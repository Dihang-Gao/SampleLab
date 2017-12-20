/************************************************************
 *  File:       Line.c
 *  Project:    Lab 0
 *  Author:     AJ Armstrong
 *  Version:    1.0
 *  Date:       29 Sep 2017
 *  Course:     CMPE1700
 *  Instructor: AJ Armstrong
 *  Description: Implementation of methods for managing a
 *  structure containing statistical data about text file
 *  contents.  See "Line.h" for declarations.
 * *********************************************************/

#include "Line.h"
#include <ctype.h> //functions for handling chars
#include <string.h> //for strtok

/*********************************************************************
 * Function:    LoadLine
 * Arguments:   char * szline - pointer to char array (string)
 *                              containing line to document
 * Returns:     Line - fully populated Line struct.
 * Description: Calculates summary data for a given line.
 * ******************************************************************/
Line LoadLine(char * szLine)
{
    //Variable I will be storing values in
    Line retval = { 0,0,0,0,0,0 };
    char * curr = szLine; //Pointer to current word

    //Get word count using strtok
    char delim[] = ""; //Word delimiters

    return retval;
}
