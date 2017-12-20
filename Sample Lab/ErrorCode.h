#ifndef ERRORCODEH
#define ERRORCODEH
#pragma once

/************************************************************
*  File:       ErrorCode.h
*  Project:    Lab 0
*  Author:     AJ Armstrong
*  Version:    1.0
*  Date:       28 Sep 2017
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Definition of an enumeration that indicates
*               the type of a program error. Declaration of
*               helper functions for that enumeration.
* *********************************************************/
typedef enum
{
 ecSuccess = 0,
 ecGeneralError = -1,
 ecTooFewArguments = -2,
 ecTooManyArguments = -3,
 ecUnableToOpenFile = -4,
 ecFileAccessError = -5,
 ecTargetNotFound = -6,
 ecInvalidArgument = -7
}ErrorCode;

//Convert Error Code to error message (string)
char const * const ErrorMessage(ErrorCode ec);

#endif //ERRORCODEH
