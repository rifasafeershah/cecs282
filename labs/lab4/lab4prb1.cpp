//Rifa Safeer Shah
//CECS 282 LAB 4 PROBLEM 1

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/* read data from file */
int readData(int *(&arr)){
	int n;
	ifstream input;
	input.open("data.txt"); //open the file
	/* if file is not found */
	if (input.fail()){
		cout << "File not found." << endl;
		return 0;
	} //Ends if statement
	input >> n;
	arr = new int[n]; //make array of the input values
	/* iterate through the array */
	for (int i = 0; i < n; i++){
		input >> *(arr + i);
	} //Ends for loop
	input.close(); //close the file
	return n;
} //ends readData

/* sort array in the ascending order */
void sort(int *arr, int last){
	/* first iteration */
	for (int i = 0; i < last; i++){
		/* second iteration */
		for (int j = 0; j < last - i - 1; j++){
			//swap if the previous integer is smaller than the next integer
			if(*(arr + j) > *(arr + j + 1)){
				int val = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = val;
			} //Ends if statement
		} //ends for loop
	} //ends for loop
} //Ends sort

/* write the elements to console */
void writeToConsole(int *arr, int last){
	/* iterate through the array and print out the sorted elements */
	for (int i = 0; i < last; i++){
		cout << *(arr + i) << " ";
	} //Ends for loop
	cout << endl;
} //Ends writeToConsole

/* call the functions */
int main(){
	int *arr;
	int n;
	n = readData(arr); //call readData function
	cout << "LAB 4 PROBLEM 1" << endl;
	cout << "Original array: " << endl;
	writeToConsole(arr, n); //call writeToConsole function before sorting
	sort(arr, n); //call sort function
	cout << "Sorted array: " << endl;
	writeToConsole(arr, n); //call writeToConsole function after sorting
	return 0;
} //Ends main
