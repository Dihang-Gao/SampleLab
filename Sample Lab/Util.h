#ifndef UTILH
#define UTILH
#pragma once

/************************************************************
*  File:       Util.h
*  Project:    Lab 0
*  Author:     AJ Armstrong
*  Version:    1.0
*  Date:       6 Sep 2017
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Declaration of general utility functions.
* *********************************************************/
#include "Settings.h"
#include "ErrorCode.h"

typedef unsigned int uint;
typedef unsigned char byte;
typedef enum {false = 0,true} bool;

//Print an error message
void PrintError(char const * const message);
//Print an error code
void PrintErrorCode(ErrorCode ec);
//Print error code as well as message
void PrintErrorCodeMessage(ErrorCode ec, char const * const message);
//Print the usage message for the app (expects a
//ARGUMENTS macro with a list of arguments)
void PrintUsage(char const * const appname);
//Exit with error, optionally printing debug info,
//  usage message
void ExitError(ErrorCode ec, char const * const message,
               char const * const debug,
               char const * const appName);

#endif
