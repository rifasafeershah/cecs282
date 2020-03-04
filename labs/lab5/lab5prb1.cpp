//Rifa Safeer Shah
//CECS 282 LAB 5 PROBLEM 1

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/* read data from file */
int *readData(int &n){
	ifstream input;
	input.open("data.txt"); //open the file
	/* if file is not found */
	if (input.fail()){
		cout << "File not found." << endl;
		return 0;
	} //Ends if statement
	input >> n;
	int *arr = new int[n];
	/* iterate through the array */
	for (int i = 0; i < n; i++){
		input >> *(arr + i);
	} //Ends for loop
	input.close(); //close the file
	return arr;
}

/* sorts the array */
void sort(int *arr, int last){
	/* first iteration */
	for (int i = 0; i < last; i++){
		/* second iteration */
		for (int j = 0; j < last - i - 1; j++){
			if (*(arr + j) > *(arr + j + 1)){
				int temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			} //Ends if statement
		} //Ends for loop
	} //Ends for loop
} //Ends sort

/* write the elements to the console */
void writeToConsole(int *arr, int last){
	/* iterate through the array and print out the sorted elements */
	/* ascending order */
	cout << "ascending order" << endl;
	for (int i = 0; i < last; i++){
		cout << *(arr + i) << " ";
	} //Ends for loop
	cout << endl;
	
	/* iterate through the array and print out the sorted elements */
	/* descending order */
	cout << "descending order" << endl;
	for (int i = last - 1; i >= 0; i--){
		cout << *(arr + i) << " ";
	} //Ends for loop
	cout << endl;
} //Ends writetoConsole

/* calls the function */
int main(){
	int *arr;
	int n;
	arr = readData(n); //call readData function
	cout<<"LAB 5 PROBLEM 1" << endl;
	cout<<"Before sorting: "<<endl; //before sort
  writeToConsole(arr, n); //call writeToConsole function
  sort(arr, n); //call sort function
  cout<<"After sorting: "<<endl; //after sort
  writeToConsole(arr, n); //call writeToConsole function
  delete[] arr; //delete pointer to the array
  return 0;
}
