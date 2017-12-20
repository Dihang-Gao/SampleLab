/************************************************************
*  File:       Settings.h
*  Project:    Lab 0
*  Author:     AJ Armstrong
*  Version:    1.0
*  Date:       6 Sep 2017
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
//If this is defined (0 or 1), main will pause.
#define DEBUG 1

//Use ANSI Colors?  If below is defined, yes
//Doesn't work on MS command windows. <Derisive sigh>
#define ANSI_COLORS

//ARGUMENTS macro is for my PrintUsage functionality (see util.h/c)
#undef ARGUMENTS
#define ARGUMENTS "FileName <letter> <number>\n     (Last 2 arguments optional)"

//Settings for ansi colors macro above
#ifndef ANSI_COLORS

#define ANSI_COLOR_RED     ""
#define ANSI_COLOR_GREEN   ""
#define ANSI_COLOR_YELLOW  ""
#define ANSI_COLOR_BLUE    ""
#define ANSI_COLOR_MAGENTA ""
#define ANSI_COLOR_CYAN    ""
#define ANSI_COLOR_RESET   ""

#else

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#endif // !ANSI_COLORS
#endif // !SETTINGSH
