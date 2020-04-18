//Rifa Safeer Shah
//CECS 282 LAB 8
//Sales.cpp

#include "cecs282lab8Sales.h"

#include <iostream>

using namespace std;

//Define the function getData to input sales for three months
void Sales :: getData()
{
	cout << "\nInput sales for three months: ";
	/* Iterate through three months */
	for (int i = 0; i < 3; i++)
	{
		cout << "\nMonth " << i + 1 << ": ";
		cin >> saleArray[i];
	} //Ends for loop
	return;
}

//Define the function putData to display three months of sales
void Sales :: putData()
{
	cout << "\nDisplay three months of sales: ";
	/* Iterate through three months */
	for (int i = 0; i < 3; i++)
	{
		cout << "\nMonth " << i + 1 << ": " << saleArray[i];
	} //Ends for loop
	return;
}
