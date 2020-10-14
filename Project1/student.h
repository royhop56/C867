#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;


class Student
{
public:
	const static int daysArraySize = 3;


private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[daysArraySize];
	DegreeProgram degreeProgram;

public:
	Student();//empty constructor

	//full constructor
	Student(
		string studentID, 
		string firstName, 
		string lastName, 
		string emailAddress, 
		int age, 
		int daysInCourse[], 
		DegreeProgram degreeProgram);

	~Student();


	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegree();


	//setters
	void setSudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegree(DegreeProgram dp);
	
	static void printHeader(); //displays a header for the data to follow

	void print(); //displays 'this' students data
};