class Student
{
	private:
		string level;
		string id:
		string name;
	
Student Class:
private:
	string level; //Freshman, Sophomore, Junior, Senior
	string id;
	string name; //formatted as First Last (assume no middle name)
	string status; //Added, Enrolled, Dropped
	Time date_of_action; //time in secs when enrolled, add or drop occurs
public:
	Student();
	Student(string id, string name, string level, Time date_of_action);
	Student(const Student& s);
	Student& operator=(const Student& s);
	string getLevel() const;
	string getId() const;
	string getName() const;
	string getDateOfAction() const; //return as Www Mmm dd hh:mm:ss yyyy
	Time getTimeOfAction() const; //return date_of_action in seconds
	string getStatus() const;
	void setStatus(string stat);
	void setTimeOfAction(Time act);
