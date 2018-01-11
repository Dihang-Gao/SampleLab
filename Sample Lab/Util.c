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

/*********************************************************************
 * Function     PrintError
 * Arguments:   char * message - string error message
 *
 * Returns:     void
 * Description: Prints formatted error message from a string.
 * ******************************************************************/
void PrintError(char const * const message)
{
    fprintf(stderr, ANSI_COLOR_RED "Error: " ANSI_COLOR_RESET);
    fprintf(stderr, "%s", message);
    fprintf(stderr, "\n");
    fflush(stderr);
}

/*********************************************************************
 * Function     PrintErrorCode
 * Arguments:   ErrorCode ec - Enumerated error code (see ErrorCode.h)
 *
 * Returns:     void
 * Description: Prints formatted error message from an error code
 * ******************************************************************/
void PrintErrorCode(ErrorCode ec)
{
    fprintf(stderr, ANSI_COLOR_RED "Error: " ANSI_COLOR_YELLOW);
    fprintf(stderr, "%s" ANSI_COLOR_RESET, ErrorMessage(ec));
    fprintf(stderr, "\n");
    fflush(stderr);
}

/*********************************************************************
 * Function     PrintErrorCodeMessage
 * Arguments:   ErrorCode ec - Enumerated error code (see ErrorCode.h)
 *              char * message - String error message
 *
 * Returns:     void
 * Description: Prints formatted error message from an error code in
 *              addition to a provided string message.
 * ******************************************************************/
void PrintErrorCodeMessage(ErrorCode ec, char const * const message)
{
    fprintf(stderr, ANSI_COLOR_RED "Error: " ANSI_COLOR_YELLOW);
    fprintf(stderr, "%s" ANSI_COLOR_RESET, ErrorMessage(ec));
    if(message && strlen(message) > 0)
        fprintf(stderr, " - %s", message);
    fprintf(stderr, "\n");
    fflush(stderr);
}

/*********************************************************************
 * Function     PrintUsage
 * Arguments:   char * appname - Name of the application to use
 *
 * Returns:     void
 * Description: Prints formatted usage message for a provide application
 *              name.  Depends on an ARGUMENTS macro being set with the
 *              list of arguments to the application and their description.
 *              (See settings.h).
 * ******************************************************************/
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
 *              bool printUsage - whether or not to print the usage message
 *
 * Returns:     void
 * Description: Prints formatted error messages and exits with error code.
 * ******************************************************************/
void ExitError(ErrorCode ec, char const * const message,
               char const * const debug,
               char const * const appName)
{
    //Check that exists before using
    if (message && strlen(message)) PrintErrorCodeMessage(ec,message);
    else PrintErrorCode(ec);
    if (debug && strlen(debug)) //Ditto.  Ansi colors depend on macro in Settings.h
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
    //Exit program with error code. (Does not return from this fctn)
    exit(ec);
}
