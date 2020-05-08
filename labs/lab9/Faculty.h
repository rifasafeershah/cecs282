//Rifa Safeer Shah
//CECS 282 LAB 9
//Faculty.h

#ifndef Faculty_hpp
#define Faculty_hpp

#include <iostream>
#include <stdio.h>

#include "cecs282lab9Employee.h"
#include "cecs282lab9Education.h"
#include "cecs282lab9EmployeeInfo.h"

using namespace std;

enum Level {
	AS,
	AO,
	FU
};

class Faculty : public Employee {
	protected:
		Level level;
		Education education;
	public:
		Faculty();
		Faculty(string lastName, string firstName, string id, string s, Date d, Level l, Education edu);
		void setLevel(Level l);
		void setEducation(Education edu);
		Level getLevel();
		string levelToString();
		Education getEducation();
		double monthlyEarning();
		void putData();
};
#endif /* Faculty.hpp */
