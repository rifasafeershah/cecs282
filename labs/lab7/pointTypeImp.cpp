//Rifa Safeer Shah
//CECS 282 LAB 7 PROBLEM
//pointTypeImp.cpp

//Implementation File pointTypeImp.cpp

#include <iostream>
#include "cecs282lab7pointType.h"

using namespace std;

void pointType :: setPoint(double x, double y)
{
	xCoordinate = x;
	yCoordinate = y;
}

void pointType :: print() const
{
	cout << "(" << xCoordinate << "," << yCoordinate << ")" << endl;
}

double pointType :: getX() const
{
	return xCoordinate;
}

double pointType :: getY() const
{
	return yCoordinate;
}

pointType :: pointType(double x, double y)
{
	xCoordinate = x;
	yCoordinate = y;
}
