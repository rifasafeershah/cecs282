//Rifa Safeer Shah
//CECS 282 LAB 7 PROBLEM 1
//circleType.h

//Class circleType

#ifndef H_CircleType
#define H_CircleType

#include "cecs282lab7pointType.h"

class circleType: public pointType
{
	public:
		void print() const;
		void setRadius(double r);
		double getRadius() const;
		double getCircumference() const;
		double getArea() const;
		circleType(double x = 0.0, double y = 0.0, double r = 0.0);
		
	protected:
		double radius;
};

#endif
