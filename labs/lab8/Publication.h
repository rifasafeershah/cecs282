//Rifa Safeer Shah
//CECS 282 LAB 8
//Publication.h

#ifndef PUBLICATION_PUBLICATION_H
#define PUBLICATION_PUBLICATION_H

#include <iostream>

using namespace std;

class Publication {
	/* Create public constructors */
	public:
		//Declare two functions getData and putData
		void getData();
		void putData();
	
	/* Create protected constructors */
	protected:
		//Declare title and price
		string title; //declare title as string type
		float price; //declare price as float type
};

#endif //PUBLICATION_PUBLICATION_H
