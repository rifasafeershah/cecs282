//Rifa Safeer Shah
//CECS 282 LAB 1 PROBLEM 2

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
  int integer;
  int i;
  cout << "Enter an integer to display factors: ";
  cin >> integer; //input an integer
  cout << "Factors are: ";
  for (i = 1; i <= integer; i++)
  {
    if (integer % i == 0)
    {
      cout << i << " ";
    } //Ends if statement
  } //Ends for loop
  return 0; 
} //Ends main
