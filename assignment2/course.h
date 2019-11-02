Course Class:
private:
  int numOfEnrolled;
  string courseNumber; //four-digit integer
  string courseName; //e.g. CECS 282
  string semester; //Fall, Winter, Spring, Summer
  Time last_date_to_enroll; //time in secs
  Students* students; //pointer to array of students
public:
  Course();
  Course(string num, string name, string sem, Time last_date, Student* stdts, int numOfEnroll);
  Course(const Course& c);
  Course& operator=(const Course& c);
  ~Course();
  Student* getStudent() const;
  string getCourseNumber() const;
  string getCourseName() const;
  string getSemester() const;
  string getYear() const; //return the year of the semester (assume to be the year of the last date to enroll)
  int getNumberOfEnrollment() const;
  string getLastDateToEnroll() const; //return as Www Mmm dd hh:mm:ss yyyy
  Time getTimeLastDateToEnroll() const; //return last_date_to_enroll in seconds
  void setNumberOfEnrollment(int ne);
  void setRoster(Student* stdts);

//Overload
Course :: Course(string num, string name, string sem, Time last_date, Student* stdts, int numOfEnroll)
{
  this -> courseNumber = num;
  this -> courseName = name;
  this -> semester = sem;
  this -> last_date_to_enroll = last_date;
  this -> numOfEnrolled = numOfEnroll;
  setRoster(stdts);
}

//Copy
Course :: Course(const Course& c)
{
  (*this).courseNumber = c.courseNumber;
  (*this).courseName = c.courseName;
  (*this).semester = c.semester;
  (*this).numOfEnrolled = c.numOfEnrolled;
  
  for (int i = 0; i < numOfEnrolled; i++)
  {
    students[i] = c.students[i];
  }
}

