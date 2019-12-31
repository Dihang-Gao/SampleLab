#ifndef COUNTTYPEH
#define COUNTTYPEH
#pragma once

/************************************************************
*  File:       CountType.h
*  Project:    Lab 0
*  Author:     AJ Armstrong
*  Version:    1.1
*  Date:       10 Dec 2019
*  Course:     CMPE1700
*  Instructor: AJ Armstrong
*  Description: Definition of an enumeration that indicates
*               a statistic of interest for a file or line.
* *********************************************************/

typedef enum CType
{
    Lines,
    Words,
    Characters,
    Letters,
    Digits,
    Special,
    Whitespace
} CountType;


#endif // !COUNTTYPEH
