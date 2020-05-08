//Rifa Safeer Shah
//CECS 282 LAB 9
//Employee.cpp

#include <iostream>

#include "cecs282lab9Employee.h"

using namespace std;

Employee :: Employee() {
	lName = "";
	fName = "";
	ID = "";
	sex = "";
	birthDate = Date();
}

Employee :: employe(string lastName, string firstName, string id, string s, Date d) {
	lName = lastName;
	fName = firstName;
	ID = id;
	sex = s;
	birthDate = d;	
}

void Employee :: setLastName(string lastName) {
	lName = lastName;
}

void Employee :: setFirstName(string firstName) {
	fName = firstName;
}

void Employee :: setID(string id) {
	ID = id;
}

void Employee :: setSex(string s) {
	sex = s;
}

void Employee :: setBirthDate(Date d) {
	birthDate = d;
}

string Employee :: getLastName() {
	return lName;
}

string Employee :: getFirstName() {
	return fName;
}

string Employee :: getID() {
	return ID;
}

string Employee :: getSex() {
	return sex;
}

string Employee :: getBirthDate() {
	return birthDate;
}

void Employee :: putData() {
	cout << "\n ID Employee Number: " << ID;
	cout << "\n Employee Name: " << fName << " " << lName;
	cout << birthDate.toString() << endl;
}
