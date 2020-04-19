//Rifa Safeer Shah
//CECS 282 LAB 7 PROBLEM 1
//circleTypeImp.cpp

//Implementation file circleTypeImp.cpp

#include <iostream>
#include "cecs282lab7circleType.h"

using namespace std;

void circleType :: print() const
{
	cout << "Base Center: ";
	pointType :: print();
	cout << endl;
	
	cout << "Base Radius: " << radius << endl;
	cout << "Base Circumference: " << getCircumference() << endl;
	cout << "Base Area: " << getArea() << endl;
}

void circleType :: setRadius(double r)
{
	radius = r;
}

double circleType :: getRadius() const
{
	return radius;
}

double circleType :: getCircumference() const
{
	return (2 * 3.1416 * radius);
}

double circleType :: getArea() const
{
	return (3.1416 * radius * radius);
}

circleType :: circleType(double x, double y, double r):pointType(x,y)
{
	radius = r;
}
