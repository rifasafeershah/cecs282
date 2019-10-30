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
