Instructor Class:
private:
  int numOfCoursesTaught;
  string name; //formatted as First Last (assume no middle name)
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
  string getStudentStatus(const Strudent& s, const Course& c) const; //Enrolled, Added, or Dropped
  int addStudent(const Student& s, Course& c); //return -1 if a student already exists; return 0 if a student is not on the roster. Otherwise return 1
  int dropStudent(const Student& s, Course& c, Time t); //return 0 if a student is not on the roster. Otherwise, return 1.
  int findStudent(const Student& s, const Course& c); //return 0 if a student is not found. Otherwise, return 1.
  int addCourse(const Course& c); //return -1 if course already exists; return 0 if the numOfCoursesTaught reaches MAXCOURSE. Otherwise, add the course and return 1.
  int findCourse(const Course& c); //return 0 if a course is not found. Otherwise, return 1.


int Instructor :: addStudent(const Student&, const Course& crs)
{
  int idx_c = findCourse(crs);
  if (idx_c > -1)
  {
    Course c = Course (idx_c);
    int idx_c ...
      .
      .
      .
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
      Time act = s.getTimeOfAction();
      Time last = c.getTimeLastDateToEnroll();
        .
        .
        .
    else
    {
      val = 1;
      Student* tmp = c.getStudent();
      tmp[n] = s;
      Time act = s.getTimeOfAction;
      Time last = s.getTimeLastDateToEnroll();
      if (act.compareTime(last) == -1 ...
          .
          .
          .
          
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
      
