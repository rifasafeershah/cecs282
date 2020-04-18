//Rifa Safeer Shah
//CECS 282 LAB 8
//Sales.h

#ifndef PUBLICATION_SALE_H
#define PUBLICATION_SALE_H

#include <iostream>

using namespace std;

class Sales {
	/* Create public constructors */
	public:
		//Declare functions getData and putData
		void getData();
		void putData();
		
	/* Create protected contructrs */
	protected:
    //Declare an array to store sales for three months
		float saleArray[3];
};

#endif //PUBLICATION_SALE_H
