#pragma once
#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;


class Roster
{

private:
	int lastIndex = -1;
	const static int numOfStudents = 5;
	


public:
	Student* classRosterArray[numOfStudents];
	void parseData(string studentData);
	void add( //keep in same order as input data
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram dp
	);

	void printAll();
	void printByDegreeProgram(DegreeProgram dp);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void remove(string studentID);


	~Roster();
};