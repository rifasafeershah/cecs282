//Rifa Safeer Shah
//CECS 282 LAB 8
//Main.cpp

#include "cecs282lab8Sales.h"
#include "cecs282lab8Publication.h"
#include "cecs282lab8Book.h"
#include "cecs282lab8Digital.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
	Book book;
	Digital digital;
	book.getData(); //gets data for the book
	book.putData(); //output data for the book
	cout << endl;
	digital.getData(); //gets data for the digital
	digital.putData(); //output data for the digital
	cout << endl;
	return 0;
}
