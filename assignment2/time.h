Time Class:
private:
	time_t secs; //time in seconds. if secs = 0, it represents Jan 1st, 1970
public:
	Time();
	Time(time_t t);
	Time(const Time& t);
	string toString() const; //return time in the following format Www Mmm dd hh:mm:ss yyyy
	string getMMDDYYYY() const; //return time in the following format MM/DD/YYYY
	string getYear() const; //return year of time.
	int compareTime(const Time& t); //return -1 if less than, 0 if equal, and 1 if more than
