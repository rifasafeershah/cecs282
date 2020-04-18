//Rifa Safeer Shah
//CECS 282 LAB 8
//Book.h

//Class Book is created from classes Publication and Sales
#ifndef PUBLICATION_BOOK_H
#define PUBLICATION_BOOK_H

#include "cecs282lab8Publication.h"
#include "cecs282lab8Sales.h"

#include <iostream>

using namespace std;

//In this class you need to declare two functions getData and putData and a data member for page
//count
class Book: public Publication, public Sales {
	/* Create public constructors */
	public:
		/* Declare two function getData and putData */
		void getData();
		void putData();
	
	/* Create protected constructors */
	protected:	
		int page_count; //Number of pages
};

#endif //PUBLICATION_BOOK_H
