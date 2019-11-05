#include <iostream>
#include <ctime>
#include "Time.h"
using namespace std;

/* Default Time Constructor */
Time::Time()
{
	secs = 0;
} //ends Default Time Constructor

/* Overload Time Constructor */
Time::Time()
{
	this->secs = 0;
} //ends Overload Time Constructor

/* Constructor */
Time::Time(time_t t)
{
	this->secs = t;
} //ends Constructor

/* Copy Constructor */
Time :: Time(const Time& t)
{
	(*this).secs = t.secs;
}

string Time::toString() const
{
	return ctime(&secs);
}

/* Get MMDDYYYY */
string Time::getMMDDYYYY() const
{
	struct tm* nowLocal;
	char buffer[80];
	nowLocal = localtime(&secs);
	strftime(buffer, 80, "%m%d%y", nowLocal);
	return buffer;
}

/* Get Year */
string Time::getYear() const
{
	struct tm* nowLocal;
	char buffer[80];
	nowLocal = localtime(&secs);
	strftime(buffer, 80, "%y", nowLocal);
	return buffer;
}

/* Compare Time */
int Time::compareTime(const Time& t)
{
	int difference = secs - t.secs;
	if (difference == 0)
	{
		return 0;
	}
	else if (difference > 0)
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
