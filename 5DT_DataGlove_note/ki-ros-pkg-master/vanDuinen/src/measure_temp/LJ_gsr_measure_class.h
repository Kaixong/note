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

#ifndef GSR_MEASURE_CLASS_H_
#define GSR_MEASURE_CLASS_H_

#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <iomanip>

// Messages
#include <labjack/Sensors.h>
#include <vanDuinen/gsr.h>

// services

#include <labjack/GetAIN.h>
#include <labjack/GetCurrents.h>
#include <labjack/StartPublishing.h>


class SkinConductanceMeasure 
{
private:
  // This will change soon
  //labjack::GetTemperature labjack_temperature_;

  //ros::ServiceClient labjack_temperature_client_;
  ros::ServiceClient labjack_publishing_client_;
  //ros::ServiceClient labjack_ain_client_;
  ros::Subscriber labjack_ain_sub_;
  labjack::StartPublishing pub_msg_;
  ros::Publisher data_pub_;
  //double temp_;

  ros::Rate loop_rate_;


  ros::Duration time_;
  ros::Time start_time_; 

  std::ofstream data_file_; // Data storange
  char* path_;

  double cal_200uA_;
  double cal_10uA_;
  double resistance_ref_;

  vanDuinen::gsr gsr_msg_;
  double gsr_[14];

public:
  
  ros::NodeHandle nh_;

  SkinConductanceMeasure(void);
  ~SkinConductanceMeasure(void);
  void publish();
  bool init_loggfile(char *path);
  //double get_temperature(int ain_ch, int curr_n); // Returns the temperature read from a resistance probe connected to labjack

};

#endif
