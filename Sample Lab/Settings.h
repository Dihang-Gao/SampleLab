/************************************************************
*  File:       Settings.h
*  Project:    Lab 0
*  Author:     AJ Armstrong
*  Version:    1.1
*  Date:       10 Sep 2019
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Definitions and macros for compile time
*               settings.  Settings.h should be included
*               before other headers as it may affect them.
* *********************************************************/
#ifndef SETTINGSH
#define SETTINGSH
#pragma once

//Debug macro.  0 or 1.  If 1, additional
//debugging features will be enabled at compile-time.
#define DEBUG 1

//Force our debug macro high (as above) if environment is debug
// This should work when running in debug on VS.
#ifdef _DEBUG
#define DEBUG 1
#endif //_DEBUG

//Use ANSI Colors?  If below is defined, yes
#define ANSI_COLOURS
//Doesn't work on MS command windows. <Derisive sigh>
//Unset the colours macro
#ifdef _WIN32
#undef ANSI_COLOURS
#endif

//ARGUMENTS macro is for my PrintUsage functionality (see util.h/c)
#undef ARGUMENTS
#define ARGUMENTS "FileName <letter> <number>\n"\
                  "(Last 2 arguments optional)"

//Settings for ansi colors macro above
#ifndef ANSI_COLOURS

#define ANSI_COLOUR_RED     ""
#define ANSI_COLOUR_GREEN   ""
#define ANSI_COLOUR_YELLOW  ""
#define ANSI_COLOUR_BLUE    ""
#define ANSI_COLOUR_MAGENTA ""
#define ANSI_COLOUR_CYAN    ""
#define ANSI_COLOUR_RESET   ""

#else //ANSI_COLOURS

#define ANSI_COLOUR_RED     "\x1b[31m"
#define ANSI_COLOUR_GREEN   "\x1b[32m"
#define ANSI_COLOUR_YELLOW  "\x1b[33m"
#define ANSI_COLOUR_BLUE    "\x1b[34m"
#define ANSI_COLOUR_MAGENTA "\x1b[35m"
#define ANSI_COLOUR_CYAN    "\x1b[36m"
#define ANSI_COLOUR_RESET   "\x1b[0m"

#endif // !ANSI_COLOURS
#endif // !SETTINGSH
