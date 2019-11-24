#ifndef BOX_H
#define BOX_H
class Box 
{
  public:
    Box(); //default constructor
    Box(int x); //overloaded constructor
    Box (const Box& a); //Copy constructor
    int getSide() const;
    void setSide(int x);
    int area() const;
    void updateTime();
  private:
    int i;
    Watch watches[9];
};

#endif
