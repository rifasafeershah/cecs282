#include "Student.h"
#include <iostream>
#include <ctime>
#include <time.h>


Student :: Student()//default constructor
{
	level = "Recruit";
	id = "000000000";
	name = "Rifa Fifa";
	status = "money";
	date_of_action = 0;
}
Student :: Student(string id, string name, string level, Time date_of_action)//overloaded constructor
{
	this ->id = id;
	this ->name = name;
    this ->level = level;
    this ->date_of_action = date_of_action;
}

Student :: Student(const Student& s)//copy constructor
{
  (*this).name = s.name;
  (*this).id = s.id;
  (*this).level = s.level;
  (*this).date_of_action = s.date_of_action;
}

Student& Student :: operator=(const Student& s) //assignment operator
{
  (*this).name = s.name;
  (*this).id = s.id;
  (*this).level = s.level;
  (*this).date_of_action = s.date_of_action;  
  return (*this);
}

string Student :: getLevel() const{
  return level;
}

string Student :: getId() const{
  return id;
}

string Student :: getName() const{
  return name;
}

string Student :: getDateOfAction() const{
  return date_of_action.toString();
}

Time Student:: getTimeOfAction() const{//return date_of_action in seconds
  return date_of_action;
}
string Student :: getStatus() const{
  return status;
}
void Student ::  setStatus(string stat){
  status = stat;
}
void Student :: setTimeOfAction(Time act){
  date_of_action = act;
}
