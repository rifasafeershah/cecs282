//Rifa Safeer Shah
//CECS 282 LAB 4 PROBLEM 2

#include <iostream>
#include <fstream>
using namespace std;

/* read data from file */
int readData(int **arr){
	ifstream input;
	input.open("data.txt"); //open the file
	/* if file is not found */
	if (input.fail()){
		cout << "File not found." << endl;
	} //Ends if statement
	int count = 0;
	int val;
	/* iterate through the array */
	while (input >> val){
		*(*arr + count) = val;
		count++;
	} //Ends while loop
	input.close(); //close the file
	return count;
} //Ends readData

/* sort array in the ascending order */
void sort(int *arr, int last){
	/* first iteration */
	for (int i = 0; i < last - 1; i++){
		/* second iteration */
		for (int j = 0; j < last - i - 1; j++){
			//swap if the previous integer is smaller than the next integer
			if (*(arr + j) > *(arr + j + 1)){
				int val = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = val;
			} //Ends i statement
		} //Ends for loop
	} //Ends for loop
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
	int *arr = new int[100];
	int n = readData(&arr); //call readData function
	cout << "LAB 4 PROBLEM 2" << endl;
	cout << "Original array: " << endl;
	writeToConsole(arr, n); //call writeToConsole function
	sort(arr, n); //call sort function
	cout << "Sorted array: " << endl;
	writeToConsole(arr, n); //call writeToConsole function
	delete[] arr; //delete pointer to the array
	return 0;
} //Ends main
