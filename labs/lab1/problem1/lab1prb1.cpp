//Rifa Safeer Shah
//CECS 282 LAB 1 PROBLEM 1

#include <iostream>
#include <cmath>
using namespace std;
int lab1prblm1()
{
  int integer;
  int sum = 0;
  cout << "Enter an integer: ";
  cin >> integer; //input an integer
  while (integer > 0)
  {
    int a = integer % 10;
    integer = integer / 10;
    if (a % 2 != 0)
    {
      sum = sum + a;
    } //Ends if statement
  } //Ends while loop
  cout << "Sum of all digits of an input: " << sum << endl;
  return 0;
} //Ends main
