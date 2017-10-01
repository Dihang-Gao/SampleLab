/************************************************************
*  File:       Util.c
*  Project:    Lab 0
*  Author:     AJ Armstrong
*  Version:    1.0
*  Date:       6 Sep 2017
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Implementation of general utility methods.
* *********************************************************/

#include "Util.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Print an error message
void PrintError(char const * const message)
{
	fprintf(stderr, ANSI_COLOR_RED "Error: " ANSI_COLOR_RESET);
	fprintf(stderr, "%s", message);
	fprintf(stderr, "\n");
	fflush(stderr);
}

void PrintErrorCode(ErrorCode ec)
{
	fprintf(stderr, ANSI_COLOR_RED "Error: " ANSI_COLOR_YELLOW);
	fprintf(stderr, "%s" ANSI_COLOR_RESET, ErrorMessage(ec));
	fprintf(stderr, "\n");
	fflush(stderr);
}

//Print the usage message for the app (expects an
//ARGUMENTS macro with list of arguments)
void PrintUsage(char const * const appname)
{
	printf(ANSI_COLOR_BLUE "Usage: " ANSI_COLOR_RESET);
	//TODO:  Ensure ARGUMENTS message macro is defined
	printf("%s %s\n", appname, ARGUMENTS);
	fflush(stdout);
}

/*********************************************************************
* Function     ExitError
* Arguments:   ErrorCode ec - enumeration defining what the error type is
*              char * message - string error message
*              char * debug - string debug information
*			   bool printUsage - whether or not to print the usage message
*
* Returns:     void
* Description: Prints formatted error messages and exits with error code.
* ******************************************************************/
void ExitError(ErrorCode ec, char const * const message,
	char const * const debug,
	char const * const appName)
{
	PrintErrorCode(ec);
	if (message && strlen(message)) PrintError(message);
	if (debug && strlen(debug))
	{
		fprintf(stderr, ANSI_COLOR_YELLOW "Debug: " ANSI_COLOR_RESET);
		fprintf(stderr, "%s", debug);
		fprintf(stderr, "\n");
		fflush(stderr);
	}
	if (appName && strlen(appName)) PrintUsage(appName);

	//Exit program with error
#ifdef DEBUG
	fflush(stdin); //Make sure there's nothing lurking in the buffer.
	printf("\nPress Enter to Exit:");
	fflush(stdout);
	fgetc(stdin);
#endif

	exit(ec);
}