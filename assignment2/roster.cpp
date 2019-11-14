#include <iostream>
#include "Course.h"
#include "Instructor.h"
#include "Student.h"
#include "Time.h"
#include <ctime>
#include <string>
#include <fstream>

using namespace std;
//ofstream outFile("raw_data_courseNumber.txt");
//ifstream inFile("courseName_courseNumber.txt");
extern const int CAPACITY = 35;
extern const int MAXCOURSE = 3;

int main()
{
	time_t secs = time(0); //This is the current time (GMT +0)
	Time last_date(secs - 10000); //Set up the last date of enrollment
	Student* students = new Student[CAPACITY]; //Set up the student dynamic array with CAPACITY. The CAPACITY for this test is 2.

	//Create 4 students
	Student s("123456789", "Kobe Bryant", "Senior", 0);
	Student s1("987654321", "Lebron James", "Sophomore", 1000);
	Student s2("123654987", "James Harden", "Senior", secs - 10);
	Student s3("345698712", "Anthony Davis", "Sophomore", 1007770);

	Course* courses = new Course[MAXCOURSE]; //Set up the courses dynamic array with MAXCOURSE. The MAXCOURSE for this test is 3

	//Create 3 courses;
	Course c("1456", "CECS228", "Fall", last_date, students, 0);
	Course c1("1345", "CECS228", "Fall", last_date, students, 0);
	Course c2("1234", "CECS282", "Fall", last_date, students, 0);
	Course c3("1233", "CECS282", "Fall", last_date, students, 0);



	//Create an instructor
	Instructor inst("Minhthong Nguyen", "Part-time", courses, 0);



	//Comment out line(s) or combination of lines below and observe the effect of add and drop.

	/*for instance, with line "inst.addCourse(c)" activated, the output is
		Part-time Instructor: Minhthong Nguyen
		Course Number: 1456
		Course Name: CECS228
		Semester: Fall 2019
		Last Date To Enroll: Thu Sep 26 12:19:11 2019
		Number of enrollment: 0
		Maximum Enrollment: 2
	*/

	//Add courses
	inst.addCourse(c);
	inst.addCourse(c1);
	inst.addCourse(c2);
	inst.addCourse(c2); //Add the same course again should have no effect on the course that an instructor teaches.

	//Add students to the courses
	inst.addStudent(s, c);
	inst.addStudent(s2, c);
	inst.addStudent(s3, c);
	inst.addStudent(s1, c);
	inst.addStudent(s1, c); //Add the same student again to the same class should have no effect.
	inst.addStudent(s, c2);
	inst.addStudent(s2, c2);
	inst.addStudent(s3, c2);
	inst.addStudent(s1, c1);
	inst.addStudent(s, c1);
	inst.addStudent(s2, c1);
	inst.addStudent(s1, c1);

	//Add student to a non-existing course should have no effect, and the number of enrollment of that course should not increase.
	inst.addStudent(s, c3);

	//cout << "Enrollment: " << c3.getNumberOfEnrollment() << endl;



	//Drop students from the courses
	inst.dropStudent(s2, c, secs);
	inst.dropStudent(s1, c1, secs);
	inst.dropStudent(s, c2, secs);
	inst.dropStudent(s2, c2, secs);

	//Drop student from a non-existing course should have no effect
	inst.dropStudent(s, c3, secs);



	//Displaying the Information of a course

	//Also display all students in that course
	Course* temp = inst.getCourse();
	for (int i = 0; i < inst.getNumberOfCoursesTaught(); i++)
	{
		string CourseName = temp[i].getCourseName() + ".txt";
		ofstream FormatFile(CourseName);
		//get the instructor information and write into file
		string instStatus = inst.getStatus();
		string instName = inst.getName();
		FormatFile << instStatus << " Instructor: " << instName << endl;
		//get student information
		Student* tmp2 = temp[i].getStudent();
		//write out course information into fule
		FormatFile << "Course Number: " << temp[i].getCourseNumber() << "\nCourse:" << temp[i].getCourseName()
			<< "\n" << "Semester: " << temp[i].getSemester() << " " << temp[i].getYear() << "\nEnrollment: " << temp[i].getNumberOfEnrollment() <<
			"\nMaximum Enrollment: " << CAPACITY << "\n" << "Last Date To Enroll: "
			<< temp[i].getLastDateToEnroll() << endl;
		//write information above students
		FormatFile << "ID\t" << "  Last Name\t" << "First Name\t" << "Level\t" << "  Status   " << "Date" << endl;
		//loop through every student and write each information
		for (int s = 0; s < temp[i].getNumberOfEnrollment(); s++)
		{
			//break down information of the student
			string studentName = tmp2[s].getName();
			int indexSpace = tmp2[s].getName().find(" ");
			string studentId = tmp2[s].getId().substr(0, 9);
			string fName = studentName.substr(0, indexSpace);
			string lName = studentName.substr(indexSpace + 1, studentName.length() - indexSpace);
			string studentLevel = tmp2[s].getLevel().substr(0, 9);
			string studentStatus = tmp2[s].getStatus().substr(0, 8);
			string date = tmp2[s].getTimeOfAction().getMMDDYYYY();

			//create conditional statements to write information in a neat format.
			//if last name is less than 6 characters, tab twice to allign
			if (lName.length() < 6) {
				//if lname length is less than 6 AND lvl is sophomore, get spacing
				if (studentLevel == "Sophomore") {
					//if lname < 6, lvl sophomore AND dropped
					if (studentStatus == "Dropped") {
						FormatFile << studentId << " " << lName.substr(0, 15) << "\t\t" << fName.substr(0, 15) << "\t\t" << studentLevel
							<< " " << studentStatus << "  " << date << endl;
					}
					//if llname < 6, lvl sophomore AND Enrolled
					else if (studentStatus == "Enrolled") {
						FormatFile << studentId << " " << lName.substr(0, 15) << "\t\t" << fName.substr(0, 15) << "\t\t" << studentLevel
							<< " " << studentStatus << " " << date << endl;
					}
					else {
						FormatFile << studentId << " " << lName.substr(0, 15) << "\t\t" << fName.substr(0, 15) << "\t\t" << studentLevel
							<< " " << studentStatus << "\t   " << date << endl;
					}
				}
				//if lname length is less than 6 AND if status is dropped
				else if (studentStatus == "Dropped") {
					FormatFile << studentId << " " << lName.substr(0, 15) << "\t\t" << fName.substr(0, 15) << "\t\t" << studentLevel
						<< " " << studentStatus << "  " << date << endl;
				}
				//if llname < 6, AND Enrolled
				else if (studentStatus == "Enrolled") {
					FormatFile << studentId << " " << lName.substr(0, 15) << "\t\t" << fName.substr(0, 15) << "\t\t" << studentLevel
						<< " " << studentStatus << " " << date << endl;
				}
				//Only if lname length is less than 6
				else {
					FormatFile << studentId << " " << lName.substr(0, 15) << "\t" << fName.substr(0, 15) << "\t\t" << studentLevel
						<< "\t  " << studentStatus << "\t   " << date << endl;
				}
			}
			//if level is sophomore, change spacing
			else if (studentLevel == "Sophomore") {
				//if lvl is sophomore and status is dropped
				if (studentStatus == "Dropped") {
					FormatFile << studentId << " " << lName.substr(0, 15) << "\t\t" << fName.substr(0, 15) << "\t\t" << studentLevel
						<< " " << studentStatus << "  " << date << endl;
				}
				//if lvl sophomore, AND Enrolled
				else if (studentStatus == "Enrolled") {
					FormatFile << studentId << " " << lName.substr(0, 15) << "\t" << fName.substr(0, 15) << "\t\t" << studentLevel
						<< " " << studentStatus << " " << date << endl;
				}
				//only if lvl is sophomore
				else {
					FormatFile << studentId << " " << lName.substr(0, 15) << "\t" << fName.substr(0, 15) << "\t\t" << studentLevel
						<< " " << studentStatus << "\t   " << date << endl;
				}
			}
			//if status is dropped
			else if (studentStatus == "Dropped") {
				FormatFile << studentId << " " << lName.substr(0, 15) << "\t" << fName.substr(0, 15) << "\t\t" << studentLevel
					<< "\t  " << studentStatus << "  " << date << endl;
			}
			// if the status is Enrolled
			else if (studentStatus == "Enrolled") {
				FormatFile << studentId << " " << lName.substr(0, 15) << "\t" << fName.substr(0, 15) << "\t\t" << studentLevel
					<< "\t  " << studentStatus << " " << date << endl;
			}
			//no special change to the spacing
			else {
				FormatFile << studentId << " " << lName.substr(0, 15) << "\t" << fName.substr(0, 15) << "\t\t" << studentLevel
					<< "\t  " << studentStatus << "\t   " << date << endl;
			}
		}
		//create divider
		FormatFile << "---------------------------------------------------------------------" << endl;
		FormatFile.close();
	}
	return 0;
}
