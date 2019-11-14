/*
 * Name: Rifa Safeer Shah
 * CECS 282 Assignment 2
 * Last Updated 
*/

#include <iostream>
#include "Time.h"
#include <ctime>
#include <iostream>
#include <sstream>
#include <time.h>
#include <stdio.h>

using namespace std;

/* Default Constructor */
Time::Time()
{
	secs = 0;
} //ends Default Constructor

/* Overload Constructor */
Time::Time(time_t t)
{
	this->secs = t;
} //ends Overload Contructor

/* Copy Constructor */
Time :: Time(const Time& t)
{
	(*this).secs = t.secs;
} //ends Copy Constructor

/* Get MMDDYYYY */
string Time::getMMDDYYYY() const
{
	ostringstream date;
	tm* gmtm = gmtime(&secs);
	int month = gmtm->tm_mon + 1;
	int day = gmtm->tm_mday;
	int year = gmtm->tm_year + 1900;
	date << month << "/" << day << "/" << year;
	return date.str();
} //ends Get MMDDYYYY

/* Get Year */
string Time::getYear() const
{
	time_t currentTime = secs;
	struct tm* timeinfo;
	time(&currentTime);
	timeinfo = localtime(&currentTime);
	char buffer[80];
	strftime(buffer, 80, "%G", timeinfo);
	return buffer;
} //ends Get Year

/* Compare Time */
int Time::compareTime(const Time& t)
{
	if (secs - t.secs == 0)
	{
		return 0;
	}
	else if (secs - t.secs < 0)
	{
		return 1;
	}
	else
	{
		return -1; 
	}
} //ends Compare Time

/* To String */
string Time::toString() const
{
	tm* gmtm = gmtime(&secs);
	char* dateTime = asctime(gmtm);
	return dateTime;
} //ends To String
