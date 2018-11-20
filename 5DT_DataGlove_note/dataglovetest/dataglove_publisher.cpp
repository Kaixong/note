#include "ros/ros.h"
#include "std_msgs/String.h"
#include "dataglovetest/dataglove_data.h"//***不知道其它的方式能不能引用？
#include "fglove.h"//***
#include <stdio.h>
#include <string.h>
#include <unistd.h>  // for usleep-----*/

#include <std_msgs/Empty.h>//***這兩個可能還會用到(1)
#include <sstream>//(1)

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int count=0;

int main(int argc, char **argv)//
{  
	char    *szPort1    = NULL;//***
	char    *szPort2    = NULL;
	fdGlove *pGloveA    = NULL;
	fdGlove *pGloveB    = NULL;
	int      glovetype = FD_GLOVENONE;
	if (argc<3)	//可控制輸入參數數量
	{
		printf("\n========== Usage: callback <devicename>\n");
		printf("Example: rosrun dataglovetest dataglove /dev/usb/hiddev0 /dev/usb/hiddev1\n");//輸入
		return 0;
	}
	else
	{
		szPort1 = argv[1];
		szPort2 = argv[2];		
		//printf("%s",argv[0]);		
	}

	// Initialize glove
	printf("\nAttempting to open glove A on %s .. ", szPort1 );
	pGloveA = fdOpen(szPort1);
	if (pGloveA == NULL)
	{
		printf("failed.\n");
		printf("========== To SLOVE this problem,\n");
		printf("(1)Make sure your glove plugin this computer,check it in [$ cd /dev/usb]\n");
		printf("(2)Try commands: [$ sudo chmod 666 /dev/usb/hiddev0] & [$ sudo chmod 666 /dev/usb/hiddev1] to get enough Permissions.\n\n");
		return -1;
	}
	printf("succeeded.\n");
	printf("\nAttempting to open glove B on %s .. ", szPort2 );
	pGloveB = fdOpen(szPort2);
	
	if (pGloveB == NULL)
	{
		printf("failed.\n");
		printf("========== To SLOVE this problem,\n");
		printf("(1)Make sure your glove plugin this computer,check it in [$ cd /dev/usb]\n");
		printf("(2)Try commands: [$ sudo chmod 666 /dev/usb/hiddev0] & [$ sudo chmod 666 /dev/usb/hiddev1] to get enough Permissions.\n\n");
		return -1;
	}
	printf("succeeded.\n");
	printf("\n========== Welcome for using this glove! ==========");
	//---------------------------------------------------------------------------------------
	// Now continuously poll for sensor data

  	ros::init(argc, argv, "dataglove_publisher");    
  	ros::NodeHandle p;  
  	//ros::Subscriber dataglove_sub = p.subscribe("/mobile_base/events/bumper", 1, BumperCallback);	//設定訂閱***
  	ros::Publisher dataglove_pub = p.advertise<dataglovetest::dataglove_data>("dataglove", 1);	//設定發布***
  	ros::Rate loop_rate(10); 
	ROS_INFO("Start!");
	float gloveA_scaled[18];
	float gloveB_scaled[18];
  while (ros::ok())
  {   		
	//ros::spinOnce();//以下兩行為有間隔的(10hz)等待topic發布消息(撞牆)***
    	//loop_rate.sleep();//這兩行指令的組合不同於ros::spin()，ros::spin()是連續的***	
		dataglovetest::dataglove_data msg;
		//std::stringstream ss;

		//sleep(1);
		if(fdGetGloveHand(pGloveA)==0){
			fdGetSensorScaledAll(pGloveA, gloveA_scaled);
			fdGetSensorScaledAll(pGloveB, gloveB_scaled);
			printf("A(lefthand):%d|B(righthand):%d|\n",
			fdGetGloveHand(pGloveA),
			fdGetGloveHand(pGloveB)
		);
		}else{
			fdGetSensorScaledAll(pGloveB, gloveA_scaled);
			fdGetSensorScaledAll(pGloveA, gloveB_scaled);
			printf("A(lefthand):%d|	B(righthand):%d|\n",
			fdGetGloveHand(pGloveB),
			fdGetGloveHand(pGloveA)
		);		
		}
		printf("A:%0.2f|%0.2f|%0.2f|%0.2f|%0.2f|	B:|%0.2f|%0.2f|%0.2f|%0.2f|%0.02f\n",
			msg.LL=gloveA_scaled[FD_LITTLENEAR],
			msg.LR=gloveA_scaled[FD_RINGNEAR],
			msg.LM=gloveA_scaled[FD_MIDDLENEAR],
			msg.LP=gloveA_scaled[FD_INDEXNEAR],
			msg.LT=gloveA_scaled[FD_THUMBNEAR],
			msg.RT=gloveB_scaled[FD_THUMBNEAR],			
			msg.RP=gloveB_scaled[FD_INDEXNEAR],			
			msg.RM=gloveB_scaled[FD_MIDDLENEAR],			
			msg.RR=gloveB_scaled[FD_RINGNEAR],			
			msg.RL=gloveB_scaled[FD_LITTLENEAR]
		);				
		//printf(" >> %d\n", fdGetGesture(pGloveA));//fdGetNumGestures是顯示總共有幾種手勢可判別，通常不會變			
		usleep(50000); // sleep 1 millisecond	
		//ss << gloveA_scaled[FD_THUMBNEAR]<<"||"<<gloveB_scaled[FD_THUMBNEAR];
		dataglove_pub.publish(msg);
		printf("\nPublish: OK\n");
		ROS_INFO("Check your Left Pointfinger: %f",msg.LP);
		//sleep(1); // sleep unit: 1 second
		//usleep(50000);// sleep unit: 1 millisecond
		//i=0;
	
  }
	// Close gloves
	printf("\nClosing glove(s)......\n" );
	fdClose(pGloveA);
	printf("Glove(s) closed.\n\n");

	return 0;
	
 	//ros::spin();
  return 0;
}
