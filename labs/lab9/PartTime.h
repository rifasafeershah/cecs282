//Rifa Safeer Shah
//CECS 282 LAB 9
//PartTime.h

#ifndef PartTime_hpp
#define PartTime_hpp

#include <iostream>
#include <stdio.h>

#include "cecs282lab9Staff.h"

using namespace std;

class PartTime: public Staff {
	protected:
		double hoursPerWeek;
	public:
		PartTime();
		PartTime(string lastName, string firstName, string id, string s, Date d, double hRate, double hPerWeek);
		void setHoursPerWeek(double hPerWeek);
		double getHoursPerWeek();
		double monthlyEarning();
		void putData();
};
#endif /* PartTime_hpp */
