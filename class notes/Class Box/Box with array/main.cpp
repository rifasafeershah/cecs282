#include <iostream>
#include "Box.h"
using namespace std;

void updateBox(Box boxes[], int size)
{
  for(int j = 0; j < size; j++)
  {
    int s = boxes[j].getSide();
    boxes[j].setSide(s+1);
  }
}
void updateBox(Box& b)
{
    int s = b.getSide();
    b.setSide(s+1);
}
int main()
{
  // Box box1;
  // updateBox(box1);
  // cout << "Box 1: " << box1.getSide() << endl;
  // Box box2(5);
  // cout << "Box 1: " << box1.getSide() << endl;
  // Box box3 = box1;
  // box3.setSide(10);
  // cout << "After Box 1: " << box1.getSide() << endl;
  // Box boxes[2];
  // boxes[0] = Box();
  // boxes[1] = Box(9);
  // updateBox(boxes, 2);
  // for(int i = 0; i < 2; i++)
  // {
  //   cout << "Area: " << boxes[i].area() << endl;
  // }
  // for(Box b : boxes)
  // {
  //       cout << "Area: " << b.area() << endl;
  // }

  return 0;
}
