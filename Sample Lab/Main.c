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
 *  All but first argument are optional. See file CountType.h
 *  for different types of information generated.
 * *********************************************************/

#include "Settings.h"
#include "Util.h" //Utility functions
#include "ErrorCode.h" //Definition of error codes ('ec' prefix)
#include <stdio.h>
#include <errno.h> //Support for POSIX error messages. Defines 'errno'

/*********************************************************************
 * Function: main
 * Arguments:int argc - number of arguments (1 implicit arg always present)
 *           char** argv - Array of strings containing com. line arguments
 * API:      arg 1 - Filename of text file to open an analyze
 *           arg 2 - (Optional) - either (a) line number (line information) or
 *                    (b) a character indicating the specific data desired
 *           arg 3 - (Optional) - line number if 2b selected above.
 * Returns:  int - Program success status for POSIX OS
 * Description: Parses command-line arguments and passes output to
 *              console. Main should trap all API errors, allowing
 *              error handling to be primarily handled here.
 * ******************************************************************/

int main(int argc, char** argv)
{
    char debugbuffer[255] = ""; //Memory area for storing debug messages
    bool doneReading = false; //Have I read all the lines in the file?
    FILE * fi = NULL; //Pointer to text file
    char * lineptr = NULL; //Pointer to dynamically allocated string buffer with line

    //Initial sanity check on number of arguments
    if (argc < 2) //No explicit args
    {
        //Create debug message only if expecting to use it.
        if (DEBUG) snprintf(debugbuffer, sizeof(debugbuffer), "Argument count: %d", argc);

        ExitError(ecTooFewArguments, "Expected a filename.",
                  DEBUG ? debugbuffer : NULL,
                  argv[0]);
    }

    if (argc > 4) //Too many explicit args
    {
        //Create debug message only if expecting to use it.
        if (DEBUG) snprintf(debugbuffer, sizeof(debugbuffer), "Argument count: %d", argc);

        ExitError(ecTooManyArguments, "Too many arguments. Did you forget quotation marks?",
                  DEBUG ? debugbuffer : NULL,
                  argv[0]);
    }

    //✓ TODO: We could add some logic here to make sure that the
    //  arguments make sense before analyzing the file to prevent
    //  analyzing it and then throwing an argument error.

    //  If we get here, we potentially have a valid request
    //  First, attempt to open the file.

    fi = fopen(argv[1],"r");
    if(fi == NULL) //Error opening file
    {
        if(DEBUG) snprintf(debugbuffer,sizeof(debugbuffer),
                           "I/O Error: errno %d attempting to open %s for reading.",
                           errno, argv[1]);

        ExitError(ecFileAccessError, "Unable to open file for reading.",
                  DEBUG ? debugbuffer:NULL, argv[0]);
    }

    //Ok.  I have an open file.  Start parsing, line by line.
    do {
	
    } while (!doneReading);

    //Pause to avoid console closing in debug mode.
    if (DEBUG)  //If DEBUG macro not 0
    {
        fflush(stdin); //Make sure there's nothing lurking in the buffer.
        printf("\nPress Enter to Exit:");
        fflush(stdout);
        fgetc(stdin);
    }
    // Clean up toys
    return ecSuccess; //If we got here, all went well
}
