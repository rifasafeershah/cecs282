#include "Box.h"
#include <iostream>
using namespace std;
Box :: Box() //default constructor
{
  cout << "Default constructor" << endl;
  i = 1;
}
Box :: Box(int x) //overloaded constructor
{
  cout << "Overloaded constructor" << endl;
  i = x;
}

Box :: Box(const Box& a)
{
  cout << "Copy constructor" << endl;
  i = a.i;
}
int Box :: getSide() const
{
  return i;
}
void Box :: setSide(int x)
{
  i = x;
}
int Box :: area() const
{
  return 6 * i * i;
}
