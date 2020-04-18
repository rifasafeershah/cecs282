//Rifa Safeer Shah
//CECS 282 LAB 8
//Book.cpp

#include "cecs282lab8Publication.h"
#include "cecs282lab8Sales.h"
#include "cecs282lab8Book.h"

#include <iostream>

//Define the function getData to get the publication, sales, and page count
void Book :: getData()
{
	Publication :: getData();
	Sales :: getData();
	cout << "\nEnter Page Count of the Book: ";
	cin >> page_count;
	return;
}

//Define the function putData to display the publication, sales, and page count
void Book :: putData()
{
	Publication :: putData();
	Sales :: putData();
	cout << "\nPage count of the Book: " << page_count;
	return;
}
