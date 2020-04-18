//Rifa Safeer Shah
//CECS 282 LAB 8
//Digital.cpp

#include "cecs282lab8Digital.h"
#include "cecs282lab8Sales.h"
#include "cecs282lab8Publication.h"

#include <iostream>

//Define the functions getData to input publication, storage and three months of sales
void Digital :: getData()
{
	Publication :: getData();
	Sales :: getData();
	cout << "\nEnter storage of the Book: ";
	cin >> storage;
	return;
}

//Define the function putData to display the publication, storage and three months of sales
void Digital :: putData()
{
	Publication :: putData();
	Sales :: putData();
	cout << "\nStorage of the Book: " << storage << "MB(s)" << endl;
	return;
}
