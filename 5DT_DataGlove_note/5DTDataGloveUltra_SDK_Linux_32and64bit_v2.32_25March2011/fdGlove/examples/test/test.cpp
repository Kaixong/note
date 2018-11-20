/*--------------------------------------------------------------------------*/
// A simple console application to get glove sensor info using callbacks
//
// Copyright (C) 2010, 5DT <Fifth Dimension Technologies>
//
/*--------------------------------------------------------------------------*/

#include "fglove.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>  // for usleep

int iNumCallbackCalls = 0;

void wait()
{
	usleep(1);
	printf(" >> waiting for player...\n");	
	sleep(1);
}

// this function will be registered as our callback function in the glove driver
void call_back(void* param)
{
   iNumCallbackCalls++;
   
   float gloveA_scaled[18];
   float gloveB_scaled[18];
   
   //printf("A:%0.3f %0.3f||%0.3f||%0.3f %0.3f||%0.3f||%0.3f %0.3f||%0.3f||%0.3f %0.3f||%0.3f||%0.3f %0.3f",
		//gloveA_scaled[FD_THUMBNEAR],
		//gloveA_scaled[FD_THUMBFAR],
		//gloveA_scaled[FD_THUMBINDEX],
		//gloveA_scaled[FD_INDEXNEAR],
		//gloveA_scaled[FD_INDEXFAR],
		//gloveA_scaled[FD_INDEXMIDDLE],
		//gloveA_scaled[FD_MIDDLENEAR],
		//gloveA_scaled[FD_MIDDLEFAR],
		//gloveA_scaled[FD_MIDDLERING],
		//gloveA_scaled[FD_RINGNEAR],
		//gloveA_scaled[FD_RINGFAR],
		//gloveA_scaled[FD_RINGLITTLE],
		//gloveA_scaled[FD_LITTLENEAR],
		//gloveA_scaled[FD_LITTLEFAR]);
				
	
if(fdGetGesture(static_cast<fdGlove*>(param))==0)
{
	if(gloveA_scaled[FD_THUMBNEAR]>0.3)
	{
		usleep(1);
		printf(" >> stone\n");	
		sleep(1);
	}else
	wait();
}
else if(fdGetGesture(static_cast<fdGlove*>(param))==15)
{
	if(gloveA_scaled[FD_THUMBNEAR]<0.5)
	{
		usleep(1);
		printf(" >> paper\n");	
		sleep(1);
	}else
	wait();
}
else if(fdGetGesture(static_cast<fdGlove*>(param))==3)
{
	if(gloveA_scaled[FD_THUMBNEAR]>0.5)
	{
		usleep(1);
		printf(" >> scissors\n");	
		sleep(1);
	}else
	wait();
}else{
	wait();
	}
}



int main( int argc, char** argv )
{
	char    *szPort1    = NULL;
	char    *szPort2    = NULL;
	fdGlove *pGloveA    = NULL;
	fdGlove *pGloveB    = NULL;
	int      glovetype = FD_GLOVENONE;

	// check that the arguments are correct
	if (argc<3)
	{
		printf("\nUsage: callback <devicename>\n");
		printf("Example: sudo ./callback /dev/usb/hiddev0 /dev/usb/hiddev1\n\n");
		return 0;
	}
	else
	{
		szPort1 = argv[1];
		szPort2 = argv[2];
	}

	// Initialize glove
	printf("\nAttempting to open glove A on %s .. ", szPort1 );
	
	pGloveA = fdOpen(szPort1);
	if (pGloveA == NULL)
	{
		printf("failed.\n");
		return -1;
	}
	printf("succeeded.\n");
	printf("\nAttempting to open glove B on %s .. ", szPort2 );
	pGloveB = fdOpen(szPort2);
	
	if (pGloveB == NULL)
	{
		printf("failed.\n");
		return -1;
	}
	printf("succeeded.\n");
	
	// Register callback function call_back() in glove driver pGloveA, and pass
    	//  pGloveA as a void pointer to the callback function when it is called
	//printf(" >> %d\n", fdGetGloveHand(pGloveA));
	//printf(" >> %d\n", fdGetGloveHand(pGloveB));
	//fdSetCallback(pGloveA, reinterpret_cast<void*>(&(call_back)), static_cast<void*>(pGloveA));
	float gloveA_scaled[18];
	float gloveB_scaled[18];
	while(1)
	{
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
			gloveA_scaled[FD_LITTLENEAR],
			gloveA_scaled[FD_RINGNEAR],
			gloveA_scaled[FD_MIDDLENEAR],
			gloveA_scaled[FD_INDEXNEAR],
			gloveA_scaled[FD_THUMBNEAR],
			gloveB_scaled[FD_THUMBNEAR],			
			gloveB_scaled[FD_INDEXNEAR],			
			gloveB_scaled[FD_MIDDLENEAR],			
			gloveB_scaled[FD_RINGNEAR],			
			gloveB_scaled[FD_LITTLENEAR]
		);

				
		//printf(" >> %d\n", fdGetGesture(pGloveA));//fdGetNumGestures是顯示總共有幾種手勢可判別，通常不會變
			
		usleep(500); // sleep 1 millisecond
	}

	// print the number of calls made to the callback function
	printf("Number of callback calls: %i\n", iNumCallbackCalls);

	// Close gloves
	printf("\nClosing glove(s)...\n" );
	fdClose(pGloveA);
	printf("Glove(s) closed.\n\n");

	return 0;
}
/*--------------------------------------------------------------------------*/
