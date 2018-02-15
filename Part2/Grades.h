Program to read in all students grade from a text file. The test file has 3 column: CWID, Course Name, Grades:
1. Create an object called myGrades from class Grades. It will be create by constructor Grades( string filename)
	-The file will be opened by the constructor: Grade(string filname) and store all information 
	into a vector : vector<studentInfo>
	
	-close the file after finishing.
2. when given an campus wide ID, we use: getGPA( string cwid) function to calculate the GPA
	-when the CWID passing into the function, we declare two variables: int sumGrade=0, int count=0;
	-loop throught the studentList:
		-check for CWID :
			- if matching:
				-check the grade for this specific CWID and add grade to sumGrade.
			-everytime found matching CWID, increase count by 1
	-return sumGrade/count to get GPA for that student

#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
struct studentInfo
{
	string CWID_;
	string courseName_;
	char grade_;
	studentInfo() {
		CWID_ = "Default name";
		courseName_ = "Default name";
		grade_ = 0;
	}
	studentInfo(string id, string className, char grade) {
		CWID_ = id;
		courseName_ = className;
		grade_ = grade;
	}
};
class Grades
{
public:
	//Default constructor
	Grades() {
		numberOfStudents = 0;
	}
	//Parameter constructor
	Grades(string filename) {
		ifstream inFile;
		inFile.open(filename);
		if (!inFile.is_open())
		{
			cout << "Could not open the file.\n";
		}
		else
		{
			string studentID, courseName;
			char grade;
			while (inFile>>studentID>>courseName>>grade)
			{
				studentInfo student(studentID, courseName, grade);//construct a student object
				studentList.push_back(student);//push a student to a student list
			}
		}
		inFile.close();
	}
	double getGPA(string cwid) {
		double sumGrade = 0;
		int count = 0;
		for (int i = 0; i < studentList.size(); i++)
		{
			if (cwid==studentList[i].CWID_)
			{
				if (studentList[i].grade_=='A')
				{
					 sumGrade += 4;
				}
				if (studentList[i].grade_ == 'B')
				{
					sumGrade += 3;
				}
				if (studentList[i].grade_ == 'C')
				{
					sumGrade += 2;
				}
				if (studentList[i].grade_ == 'D')
				{
					 sumGrade += 1;
				}
				if (studentList[i].grade_ == 'F')
				{
					sumGrade += 0;
				}
				count++;
			}
		}
		return sumGrade/count;//return the GPA=sumGrade/count.
	}

private:
	vector<studentInfo> studentList;//the list contains all the student information.
	int numberOfStudents;//number of student in the file.
};

