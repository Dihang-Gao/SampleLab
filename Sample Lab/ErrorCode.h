#ifndef ERRORCODEH
#define ERRORCODEH
#pragma once

/************************************************************
*  File:       ErrorCode.h
*  Project:    Lab 0
*  Author:     AJ Armstrong
*  Version:    1.1
*  Date:       10 Dec 2019
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Definition of an enumeration that indicates
*               the type of a program error. Declaration of
*               helper functions for that enumeration.
* *********************************************************/

// ✐ NOTE:AJA:20191229: Use of negative error codes means that most shell
//         environments will interpret this as a large positive
//         rather than negative return value (because 2's complement).
//         The author (aja) doesn't mind this.  You might. Easy enough
//         to change here by modifying the values below (other than
//         ecSuccess, which of course should be bound to 0).

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
///(see ErrorCode.c for string contents.)
//☠ TODO: Shift string message declarations from .c to
//        this file to ease maintenance.
char const * const ErrorMessage(ErrorCode ec);

#endif //ERRORCODEH
