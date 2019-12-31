/************************************************************
*  File:       ErrorCode.c
*  Project:    Lab 0
*  Author:     AJ Armstrong
*  Version:    1.1
*  Date:       10 Dec 2019
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Implementation of support functions for error codes.
*  contents.  See "Line.h" for declarations.
* *********************************************************/

#include "ErrorCode.h"

/*********************************************************************
* Function:    ErrorMessage
* Arguments:   ErrorCode ec - enumeration defining what the error type is
* Returns:     void
* Description: Returns string describing error.
* ******************************************************************/
char const * const ErrorMessage(ErrorCode ec)
{
    switch (ec)
    {
    case ecSuccess: return "Success";
    case ecGeneralError: return "General Error";
    case ecTooFewArguments: return "Too Few Arguments";
    case ecTooManyArguments: return "Too Many Arguments";
    case ecUnableToOpenFile: return "Unable to Open File";
    case ecFileAccessError: return "File Access Error";
    case ecTargetNotFound: return "Target Not Found";
    case ecInvalidArgument: return "Invalid Argument";
    default: return "Unknown Error";
    }
}
