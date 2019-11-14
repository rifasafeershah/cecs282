#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <string>
#include "Instructor.h"
#include "Course.h"
#include "Student.h"
#include "Time.h"

using namespace std;

class Instructor {
	private:

		string name; //name of the instructor (first and last)
		int numOfCoursesTaught; //number of courses taught
		string status; //full-time or part-time or tenured
		Course* courses; //pointer to array of courses

	public:
		Instructor();
		Instructor(string name, string status, Course* crs, int num);
		Instructor(const Instructor& i);
		~Instructor();
		Course* getCourse() const;
		int getNumberOfCoursesTaught() const;
		string getName() const;
		string getStatus() const; //Part-time or Full-time or Tenured
		string getStudentStatus(const Student& s, const Course& c) const; //Enrolled, Added, or Dropped
		int addStudent(const Student& s, Course& c); //return -1 if a student already exists; return 0 if a student is not on the roster. Otherwise return 1
		int dropStudent(const Student& s, Course& c, Time t); //return 0 if a student is not on the roster. Otherwise, return 1.
		int findStudent(const Student& s, const Course& c); //return 0 if a student is not found. Otherwise, return 1.
		int addCourse(const Course& c); //return -1 if course already exists; return 0 if the numOfCoursesTaught reaches MAXCOURSE. Otherwise, add the course and return 1.
		int findCourse(const Course& c); //return 0 if a course is not found. Otherwise, return 1.
};
#endif
