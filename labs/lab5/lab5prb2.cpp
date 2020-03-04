//Rifa Safeer Shah
//CECS 282 LAB 5 PROBLEM 2

#include <iostream>
#include<string>
using namespace std;

/* Person class */
class Person{
	private:
		string name; //name as a string
		float salary; //salary as a float
	public:
		void setPerson(); //User inputs name and salary
		string getName(); //Gets name
		float getSalary(); //Gets salary
}; //Ends Person class

/* setPerson */
void Person :: setPerson() {
	cout << "Enter name:";
	cin >> name; //input name
	cout<<"Enter Salary:";
	cin>>salary; //input salary
} //Ends setPerson

/* getName */
string Person :: getName() {
	return name; //returns name
} //Ends getName

/* getSalary */
float Person :: getSalary() {
	return salary; //returns salary
} //Ends getSalary

/* bubble sort */
void bsort(Person** p, int n, bool s) {
	/* first iteration */
	for(int i=0;i<n;i++) {
		/* second iteration */
		for(int j=i+1;j<n;j++) {
			Person* temp;
			/* comapring is s value is true or false and getSalary and getName */
			if((s == false && p[i] -> getSalary() > p[j] -> getSalary()) || (s == true && p[i] -> getName() > p[j] -> getName())) {
				temp = p[i]; //set temp to p[i]
				p[i] = p[j]; //set p[i] to p[j]
				p[j] = temp; //set p[j] to temp
			} //Ends if statement
		} //Ends for loop
	} //Ends for loop
} //Ends bsort

/* print the array */
void writeToConsole(Person** p, int n) {
	/* iterate through each element of array */
	for(int i = 0; i < n; i++) {
		cout << (p[i] -> getName()) << " " << (p[i] -> getSalary()) << endl;
	} //Ends for loop
} //Ends print

/* run the program */
int main() {
	int n;
	cout << "Enter number of person : ";
	cin >> n;
	Person* p[n]; //array of pointers to persons
	/* iterate through the array */
	for(int i = 0; i < n; i++) {
		p[i] = new Person(); 
		p[i] -> setPerson();
	} //Ends for loop
	cout << "Unsorted Array" << endl;
	writeToConsole(p, n); //call print function
	cout << "Sorted Array based on Name" << endl;
	bsort(p, n, true); //call bsort function
	writeToConsole(p, n); //call print function
	cout << "Sorted Array based on Salary" << endl;
	bsort(p, n, false); //call bsort function
	writeToConsole(p, n); //call print function
	return 0;
} //Ends main
