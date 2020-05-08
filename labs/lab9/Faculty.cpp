//Rifa Safeer Shah
//CECS 282 LAB 9
//Faculty.cpp

#include <iostream>

#include "cecs282lab9Faculty.hpp"

using namespace std;

Faculty :: Faculty(): Employee() {
	education = Education();
}

Faculty :: Faculty(string lastName, string firstName, string id, string s, Date d, Level l, Education edu): Employee(lastName, firstName, id, s, d) {
	level = l;
	education = edu;
}

void Faculty :: setLevel(Level l) {
	level = l;
}

void Faculty :: setEducation(Education edu) {
	education = edu;
}

Level Faculty :: getLevel() {
	return level;
}

string Faculty :: levelToString() {
	if (getLevel() == AS) {
		return "Assistant";
	}
	else if (getLevel() == AO) {
		return "Associate";
	}
	else {
		return "Full";
	}
}

Education Faculty :: getEducation() {
	return education;
}

double Faculty :: monthlyEarning() {
	if (getLevel() == AS) {
		return FACULTY_MONTHLY_SALARY;
	}
	else if (getLevel() == AO) {
		return FACULTY_MONTHLY_SALARY * 1.2;
	}
	else {
		return FACULTY_MONTHLY_SALARY * 1.4;
	}
}

void Faculty :: putData() {
	Employee :: putData();
	cout << levelToString() << " Professor" << endl;
	cout << "Monthly Salary: " << monthlyEarning() << endl;
}
