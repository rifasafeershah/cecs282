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

		}
	}
}
	{

		Course c = Courses(idx_c);

		int idx_c ...

			.

			.

			.

	}

	else

	{

		int val = c;

		int n = c.getNumberOfEnrollment();

		if n >= CAPACITY

		{

		  val = 0;

		  Student* ptr = new Student(n + 1);

		  Student* tmp = c.getStudent();

		  for (int i = 0; i < n; i++)

		  {

			ptr[i] = tmp[i];

		  }

		  ptr[n] = s;

		  Time act = s.getTimeDateOfAction();

		  Time last = c.getTimeLastDateToEnroll();

			.

			.

			.

			  if (idx_c > -1)

			  {

				Course c = Courses(idx_c);

				int idx_s = findStudent(s,c);

				if (idx_s > -1)

				{

				  .

				  .

				  .

				}

			  }

		}

		else

		{

			val = 1;

			Student* ptr = c.getStudent();

			tmp[n] = s;

			Time act = s.getTimeOfAction();

			Time last = c.getTimeLastDateToEnroll();

			if (act.compareTime(last) == -1)

			{

				.

					.

					.

			}

		}

	}

}



/* Drop Student */

int Instructor::dropStudent(const Student& s, const Course& crs, Time dropTime)

{

	int idx_c = findCourse(crs);

	if (idx_c > -1)

	{

		Course c = Courses(idx_c);

		int idx_s = findStudent(s, c);

		if (idx_s <= -1)

		{

			return 0;

		}

		else

		{

			Student* tmp = c.getStudent();

			Time act = tmp[idx_s].getTimeOfAction();

			if droptime.compareTime(act) == -1)

	  {

	  return 0;

	  }

			else

			{

				.

					.

					.

			}

		}

	}

}



/* Find Student */

int Instructor::findStudent(const Student& s, const Course& c)

{

}



/* Add Course */

int Instructor::addCourse(const Course& c)

{

}



/* Find Course */

int Instructor::findCourse(const Course& c)

{

}
