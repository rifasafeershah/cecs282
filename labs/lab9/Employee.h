//Rifa Safeer Shah
//CECS 282 LAB 9
//Employee.h

#ifndef Employee_hpp
#define Employee_hpp

#include <iostream>
#include <stdio.h>

#include "cecs282lab9EmployeeInfo.h"
#include "cecs282lab9Date.h"

using namespace std;

class Employee {
	protected:
		string lName;
		string fName;
		string ID;
		string sex;
		Date birthDate;
	public:
		Employee();
		Employee(string lastName, string firstName, string id, string s, Date d);
		void setLastName(string lastName);
		void setFirstName(string firstName);
		void setID(string id);
		void setSex(string s);
		void setBirthDate(Date d);
		string getlastName();
		string getFirstName();
		string getID();
		string getSex();
		Date getBirthDate();
		virtual double monthlyEarning() = 0;
		virtual void putData();
};
#endif /* Employee_hpp */
