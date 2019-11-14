#include <iostream>
#include <ctime>
#include "Student.h"
#include "Time.h"

using namespace std;

/* Default Constructor */
Student:: Student()
{
	name = ""; //name of the student
	id = ""; //student id number
	level = ""; //level of the student - FRESHMAN, SOPHOMORE, JUNIOR, SENIOR
	status = ""; //status of the student - ENROLLED, DROPPED, ADDED
	date_of_action = 0; //date of action
} //ends Default Constructor

/* Overload Constructor */
Student :: Student(string id, string name, string level, Time date_of_action)
{
	this->name = name;
	this->id = id;
	this->level = level;
	//this->status = status;
	this->date_of_action = date_of_action;
} //ends Overload Constructor


/* Copy Constructor */
Student::Student(const Student& s)
{
	(*this).name = s.name;
	(*this).id = s.id;
	(*this).level = s.level;
	(*this).date_of_action = s.date_of_action;
} //ends Copy Constructor

/* Assignment Operator */
Student& Student :: operator=(const Student& s)
{
	(*this).name = s.name;
	(*this).id = s.id;
	(*this).level = s.level;
	(*this).date_of_action = s.date_of_action;
	return (*this);
} //ends Assignment Operator

/* Get Name */
string Student::getName() const {
	return name; //returns name of the student
} //Ends Get Name

/* Get ID */
string Student::getId() const {
	return id; //returns id of the student
} //ends Get ID

/* Get Level */
string Student::getLevel() const {
	return level; //returns level of the student
} //ends Get Level

/* Get Date of Action */
string Student::getDateOfAction() const {
	return date_of_action.toString();
} //ends Get Date of Action

/* Set Time of Action */
void Student::setTimeOfAction(Time act) {
	date_of_action = act;
} //ends Set Time of Action

/* Get Time of Action */
Time Student::getTimeOfAction() const {
	return date_of_action; //returns date of action
} //ends Get Time of Action

/* Get Status */
string Student::getStatus() const {
	return status; //returns status of the student
} //ends Get Status

/* Set Status*/
void Student::setStatus(string stat) {
	status = stat; //sets status of the student
} //ends Set Status
