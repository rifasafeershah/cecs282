#include "Time.h"
#include <iostream>
#include <ctime>
using namespace std;

Time :: Time()
{
  this -> secs = 0;
}

Time :: Time(time_t)
{
  this -> secs = t;
}

Time :: Time(const Time& t)
{
  (*this).secs = t.secs;
}

string Time :: toString() const
{
  return ctime(&secs);
}

string Time :: getMMDDYYYY() const
{
  struct tm* nowLocal;
  char buffer[80];
  nowLocal = localtime(&secs);
  strftime(buffer, 80, "%m%d%y", nowLocal);
  return buffer;
}

string Time :: getYear() const
{
  struct tm* nowLocal;
  char buffer[80];
  nowLocal = localtime(&secs);
  strftime(buffer, 80, "%y", nowLocal);
  return buffer;
}

int Time :: compareTime(const Time &t)
{
  int difference = secs - t.secs;
  if (difference == 0)
  {
    return 0;
  }
  
