#include "roster.h"



int main()
{
	const string studentData[] =

	{   "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Roy,Hopkins,Rhopk39@wgu.edu,28,20,25,28,SOFTWARE"

	};

	const int numStudents = 5;
	Roster classRoster;

	cout << "Scripting and Programming - Applications" << std::endl;
	cout << "_________Created by Roy Hopkins_________" << std::endl;
	cout << "__________Language Used: C++____________" << std::endl;
	cout << "_________Student ID: 001417848__________" << std::endl;

	for (int i = 0; i < numStudents; i++)classRoster.parseData(studentData[i]);
	cout << "Current Student Roster:  " << std::endl;
	classRoster.printAll();
	cout << endl << endl;

	cout << "Invalid emails listed below: " << endl;

	classRoster.printInvalidEmails();
	cout << endl;



	
	cout << " Average days in course for student:  " << endl;
	for (int i = 0; i < numStudents; i++)
	{
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	cout << endl;



	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");


	system("pause");

	return 0;
}