#include <iostream>
#include <string>
#include "Grades.h"

int main() {
	Grades myGrades("gradeslist.txt");
	double gpa = myGrades.getGPA("279750343");
	cout << "GPA = " << gpa << "(expected 2.6667)" << endl;
	gpa = myGrades.getGPA("454454651");
	cout << "GPA = " << gpa << "(expected 3)" << endl;
	//system("pause"); // can pause main program for testing in Visual Studio
}
