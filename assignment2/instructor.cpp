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
