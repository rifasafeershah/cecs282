//Rifa Safeer Shah
//CECS 282 LAB 9
//Staff.cpp

#include <iostream>

#include "cecs282lab9Staff.hpp"

using namespace std;

Staff :: Staff(): Employee() {
	hourRate = 0.0;
}

Staff :: Staff(string lastName, string firstName, string id, string s, Date d, double hRate): Employee(lastName, firstName, id, s, d){
	hourRate = hRate;
}

double Staff :: getHourRate() {
	return hourRate;
}

void Staff :: setHourRate(double hRate) {
	hourRate = hRate;
}

double Staff :: monthlyEarning() {
	return hourRate * 160;
}

void Staff :: putData() {
	Employee :: putData();
	cout << "Full Time\n" << "Monthly Salary: " << monthlyEarning() << endl;
}
