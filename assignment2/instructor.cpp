#include <iostream>
#include "Instructor.h"
#include "Course.h"

using namespace std;

extern int const MAXCOURSE = 3;
extern int const CAPACITY;

/* Default Constructor */
Instructor::Instructor()
{
	this->numOfCoursesTaught = 0;
	this->name = "EMPTY";
	this->status = "EMPTY";
	this->courses = new Course[MAXCOURSE];
}

/* Overload Constructor */
Instructor::Instructor(string name, string status, Course* crs, int num)
{
	this->name = name;
	this->status = status;
	this->numOfCoursesTaught = num;
	for (int i = 0; i < MAXCOURSE; i++)
	{
		courses[i] = crs[i];
	}
}

/* Copy Constructor */
Instructor::Instructor(const Instructor& i)
{
	(*this).name = i.name;
	(*this).status = i.status;
	(*this).courses = i.courses;
	(*this).numOfCoursesTaught = i.numOfCoursesTaught;
	for (int x = 0; x < numOfCoursesTaught; x++)
	{
		courses[x] = i.courses[x];
	}
}

/* Destrcutor */
Instructor :: ~Instructor()
{
	delete[] courses;
}

/* Get Course */
Course* Instructor::getCourse() const
{
	return courses;
}

/* Get Number of Courses Taught */
int Instructor::getNumberOfCoursesTaught() const
{
	return numOfCoursesTaught;
}

/* Get Name */
string Instructor::getName() const
{
	return name;
}

/* Get Status */
string Instructor::getStatus() const
{
	return status;
}

/* Get Student Status */
string Instructor::getStudentStatus(const Student& s, const Course& c) const
{
	Student* stud = c.getStudent();
	string studStat = "";
	for (int i = 0; i < c.getNumberOfEnrollment(); i++)
	{
		if ((stud + i)->getId() == s.getId())
		{
			studStat = (stud + i)->getStatus();
		}
	}
	delete stud;
	return studStat;
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
}

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
					(ptr + i)->setStatus("Dropped");
				}
			}
			return 1;
		}
	}
}

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
}

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
		numOfCoursesTaught++;
		this->courses = ptr;
		delete temp;
		return 0;
	}
	else
	{
		courses[numOfCoursesTaught] = c;
		numOfCoursesTaught++;
		return 1;
	}
}

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
}
