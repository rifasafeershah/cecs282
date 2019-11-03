#include "Course.h"
#include <iostream>
using namespace std;
extern int const CAPACITY = 35;

//defailt constructor
Course :: Course(){
  numOfEnrolled = 0;
  courseNumber = "";//four-digit integer
  courseName = "";//e.g. CECS282 
  semester = "";// Fall, Winter,Spring, SummerTime 
  last_date_to_enroll = 0;//time in secs    
  students = new Student[CAPACITY]; //pointer to array of students
}
//Overload constructor
Course :: Course(string num, string name, string sem, Time last_date, Student* stdts, int numOfEnroll){
  this -> courseNumber = num;
  this -> courseName = name;
  this -> semester = sem;
  this -> last_date_to_enroll = last_date;
  this -> numOfEnrolled = numOfEnroll;
  setRoster(stdts);
}

//copy contructor
Course :: Course(const Course& c){
  (*this).courseNumber = c.courseNumber;
  (*this).courseName = c.courseName;
  (*this).semester = c.semester;
  (*this).last_date_to_enroll = c.last_date_to_enroll;
  (*this).numOfEnrolled = c.numOfEnrolled;

  for(int i = 0; i < numOfEnrolled; i++){
    students[i] = c.students[i];
  }
}
//assignment operator
Course& Course :: operator=(const Course& c){
  (*this).courseNumber = c.courseNumber;
  (*this).courseName = c.courseName;
  (*this).semester = c.semester;
  (*this).last_date_to_enroll = c.last_date_to_enroll;
  (*this).numOfEnrolled = c.numOfEnrolled;

  for(int i = 0; i < numOfEnrolled; i++){
    students[i] = c.students[i];
  }
  return (*this);
}
//destructor
Course :: ~Course(){
  delete [] students;
}

Student* Course :: getStudent() const{
  return students;
}

string Course :: getCourseNumber() const{
  return courseNumber;
}

string Course :: getCourseName() const{
  return courseName;
} 
string Course :: getSemester() const{
  return semester;
} 
string Course :: getYear() const{ //return the year of the semester (assume to be the year of the last date to enroll)   
//not finished
} 
int Course :: getNumberOfEnrollment() const{
  return numOfEnrolled;
}
string Course ::  getLastDateToEnroll() const{// return as Www Mmm dd hh:mm:ss yyyy 
  return last_date_to_enroll.toString();
}

Time Course :: getTimeLastDateToEnroll() const{// return last_date_to_enroll in secondsvoid 
  return last_date_to_enroll;
}

void Course :: setNumberOfEnrollment(int ne){
  numOfEnrolled = ne;
} 
void Course :: setRoster(Student* stdts){
  for(int i = 0; i < numOfEnrolled; i++){
    students[i] = stdts[i];
  }
}
