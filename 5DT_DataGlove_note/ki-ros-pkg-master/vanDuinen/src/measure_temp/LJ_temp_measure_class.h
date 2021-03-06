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

#ifndef TEMPERATURE_MEASURE_CLASS_H_
#define TEMPERATURE_MEASURE_CLASS_H_

#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>

// Messages

#include <labjack/Sensors.h>
#include <vanDuinen/temp.h>

// services

#include <labjack/GetTemperature.h>
#include <labjack/GetCurrents.h>
#include <labjack/StartPublishing.h>


class TemperatureMeasure 
{
private:
  // This will change soon
  labjack::GetTemperature labjack_temperature_;

  ros::ServiceClient labjack_temperature_client_;
  ros::Subscriber labjack_ain_sub_;
  ros::Publisher data_pub_;
  //double temp_;

  ros::Rate loop_rate_;
  //  ros::Rate publish_rate_;

  ros::Duration time_;
  ros::Time start_time_; 

  std::ofstream data_file_; // Data storange
  char* path_;

  double cal_200uA_;
  double cal_10uA_;
  
  vanDuinen::temp temp_msg_;
  double temp_[14];
  bool publishing_;
  int current_channel_;
  int starting_channel_;
  int number_of_channels_;

  ros::NodeHandle nh_;

public:

  //void LabjackMsgCallback(const boost::shared_ptr<const labjack::Sensors> &msg);

  bool init(void);
  TemperatureMeasure(int cur_n, int ch_start, int ch_num);
  ~TemperatureMeasure(void);
  void publish();
  void spin();
  bool init_loggfile(char *path);
  double get_temperature(int ain_ch, int curr_n); // Returns the temperature read from a resistance probe connected to labjack  
  double volt2temperature(double u, bool c200ua);

};

#endif
