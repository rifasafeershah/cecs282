//Rifa Safeer Shah
//CECS 282 LAB 9
//Education.cpp

#include <iostream>

#include "cecs282lab9Education.hpp"

using namespace std;

Education :: Education() {
	degree = None;
	major = "";
	research = 0;
}

Education :: Education(Degree d, string m, int r) {
	degree = d;
	major = m;
	research = r;
}

void Education :: setDegree(Degree d) {
	degree d;
}

void Education :: setMajor(string m) {
	major m;
}

void Education :: setResearch(int r) {
	research = r;
}

Degree Education :: getDegree() {
	return degree;
}

string Education :: getMajor() {
	return major;
}

int Education :: getResearch() {
	return research;
}
