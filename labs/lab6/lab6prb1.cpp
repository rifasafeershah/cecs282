//Rifa Safeer Shah
//CECS 282 LAB 6 PROBLEM 1

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

void transform(char *raw, char *testStr);
bool testPalindrome(char *str);

/* Convert raw strings into c strings */
void transform(char *raw, char *testStr)
{
	int index = 0; //set index to 0
	int length = 0; //set length to 0
	char alphabet; //set alphabet to char type
	
	/* find size of character array */
	while (*(raw + index) != '\0') {
		
		alphabet = *(raw + index);
		
		/* if character not a-z then it skips */
		if ('a' <= alphabet && alphabet <= 'z') {
			length = length + 1;
		} //Ends if statement
		
		/* if character not A-Z then it skips */
		else if ('A' <= alphabet && alphabet <= 'Z'){
			length = length + 1;
		} //Ends else if statement
		
		index++;
	} //Ends while loop
	
	length = length + 1;
	int position = 0;
	index = 0;
	
	/* find the size of character array */
	while (*(raw + index) != '\0') {
		alphabet = *(raw + index);
		
		if ('a' <= alphabet && alphabet <= 'z') {
			
			*(testStr + position) = alphabet; //converts raw string to c string
			position++;
			
		} //Ends if statement
		
		else if ('A' <= alphabet && alphabet <= 'Z') {
			
			*(testStr + position) = tolower(alphabet); //converts raw string to lowercase
			position++;
			
		} //Ends else if statement
		
		index++;
		
	} //Ends while loop
	
	*(testStr + position) = '\0';
	
} //Ends transform function

/* check if string is a palindrome */
bool testPalindrome(char *str)
{
	int length = strlen(str);
	int starting = 0; //set starting to first element
	int ending = length - 1; //set ending to last element
	
	/* while starting is less than ending */
	while (starting < ending) {
		if (*(str + starting) != *(str + ending)) {
			return false;
		} //Ends if statement
		
		starting = starting + 1;
		ending = ending - 1;
	
	} //Ends while loop
	
	return true;
	
} //Ends testPalindrome function

int main()
{
	char alphabet[100];
	char testStr[100];
	char redo;
	do {
		cout << "Enter a sentence: " ;
		
		cin.getline(alphabet, 99, '\n'); //gets line
		
		transform(alphabet, testStr); //Calls transform function
		
		if (testPalindrome(testStr)) {
			
			cout << alphabet << " is a Palindrome." << endl; //print if a palindrome
			
		} //Ends if statement
		
		else {
			
			cout << alphabet << " is not a Palindrome." << endl; //print if not a palindrome
			
		} //Ends else statement
		
		cout << endl << "Do you want to redo this simulation [y/n] ? "; //attempt the program again
		cin >> redo; //Input for redo
		cin.ignore(256,'\n'); //Ignore the characters until new line
		cout << endl;
		
	} while (redo == 'y' || redo == 'Y'); //Ends do while
	
} //Ends main
