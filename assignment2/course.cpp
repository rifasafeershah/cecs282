#include <iostream>
#include "Course.h"
#include "Time.h"
#include "Student.h"

using namespace std;

extern int const CAPACITY; //set maximum capacity of enrollment in a course

/* Default Constructor */
Course::Course() {
	this->courseName = ""; //name of the course (CECS282)
	this->courseNumber = ""; //four-digit course number (2856)
	this->semester = ""; //the semester of the course - FALL, WINTER, SPRING, SUMMER (FALL)
	this->last_date_to_enroll = 0; //the time of last date to enroll in seconds
	this->numOfEnrolled = 0; //number of students enrolled
	this->students = new Student[CAPACITY]; //pointer that points to array of students
} //ends Default Constructor

/* Overload Constructor */
Course::Course(string name, string num, string sem, Time last_date, Student* stdts, int numOfEnroll) {
	this->courseName = name; //name of the course
	this->courseNumber = num; //number of the course
	this->semester = sem; //semester of the course
	this->last_date_to_enroll = last_date; //last date to enroll into the course
	this->numOfEnrolled = numOfEnroll; //number of students enrolled
	setRoster(stdts); //
} //ends Overload Constructor

/* Copy Constructor */
Course::Course(const Course& c) {
	(*this).courseName = c.courseName;
	(*this).courseNumber = c.courseNumber; 
	(*this).semester = c.semester;
	(*this).last_date_to_enroll = c.last_date_to_enroll;
	(*this).numOfEnrolled = c.numOfEnrolled;
	for (int i = 0; i < numOfEnrolled; i++) {
		students[i] = c.students[i];
	}
} //ends Copy Constructor

/* Assignment Operator */
Course& Course :: operator=(const Course& c) {
	(*this).courseNumber = c.courseNumber;
	(*this).courseName = c.courseName;
	(*this).semester = c.semester;
	(*this).last_date_to_enroll = c.last_date_to_enroll;
	(*this).numOfEnrolled = c.numOfEnrolled;
	for (int i = 0; i < numOfEnrolled; i++) {
		students[i] = c.students[i];
	}
	return (*this);
} //ends Assignment Operator

/* Destructor */
Course :: ~Course() {
	delete[] students;
} //ends Destructor


/* Get Student */
Student* Course::getStudent() const {
	return students;
} //ends Get Student


/* Get Course Number */
string Course::getCourseNumber() const {
	return courseNumber;
} //ends Get Course Number


/* Get Course Name */
string Course::getCourseName() const {
	return courseName;
} //ends Get Course Name

/* Get Semester */
string Course::getSemester() const {
	return semester;
} //ends Get Semester

/* Get Year */
string Course::getYear() const { //return the year of the semester (assume to be the year of the last date to enroll)
	return last_date_to_enroll.getYear();
} //ends Get Year

/* Get Number of Enrollment */
int Course::getNumberOfEnrollment() const {
	return numOfEnrolled;
} //ends Get Number of Enrollment

/* Get Last Date to Enroll */
string Course::getLastDateToEnroll() const {// return as Www Mmm dd hh:mm:ss yyyy 
	return last_date_to_enroll.toString();
} //ends Last Date to Enroll

/* Get Time Last Date to Enroll */
Time Course::getTimeLastDateToEnroll() const {// return last_date_to_enroll in secondsvoid 
	return last_date_to_enroll;
} //ends Get Time Last Date to Enroll

/* Set Number of Enrollment */
void Course::setNumberOfEnrollment(int ne) {
	numOfEnrolled = ne;
} //ends Set Number of Enrollment

/* Set Roster */
void Course::setRoster(Student* stdts) {
	for (int i = 0; i < numOfEnrolled; i++) {
		students[i] = stdts[i];
	}
} //ends Set Roster
