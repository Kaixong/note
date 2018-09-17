/*--------------------------------------------------------------------------*/
// A simple console application to get glove sensor info using polling
//
// Copyright (C) 2010, 5DT <Fifth Dimension Technologies>
//
/*--------------------------------------------------------------------------*/

#include "fglove.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>  // for usleep-----*/


int main( int argc, char** argv )
{
	char    *szPort    = NULL;
	fdGlove *pGloveA    = NULL;
	int      glovetype = FD_GLOVENONE;

	// check that the arguments are correct
	if (argc!=2)	//可控制輸入參數數量
	{
		printf("\nUsage: callback <devicename>\n");
		printf("Example: sudo ./callback /dev/usb/hiddev0\n\n");
		return 0;
	}
	else
	{
		szPort = argv[1];
		printf("%s",argv[0]);		
	}

	// Initialize glove	
	printf("\nAttempting to open glove A on %s .. ", szPort );
	pGloveA = fdOpen(szPort);
	if (pGloveA == NULL)
	{
		printf("failed.\n");
		return -1;
	}
	printf("succeeded.\n");
	
	//---------------------------------------------------------------------------------------
	// Now continuously poll for sensor data
	
	float gloveA_scaled[18];
	
	for (int i=0; i<5000; i++)
	{
		sleep(3);
		fdGetSensorScaledAll(pGloveA, gloveA_scaled);
		
		printf("A:%0.1f %0.1f||%0.1f||%0.1f %0.1f||%0.1f||%0.1f %0.1f||%0.1f||%0.1f %0.1f||%0.1f||%0.1f %0.1f||%0.01f",
			gloveA_scaled[FD_THUMBNEAR],
			gloveA_scaled[FD_THUMBFAR],
			gloveA_scaled[FD_THUMBINDEX],
			gloveA_scaled[FD_INDEXNEAR],
			gloveA_scaled[FD_INDEXFAR],
			gloveA_scaled[FD_INDEXMIDDLE],
			gloveA_scaled[FD_MIDDLENEAR],
			gloveA_scaled[FD_MIDDLEFAR],
			gloveA_scaled[FD_MIDDLERING],
			gloveA_scaled[FD_RINGNEAR],
			gloveA_scaled[FD_RINGFAR],
			gloveA_scaled[FD_RINGLITTLE],
			gloveA_scaled[FD_LITTLENEAR],
			gloveA_scaled[FD_LITTLEFAR],
			gloveA_scaled[FD_ROLL]);
				
		printf(" >> %d\n", fdGetNumGestures(pGloveA));
			
		//sleep(3); // sleep 1 millisecond
i=0;
	}

	// Close gloves
	printf("\nClosing glove(s)......\n" );
	fdClose(pGloveA);
	printf("Glove(s) closed.\n\n");

	return 0;
}

