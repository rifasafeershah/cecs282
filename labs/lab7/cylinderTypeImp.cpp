//Rifa Safeer Shah
//CECS 282 LAB 7 PROBLEM 1
//cylinderTypeImp.cpp

#include <iostream>
#include "cecs282lab7cylinderType.h"
#include "cecs282lab7circleType.h"

using namespace std;
void cylinderType :: print() const
{	
	circleType :: print(); //print
	
	cout << "Cylinder height: " << height << endl; //prints the height of the cylinder
	cout << "Cylinder surface area: " << getSurfaceArea() << endl; //prints the surface area of the cylinder
	cout << "Cylinder volume: " << getVolume() << endl; //prints the volume of the cylinder
}

/* sets the height of the cylinder */
void cylinderType :: setHeight(double h)
{
	height = h; //set height to variable h
}

/* sets the center, radius and height of the cylinder */
void cylinderType :: setCenterRadiusHeight(double x, double y, double r, double h)
{
	setPoint(x,y); //sets the point of the cylinder (x coordinate and y coordinate)
	setRadius(r); //sets radius of the cylinder
	setHeight(h); //sets height of the cylinder
}

/* gets the height of the cylinder */
double cylinderType :: getHeight() const
{
	return height; //returns height
}

/* gets the surface area of the cylinder */
double cylinderType :: getSurfaceArea() const
{
	return getCircumference() * getHeight() + 2 * getArea(); //returns surface area
}

/* gets the volume of the cylinder */
double cylinderType :: getVolume() const
{
	return getArea() * getHeight(); //returns volume
}

/* create a cylinder */
cylinderType :: cylinderType(double x, double y, double r, double h):circleType(x,y,r)
{
	height = h;
}
