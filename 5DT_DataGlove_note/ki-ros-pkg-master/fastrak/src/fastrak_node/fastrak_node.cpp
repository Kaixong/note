#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>
#include <cmath>

// messages
#include <fastrak/Pose.h>

#include "fastrak_tracker.h"

int eul2rpy(double eul[3],double &roll, double &pitch, double &yaw)
{
  /*int i;
  for(i=0;i<3;i++){
    std::cout << "eul[" << i << "]:" << eul[i]<< "\n";
    }*/
  double ca = cos(eul[0]);
  double sa = sin(eul[0]);
  double cb = cos(eul[1]);
  double sb = sin(eul[1]);
  double cg = cos(eul[2]);
  double sg = sin(eul[2]);
  double T11 = ca*cb;
  //double T12 = ca*sb*sg-sa*cg;
  //double T13 = ca*sb*cg+sa*sg;
  double T21 = sa*cb; 
  //double T22 = sa*sb*sg+ca*cg;  
  //double T23 = sa*sb*cg-ca*sg;
  double T31 = -sb;   
  double T32 = cb*sg;  
  double T33 = cb*cg;

  pitch = atan2(-T31, sqrt(T11*T11 + T21*T21));
  yaw = atan2(T21/cos(pitch), T11/cos(pitch));
  roll = atan2(T32/cos(pitch), T33/cos(pitch));
 
  /*rpy[0] = roll;
  rpy[2] = pitch;
  rpy[3] = yaw;*/
  return 1;
}


int main(int argc, char** argv)
{

  fastrak::Pose fastrak_pose_message_;
 
  ros::init(argc, argv, "fastrak_talker");
  ros::NodeHandle n;
  //ros::Publisher chatter_pub = n.advertise<fastrak::Pose >("fastrak_chatter", 100);
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("fastrak_chatter", 100);
  ros::Publisher pose_pub = n.advertise<fastrak::Pose>("fastrak", 100);
  ros::Rate loop_rate(120);
  int count = 0;

  double x,y,z,pi,ya,ro;
  
  if (argc != 2)
    {
      printf("Usage: fastrack_node USB_dev_num (ie /dev/ttyUSB4 -> fastrack_node 4) \n");
      return 1;
    }
  int dev_num = atoi(argv[1]);  
  
  tracker t(dev_num);

  /*
  printf("Setting defaults...\n");
  t.restore_system_defaults();
  printf("Done!\n\n\n");
  */

  /*
  printf("Storing settings to EEPROM...\n");
  t.store_current_to_eeprom();
  printf("Done!\n\n\n");
  */

  /*
  printf("Restarting tracker - this takes %.1f seconds\n", (float)RESTART_TIME/1000);
  t.restart_tracker();
  printf("Done!\n\n\n");
  */

  /*
  //Set and check hemisphere
  printf("Setting and checking hemisphere...\n");
  t.set_hemisphere(0,0,1.0); //This is the default anyway
  if (t.get_hemisphere(&x,&y,&z) == -1)
    printf("error1\n");
  else
    printf("Hemisphere: (%.2lf,%.2lf,%.2lf)\n", x, y, z);
  printf("Done!\n\n\n");
  */

  /*
  //Set and check units
  printf("Setting and checking units...\n");
  t.set_dist_units(DIST_UNIT_MM);
  t.set_angle_units(ANGLE_UNIT_DEG);
  printf("Using %s for XYZ and %s for angles\n", DIST_UNIT_NAME(t.get_dist_units()), ANGLE_UNIT_NAME(t.get_angle_units()));
  */

  //Interactively set up coordinate system
  /*printf("Interactively set up origin? (y/n - then enter)\n");
  ch = getchar();
  if (ch == 'y')
  {
    getchar();
    t.setup_origin(INTERACTIVE);
  }
  else
  getchar();
  
  printf("Interactively set up boresight? (y/n - then enter)\n");
  ch = getchar();
  if (ch == 'y')
  {
    getchar();
    t.setup_boresight(INTERACTIVE);
  }
  else
  getchar();
  */

  
  printf("Non-interactively setting up origins...\n");
  //Non-interactively set up coordinate system
  //This could be used if you want to use your own interface to the calibration (e.g. via a GUI)
  /*t.setup_origin(STEP_0); //Indicate start - place probe at proposed origin
  printf("Place probe at desired xyz origin, then hit enter...\n");
  getchar();
  t.setup_origin(STEP_1); //Indicate this is origin - now place probe on X axis
  printf("Place probe 20-40cm along the positive X axis, then hit enter...\n");
  getchar();
  t.setup_origin(STEP_2); //Indicate this was X - now place probe on Y axis
  printf("Place probe 20-40cm along the positive Y axis, then hit enter...\n");
  getchar();
  t.setup_origin(STEP_3); //Indicate this was Y - done!
  printf("Done!\n");*/

  t.setup_boresight(STEP_0); //Indicate start - place probe with desired orientation
  printf("Place probe at desired origin orientation, then hit enter...");
  getchar();
  t.setup_boresight(STEP_1); //Could also just use t.set_boresight_to_current();
  printf("Done!\n");
  


  //Check boresight
  /*  printf("Checking boresight...\n");
  if (t.get_boresight(&ya,&pi,&ro) == -1)
    printf("error3\n");
  else
    printf("Boresight: (%.2lf,%.2lf,%.2lf)\n", ya, pi, ro);
  */

  //double roll, pitch, yaw; 
  //std_msgs::double orientation[3];
  //double myeul[3];
  //ya = 0.0; pi = -0.0; ro = 0.0;
  //double dya =0.01;
  //double dro =0.01;
  
  while (ros::ok())
  {
    std::stringstream ss;
    //ss << "Hello there! This is message [" << count << "]";
    
    /*
    if (t.get_pose(&x,&y,&z,&ya,&pi,&ro) == -1){
      ss << "error4\n" ;
      }*/
    if (t.recive_stream(&x,&y,&z,&ya,&pi,&ro) == -1){
      ss << "error4\n" ;
      
    }

    /*else{
      sprintf("(x,y,z,yaw,pitch,roll): (%5.2lf, %5.2lf, %5.2lf, %5.2lf, %5.2lf, %5.2lf)\n", x, y, z, ya, pi, ro);
      }*/
    /*if( -0.5 > ya || ya > 0.5)
      dya = -dya;
    if( -0.5 > ro || ro > 0.5)
      dro = -dro;

      ya = ya+dya; ro = ro+dro;*/
    ss <<  ya << " " << pi << " " << ro;
      //eul2rpy(myeul, roll, pitch, yaw);
      //ss << "(yaw,pitch,roll): "  << DEG(yaw) << ", " << DEG(pitch) << ", " << DEG(roll);
      //ss << "(yaw,pitch,roll): "  << DEG(ya) << ", " << DEG(pi) << ", " << DEG(ro);
      //orientation[0]=ya;orientation[1]=pi;orientation[2]=ro;
      /*fastrak_pose_message_.ya = ya;
      fastrak_pose_message_.pi = pi;
      fastrak_pose_message_.ro = ro;*/
      //}  
    //chatter_pub.publish(fastrak_pose_message_);
    std_msgs::String msg;
    msg.data = ss.str();
    chatter_pub.publish(msg);


    fastrak::Pose pose;
    pose.x = x;
    pose.y = y;
    pose.z = z;
    pose.ya = ya;
    pose.pi = pi;
    pose.ro = ro;
    pose_pub.publish(pose);
    /*turtlesim::Velocity vel;
    vel.linear = linear;
    vel.angular = angular;
    vel_pub.publish(vel);*/


    //ROS_INFO("I published [%s]", ss.str().c_str());
    ros::spinOnce();
    loop_rate.sleep();
    ++count;
  }
}
