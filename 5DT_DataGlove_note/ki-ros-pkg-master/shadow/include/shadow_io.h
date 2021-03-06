/*********************************************************************
 *
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2010, Alexander Skoglund, KI
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
 *   * Neither the name of the Robert Bosch nor the names of its
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

#ifndef SHADOW_IO_H
#define SHADOW_IO_H

//#include "amtec_base.h"
#include "shadow_base.h"

#ifdef __cplusplus
extern "C" {
#endif

  void shadowDeviceSetParams(shadow_spcu_device_p dev);
  void shadowDeviceSetBaudrate(shadow_spcu_device_p dev, int brate);
  int shadowDeviceConnectPort(shadow_spcu_device_p dev);
  void shadowDeviceClosePort(shadow_spcu_device_p dev);
  int shadowSendCommandEcho(int fd, unsigned char *cmd, int len);
  int shadowSendCommand(int fd, unsigned char *cmd, int len);
  int shadowGetAnswer(int fd, unsigned char *buf,int len, int cs_flag);

  int shadowSendCommandEchoAscii(int fd, unsigned char *cmd, int len);
 
  //  int shadowGetAnswer(shadow_spcu_device_p dev, unsigned char *cmd,unsigned char *buf );
  //int amtecSendCommand(amtec_powercube_device_p dev, int id, unsigned char *cmd, int len);
  //int amtecGetAnswer(amtec_powercube_device_p dev, unsigned char *cmd, int *len);

#ifdef __cplusplus
}
#endif

#endif
