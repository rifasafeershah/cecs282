#include <iostream>
#include "Instructor.h"
#include "Course.h"

using namespace std;

extern int const MAXCOURSE;
extern int const CAPACITY;

/* Default Constructor */
Instructor::Instructor()
{
	this->name = "EMPTY"; //name of the instructor
	this->numOfCoursesTaught = 0; //number of courses taught
	this->status = "EMPTY"; //status of the instructor
	this->courses = new Course[MAXCOURSE]; //pointer pointing to the array of courses
}

/* Overload Constructor */
Instructor::Instructor(string name, string status, Course* crs, int num)
{
	this->name = name;
	this->status = status;
	this->courses = courses;
	this->numOfCoursesTaught = num; //number of courses taught
	for (int i = 0; i < numOfCoursesTaught; i++)
	{
		courses[i] = crs[i];
	}
} //ends Overload Constructor

/* Copy Constructor */
Instructor::Instructor(const Instructor& i)
{
	(*this).name = i.name; //name of the instructor
	(*this).status = i.status; //status of the instructor
	(*this).courses = i.courses; //name of the course
	(*this).numOfCoursesTaught = i.numOfCoursesTaught; //number of courses taught
	for (int x = 0; x < numOfCoursesTaught; x++)
	{
		courses[x] = i.courses[x];
	}
} //ends Copy Constructor

/* Destrcutor */
Instructor :: ~Instructor()
{
	delete[] courses;
}

/* Get Name */
string Instructor::getName() const
{
	return name; //returns name of the instructor
} //ends Name

/* Get Course */
Course* Instructor::getCourse() const
{
	return courses; //returns name of the course
} //ends Get Course

/* Get Number of Courses Taught */
int Instructor::getNumberOfCoursesTaught() const
{
	return numOfCoursesTaught; //returns number of courses taught
} //ends Get Number of Courses Taught

/* Get Status */
string Instructor::getStatus() const
{
	return status; //returns status of the instructor
} //ends Get Status

/* Get Student Status */
string Instructor::getStudentStatus(const Student& s, const Course& c) const
{

}

/* Add Student */
int Instructor::addStudent(const Student& s, Course& c)
{
	int course = findCourse(c);
	if (course == 0)
	{
		return -1;
	}
	else
	{
		int student = findStudent(s, c);
		if (student == 0)
		{
			int cap = c.getNumberOfEnrollment();
			if (cap >= CAPACITY)
			{
				Student* ptr = new Student[cap + 1];
				Student* temp = c.getStudent();
				for (int i = 0; i < cap; i++)
				{
					ptr[i] = temp[i];
				}
				ptr[cap] = s;
				ptr[cap].setStatus("Added");
				c.setNumberOfEnrollment(cap + 1);

				if (s.getTimeOfAction().compareTime(c.getTimeLastDateToEnroll()) == -1 || s.getTimeOfAction().compareTime(c.getTimeLastDateToEnroll()) == 0)
				{
					ptr[cap].setStatus("Enrolled");
					c.setRoster(ptr);
				}
				delete temp;
				return 1;
			}
			else
			{
				Student* ptr = c.getStudent();
ptr[cap] = s;
ptr[cap].setStatus("Added");
c.setNumberOfEnrollment(cap + 1);

if (s.getTimeOfAction().compareTime(c.getTimeLastDateToEnroll()) == -1 || s.getTimeOfAction().compareTime(c.getTimeLastDateToEnroll()) == 0)
{
	ptr[cap].setStatus("Enrolled");
}
c.setRoster(ptr);
return 1;
			}
		}
		else
		{
		return -1;
		}
	}
} //ends Add Student

/* Drop Student */
int Instructor::dropStudent(const Student& s, Course& c, Time t)
{
	int course = findCourse(c);
	if (course == 0)
	{
		return 0;
	}
	else
	{
		int n = findStudent(s, c);
		if (n == 0)
		{
			return 0;
		}
		else
		{
			Student* ptr = c.getStudent();
			for (int i = 0; i < c.getNumberOfEnrollment(); i++)
			{
				if ((ptr + i)->getId() == s.getId())
				{
					(ptr + i)->setStatus("Dropped"); //set status to dropped
				}
			}
			return 1;
		}
	}
} //ends Drop Student

/* Add Course */
int Instructor::addCourse(const Course& c)
{
	int c_exists = findCourse(c);
	if (c_exists == 1)
	{
		return -1;
	}
	else if (numOfCoursesTaught == MAXCOURSE)
	{
		Course* ptr = new Course[numOfCoursesTaught + 1];
		Course* temp = courses;
		for (int i = 0; i < numOfCoursesTaught; i++)
		{
			ptr[i] = temp[i];
		}
		ptr[numOfCoursesTaught] = c;
		numOfCoursesTaught = getNumberOfCoursesTaught() + 1;
		this->courses = ptr;
		//delete temp;
		return 0;
	}
	else //if the course does not exist
	{
		courses[numOfCoursesTaught] = c; //add new course to the array of courses
		numOfCoursesTaught = getNumberOfCoursesTaught() + 1;
		return 1;
	}
} //ends Add Course

/* Find Course */
int Instructor::findCourse(const Course& c)
{
	for (int i = 0; i < numOfCoursesTaught; i++)
	{
		if ((courses + i)->getCourseNumber() == c.getCourseNumber())
		{
			return 1;
		}
	}
	return 0;
} //ends Find Course

/* Find Student */
int Instructor::findStudent(const Student& s, const Course& c)
{
	Student* roster = c.getStudent();
	for (int i = 0; i < sizeof(roster); i++)
	{
		if ((roster + i)->getId() == s.getId())
		{
			return 1;
		}
	}
	delete roster;
	return 0;
} //ends Find Student
