//Rifa Safeer Shah
//CECS 282 LAB 9
//PartTime.cpp

#include <iostream>

#include "cecs282lab9PartTime.hpp"

using namespace std;

PartTiem :: PartTime(): Staff() {
	hoursPerWeek = 0.0;
}

PartTime :: PartTime(string lastName, string firstName, string id, string s, Date d, double hRate, double hPerWeek): Staff(lastName, firstName, id, s, d, hRate) {
	hoursPerWeek = hPerWeek;
}

void PartTime :: setHoursPerWeek(double hPerWeek) {
	hoursPerWeek = hPerWeek;
}

double PartTime :: getHoursPerWeek() {
	return hoursPerWeek;
}

double PartTime :: monthlyEarning() {
	return Staff :: getHourRate() * hoursPerWeek * 4;
}
