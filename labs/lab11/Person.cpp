//Rifa Safeer Shah
//CECS 282 LAB 11
//Person.cpp

#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

class Person {
	
	private:
		/* last name */
		string lastName;
		/* first name */
		string firstName;
		
	public:
		
		/* constructor */
		Person(string lname, string fname): lastName(lname), firstName(fname) { 
		
		}
		
		friend bool operator < (const Person&, const Person&);
		friend bool operator == (const Person&, const Person&);
		
		void display() const {
			cout << endl << lastName << " , "<< firstName;
		} // End of display()
		
}; // End of Person class

/* overload for Person class */
bool operator < (const Person& p1, const Person& p2)
{
	if (p1.lastName == p2.lastName) {
		return (p1.firstName < p2.firstName) ? true : false;
		return (p1.lastName < p2.lastName) ? true : false;
	} // Ends if-statement
}

/* overload for Person class */
bool operator == (const Person& p1, const Person& p2) {
	return (p1.lastName == p2.lastName &&
	p1.firstName == p2.firstName) ? true : false;
}

/* compare Persons using pointers */
class comparePersons {
	public:
		bool operator() (const Person* ptrP1, const Person* ptrP2) const {
			return *ptrP1 < *ptrP2;
		}
};

/* display Persons using pointers */
class displayPerson {
	public:
		void operator() (const Person* ptrP) const {
			ptrP -> display();
		}
};

int main() {
	
	/* create 6 new Persons */
	Person* ptrP1 = new Person("Stark", "Tony");
	Person* ptrP2 = new Person("Odinson", "Thor");
	Person* ptrP3 = new Person("Rogers", "Steve");
	Person* ptrP4 = new Person("Romanoff", "Natasha");
	Person* ptrP5 = new Person("Barton", "Clint");
	Person* ptrP6 = new Person("Banner", "Bruce");
	
	/* Create multisets */
	multiset<Person*, comparePersons > multiPtrsPers;
	multiPtrsPers.insert(ptrP1);
	multiPtrsPers.insert(ptrP2);
	multiPtrsPers.insert(ptrP3);
	multiPtrsPers.insert(ptrP4);
	multiPtrsPers.insert(ptrP5);
	multiPtrsPers.insert(ptrP6);
	
	/* displaying Persons */
	for_each(multiPtrsPers.begin(), multiPtrsPers.end(), displayPerson());
	cout << endl;
	
	return 0;
	
} // End of Main
