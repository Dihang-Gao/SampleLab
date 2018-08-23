#ifndef LINEH
#define LINEH
#pragma once

/************************************************************
*  File:       Line.h
*  Project:    Lab 0
*  Author:     AJ Armstrong
*  Version:    1.0
*  Date:       15 Oct 2014
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Implementation of a structure to store the
*  statistical data for a single line of a text file.  Header
*  for prototypes of utility functions for managing this struct
* *********************************************************/

typedef unsigned int uint;

typedef struct
{
    uint wordCount; //Number of words
    uint charCount; //Number of characters
    uint alphaCount; //Number of letters
    uint digitCount; //Number of digits
    uint specCount; //Number of other types
    uint whiteCount; //Number of whitespace chars
} Line;

//Calculate statistics for a given line
Line LoadLine(char * szLine);



#endif
