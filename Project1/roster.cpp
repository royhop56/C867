#include "roster.h"


void Roster::parseData(string studentData)
{
	DegreeProgram dp = DegreeProgram::SOFTWARE;
	if (studentData.at(2) == 'C') dp = DegreeProgram::SECURITY;
	else if (studentData.at(2) == 'T') dp = DegreeProgram::NETWORK;
	else if (studentData.at(2) == 'F') dp = DegreeProgram::SOFTWARE;


	int rhs = studentData.find(",");
	string sID = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int day1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int day2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int day3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string degree = studentData.substr(lhs, rhs - lhs);

	if (degree[2] == 'F') dp = DegreeProgram::SOFTWARE;
	if (degree[2] == 'T') dp = DegreeProgram::NETWORK;
	if (degree[2] == 'C') dp = DegreeProgram::SECURITY;
	


	add(sID, firstName, lastName, emailAddress, age, day1, day2, day3, dp);
}

	void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
	{
		int daysInCourseArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
		classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram);
	}

	void Roster::printAll() 
	{
		Student::printHeader();
		for (int i = 0; i <= Roster::lastIndex; i++) 
		{
			cout << classRosterArray[i]->getStudentID(); cout << '\t';
			cout << classRosterArray[i]->getFirstName(); cout << '\t';
			cout << classRosterArray[i]->getLastName(); cout << '\t';
			cout << classRosterArray[i]->getEmailAddress(); cout << '\t';
			cout << classRosterArray[i]->getAge(); cout << '\t';
			cout << classRosterArray[i]->getDaysInCourse()[0]; cout << '\t';
			cout << classRosterArray[i]->getDaysInCourse()[1]; cout << '\t';
			cout << classRosterArray[i]->getDaysInCourse()[2]; cout << '\t';
			cout << degreeProgramString[classRosterArray[i]->getDegree()] << std::endl;
		}

	}

	void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
	{
		Student::printHeader();

		for (int i = 0; i <= Roster::lastIndex; i++)
		{
			if (Roster::classRosterArray[i]->getDegree() == degreeProgram) classRosterArray[i]->print();
		}
		cout << endl;
	}

	void Roster::printInvalidEmails() 
	{
		for (int i = 0; i <= lastIndex; i++)
		{
			string email = classRosterArray[i]->getEmailAddress();
			if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos))
			{
				cout << email << ": " << classRosterArray[i]->getFirstName() << classRosterArray[i]->getLastName() << endl;
			}
		}
		cout << endl;
	}

	void Roster::printAverageDaysInCourse(string studentID)
	{
		int sum = 0;
		for (int i = 0; i <= lastIndex; i++)
		{
			if (this->classRosterArray[i]->getStudentID() == studentID)
			{
				for (int j = 0; j < Student::daysArraySize; j++)
				{
					sum += classRosterArray[i]->getDaysInCourse()[j];
				}
			}
		}
		sum = sum / Student::daysArraySize;
		cout << "Average days in course: " << sum;
		cout << std::endl;
	}

	void Roster::remove(string studentID)
	{
		bool success = false;
			for (int i = 0; i <= Roster::lastIndex; i++)
			{
				if (classRosterArray[i]->getStudentID() == studentID)
				{
					success = true;
					if (i < numOfStudents - 1)
					{
						Student* tempvariable = classRosterArray[i];
						classRosterArray[i] = classRosterArray[numOfStudents - 1];
						classRosterArray[numOfStudents - 1] = tempvariable;
					}
					Roster::lastIndex--;
				}
			}

		if (success)
		{
			cout << studentID << "has been removed from the roster." << std::endl << std::endl;
			this->printAll();
		}
		else cout << studentID << "not found." << std::endl << std::endl;
	}

	Roster::~Roster() 
	{
		cout << "THE ROSTER IS BEING DESTRYOED!!!:" << std::endl << std::endl;
		for (int i = 0; i < numOfStudents; i++)
		{
			cout << "destryoing student *" << i + 1 << std::endl;
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}

