/************************************************************
*  File:       Main.c
*  Project:    Lab 0
*  Author:     AJ Armstrong
*  Version:    1.0
*  Date:       29 Sep 2017
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Main implementation file for command-line
*  program to generate statistics on a text file. Accepts
*  the following arguments:  (1)  Filename to process,
*  (2a) Line to generate data for, or (2b) information of
*  interest for file, (3) line number for 2b information.
*  All but first argument are required. See file CountType.h
*  for different types of information generated.
* *********************************************************/

#include "Settings.h"
#include "Util.h" //Utility functions
#include "ErrorCode.h" //Definition of error codes ('ec' prefix)
#include <stdio.h>

/*********************************************************************
* Function:	main
* Arguments:int argc - number of arguments (1 implicit arg always present)   
			char** argv - Array of strings containing com. line arguments
* Returns:	int - Program success status for POSIX os
* Description: Parses command-line arguments and passes output to
*              console.
* ******************************************************************/

int main(int argc, char** argv)
{
	char debugbuffer[255];
	//Initial sanity check on number of arguments
	
	if (argc < 2)
	{
		if (DEBUG) snprintf(debugbuffer, sizeof(debugbuffer), "Argument count: %d", argc);

		ExitError(ecTooFewArguments, "Expected a filename.",
			DEBUG ? debugbuffer : NULL,
			argv[0]);
	}
#ifdef DEBUG
	fflush(stdin); //Make sure there's nothing lurking in the buffer.
				   //printf("-------------------------------------------------------\n");
				   //printf("If you got here, your program meets expectations.  Yay!\n");
				   //printf("-------------------------------------------------------\n");
	printf("             Press Enter to Exit:");
	fgetc(stdin);
#endif

	return ecSuccess; //If we got here, all went well
}