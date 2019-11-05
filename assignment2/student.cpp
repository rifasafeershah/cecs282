#include <iostream>
#include <ctime>
#include "Student.h"
#include "Time.h"

using namespace std;

/* Default Constructor */
Student:: Student()
{
	level = "Recruit";
	id = "000000000";
	name = "Rifa Fifa";
	status = "money";
	date_of_action = 0;
}

/* Overload Constructor */
Student :: Student(string id, string name, string level, Time date_of_action)
{
	this->id = id;
	this->name = name;
	this->level = level;
	this->date_of_action = date_of_action;
}


/* Copy Constructor */
Student::Student(const Student& s)
{
	(*this).name = s.name;
	(*this).id = s.id;
	(*this).level = s.level;
	(*this).date_of_action = s.date_of_action;
}

/* Assignment Operator */
Student& Student :: operator=(const Student& s)
{
	(*this).name = s.name;
	(*this).id = s.id;
	(*this).level = s.level;
	(*this).date_of_action = s.date_of_action;
	return (*this);
}

/* Get Level */
string Student::getLevel() const {
	return level;
}

/* Get ID */
string Student::getId() const {
	return id;
}

/* Get Name */
string Student::getName() const {
	return name;
}

/* Get Date of Action */
string Student::getDateOfAction() const {
	return date_of_action.toString();
}

/* Get Time of Action */
Time Student::getTimeOfAction() const {//return date_of_action in seconds
	return date_of_action;
}

/* Get Status */
string Student::getStatus() const {
	return status;
}

void Student::setStatus(string stat) {
	status = stat;
}

void Student::setTimeOfAction(Time act) {
	date_of_action = act;
}
