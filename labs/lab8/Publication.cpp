//Rifa Safeer Shah
//CECS 282 LAB 8
//Publication.cpp

#include "cecs282lab8Publication.h"

#include <iostream>

using namespace std;

//Define the function getData to get title and price
void Publication :: getData()
{
	cout << "\nTitle: " << endl; //gets title of the book
	cin >> title;
	cout << "\nPrice: " << endl; //gets price of the book
	cin >> price;
	return;
}

//Define the function putData to get title and price
void Publication :: putData()
{
	cout << "\nTitle: " << title << "\nPrice: " << price; //print title and price
	return; 
}
