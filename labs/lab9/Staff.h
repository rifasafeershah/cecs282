//Rifa Safeer Shah
//CECS 282 LAB 9
//Staff.h

#ifndef Staff_hpp
#define Staff_hpp

#include <iostream>
#include <stdio.h>

#include "cecs282lab9Employee.h"
#include "cecs282lab9EmployeeInfo.h"

using namespace std;

class Staff: public Employee {
	protected:
		double hourRate;
	public:
		Staff();
		Staff(string lastName, string firstName, string id, string s, Date d, double hRate);
		double getHourRate();
		void setHourRate(double hRate);
		double monthlyEarning();
		void putData();
};
#endif /* Staff_hpp */
