//Rifa Safeer Shah
//CECS 282 LAB 9
//Date.h
#ifndef Date_hpp
#define Date_hpp

#include <iostream>

using namespace std;

class Date {
	protected:
		int year;
		int month;
		int day;
	public:
		Date();
		Date(int m, int d, int y);
		void toString();
};

#endif /* Date_h */
