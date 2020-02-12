//Rifa Safeer Shah
//CECS 282 LAB 1 PROBLEM 3

#include <iostream>
#include <fstream>
#include <cmath>
#include <stdio.h>
#include <math.h>

using namespace std;
void inputRainfall(int rainFall[], int size); //reads the monthly rainfall from the rainfall.txt file and stores them in the array
int calculateAverageRainFall(int rainFall[], int months); //returns the average monthly rainfall
void classifyAndDisplayRainfall(int rainFall[], int months); //display the average rainfall and the month with highest and lowest rainfall
string getRainFallType(int average, int currentMonth); //gets rainfall type
string getMonth(int month); //gets month

void inputRainfall(int rainFall[], int size)
{
  //Open the file
  ifstream inputFile;
  inputFile.open("rainfall.txt");
  //Initialize month counter
  int month = 0; //first month
  //Read the monthly rainfall in the file
  while (month < size) {
    inputFile >> rainFall[month];
    month++; //increment the months
  } //Ends while loop
  //Close the file
  inputFile.close();
} //Ends inputRainfall()

int calculateAverageRainFall(int rainFall[], int size)
{
  int sum = 0;
  int month = 0;
  while (month < size)
  {
    sum = sum + rainFall[month];
    month++;
  } //Ends while loop
  return ceil(sum / size); //average rainfall
} //Ends calculateAverageRainFall()

void classifyAndDisplayRainfall(int rainFall[], int months)
{
  int average = calculateAverageRainFall(rainFall, months);
  int highest = rainFall[0];
  int lowest = rainFall[0];
  int h_month = 0;
  int l_month = 0;
  int month = 1; //counter
  while (month < months) {
    if (rainFall[month] > highest)
    {
      highest = rainFall[month];
           h_month = month;
       }
       if(rainFall[month] < lowest){
           lowest = rainFall[month];
           l_month = month;
       }
       month++;
    }
  cout << "The year's average monthly rainfall was " << average << endl;
  cout << getMonth(h_month + 1) << " has the highest rainfall (" << highest << " mm)."<<endl;
  cout << getMonth(l_month + 1) << " has the highest rainfall (" << lowest << " mm)."<<endl;
  cout<<"Month Rainfall(mm) Classification"<<endl;
  cout<<"------- ----------------- ------------------"<<endl;
  month = 0;
  while(month < months){
      cout << (month + 1) << " "<<rainFall[month] << " " << getRainFallType(average, rainFall[month]) << endl;
      month++;
  } //Ends while loop
} //Ends classifyAndDisplayRainfall()

string getRainFallType(int average, int currentMonth)
{
   if(currentMonth > average)
   {
       double percent = ((currentMonth - average)*100.0)/average;
       if(percent > 20)
           return "Rainy"; //return rainy if over 20
   } //Ends if
   else if(currentMonth < average)
   {
       double percent = ((average - currentMonth)*100.0)/average;
       if(percent > 25)
           return "Dry"; //return dry if over 25
   } //Ends else if
   return "Average";
} //Ends getRainFallType()

string getMonth(int month)
{
   switch(month){
       case 1:
           return "January"; //0 -> jan
       case 2:
           return "February"; //1 -> feb
       case 3:
           return "March"; //2 -> mar
       case 4:
           return "April"; //3 -> apr
       case 5:
           return "May"; //4 -> may
       case 6:
           return "June"; // 5 -> jun
       case 7:
           return "July"; //6 -> jul
       case 8:
           return "August"; //7 -> aug
       case 9:
           return "September"; //8 -> sep
       case 10:
           return "October"; //9 -> oct
       case 11:
           return "November"; //10 -> nov
       case 12:
           return "December"; // 11 -> dec
       default:
           return "None";
   } //Ends switch
} //Ends getMonth()

int main()
{
  int size = 12; //array size
  int rainFall[size];
  inputRainfall(rainFall, size);
  classifyAndDisplayRainfall(rainFall, size);
  return 0;
} //Ends main()
