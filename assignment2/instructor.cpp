#include "Instructor.h"

int Instructor :: addStudent(const Student&, const Course& crs)
{
  int idx_c = findCourse(crs);
  if (idx_c > -1)
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
      Student* ptr = new Student(n+1);
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
            Course c = Courses (idx_c);
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

int Instructor :: dropStudent(const Student& s, const Course& crs, Time dropTime)
{
  int idx_c = findCourse(crs);
  if (idx_c > -1)
  {
    Course c = Courses(idx_c);
    int idx_s = findStudent(s,c);
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
