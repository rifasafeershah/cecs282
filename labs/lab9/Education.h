//Rifa Safeer Shah
//CECS 282 LAB 9
//Education.h

#ifndef Education_hpp
#define Education_hpp

#include <iostream>
#include <stdio.h>

using namespace std;

enum Degree{
	None,
	MS,
	PhD
};

class Education {
	protected:
		Degree degree;
		string major;
		int research;
	public:
		Education();
		Education(Degree d, string m, int r);
		void setDegree(Degree degree);
		void setMajor(string m);
		void setResearch(int r);
		Degree getDegree();
		string getMajor();
		int getResearch();
};
#endif /* Education_hpp */
