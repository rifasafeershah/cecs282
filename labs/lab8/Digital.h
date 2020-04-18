//Rifa Safeer Shah
//CECS 282 LAB 8
//Digital.h

#ifndef PUBLICATION_DIGITAL_H
#define PUBLICATION_DIGITAL_H

#include "cecs282lab8Publication.h"
#include "cecs282lab8Sales.h"

//Class Digital is created from classes Publication and Sales

//In this class you need to declare two functions getData and putData and a data member for storage
class Digital: public Publication, public Sales {
	/* Create public constructors */
	public:
		/* Declare two functions getData and putData */
		void getData();
		void putData();
	
	/* Create protected constructors */
	protected:
		float storage; //Storage capacity
};
#endif //PUBLICATION_DIGITAL_H
