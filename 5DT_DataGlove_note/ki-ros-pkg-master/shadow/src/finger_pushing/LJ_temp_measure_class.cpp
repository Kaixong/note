/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2011, Alexander Skoglund, Karolinska Institute
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Karolinska Institute nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 *********************************************************************/

#include <ros/ros.h>
#include <boost/thread/mutex.hpp>

// services

#include <shadow/ShadowSensors.h>

 
#include "LJ_temp_measure_class.h"


TemperatureMeasure::TemperatureMeasure(void):loop_rate_(100)
{
  std::string the_path;
  ROS_INFO("Creating a temperature node");

  start_time_ = ros::Time::now();
  labjack_temperature_client_ = nh_.serviceClient<shadow::LJGetTemperature>("/labjack/temperature");
  
  // set path for data storage
  //std::string full_topic = prefix_ + "/path_to_spcu";
  /*std::string topic = "/temperature/path_to_data";
  if (nh_.getParam(topic, the_path))
    {
      ROS_INFO("Path to for data logging is: %s", the_path.c_str());
      strcpy( path_, the_path.c_str() );
    }
  else
    {
      ROS_ERROR("Unable to determine path for data logging, full_topic=%s", topic.c_str());
      return;
    }
  */

}

TemperatureMeasure::~TemperatureMeasure(void)
{
  
  // Close loggfile
  data_file_.close();
}

bool TemperatureMeasure::init_loggfile(char* path)
{

  // Open data file for printing
  time_t t = time(0);
  struct tm* lt = localtime(&t);
  char time_str[256];
  sprintf(time_str, "%s/templog_%04d%02d%02d_%02d%02d%02d.log",path,
          lt->tm_year + 1900, lt->tm_mon + 1, lt->tm_mday,
          lt->tm_hour, lt->tm_min, lt->tm_sec);
 
  data_file_.open(time_str);

  return true;
}


double TemperatureMeasure::get_temperature(int ain_ch, int curr_n)
{
  double t;
  // Resistance voltage conversion table from 
  // http://www.advindsys.com/ApNotes/YSI400SeriesProbesRvsT.htm

  double resistance[35] = {4273, 4074, 3886, 3708, 3539, 3378, 3226, 
			   3081, 2944, 2814, 2690, 2572, 2460, 2354, 
			   2252, 2156, 2064, 1977, 1894, 1815, 1739,
			   1667, 1599, 1533, 1471, 1412, 1355, 1301,
			   1249, 1200, 1152, 1107, 1064, 1023, 983.8 };
  double temp[35] = {11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,
		     28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45};
  int i=0;

  // Call the service get data 

  labjack_temperature_.request.ain_number = ain_ch;     // Temperature sensor is on channel AIN3
  labjack_temperature_.request.current_number = curr_n; // Temperature sensor supplied with 200 uA

  if (!labjack_temperature_client_.call(labjack_temperature_))
    ROS_ERROR("Failed to call labjack temperature service");
  double temp_res = labjack_temperature_.response.temp_res;
  time_ = labjack_temperature_.response.header.stamp - start_time_;
  
  if( temp_res > 42733 )
    {
      ROS_WARN("Temp too low! Below 11 deg");
      return 0;
    }
  if( temp_res < 1023 )
    {
      ROS_WARN("Temp too high! Above 45 deg");
      return 0;
    }

  while(temp_res < resistance[i])
    i++;
 
  // Picse wise linear approximation:
  temp_ =((temp_res-resistance[i])*(temp[i+1]-temp[i])/(resistance[i+1]-resistance[i]))+temp[i];

  data_file_ << time_.toSec() << "\t" << temp_ << std::endl;

  ROS_INFO("Time %f temp %lf",time_.toSec(),temp_);

  return temp_;
  
}

