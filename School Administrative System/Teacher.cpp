#include "Teacher.h"
#include <iostream>

using namespace std;

teacher::teacher()
{
	numClasses = 2;
	numStudents = 60;
	subject = "Math";
	favStudent = "Mary";
	hatesKids = true;
}

string teacher::getFavStudent()
{
	return favStudent;
}

bool teacher::getAttitude()
{
	return hatesKids;
}

//Initializes teacher information
void teacher::setTeacher()
{
	cout << "Number of Classes: ";
	cin >> numClasses;
	cout << "Number of Students: ";
	cin >> numStudents;
	cout << "Subject: ";
	cin >> subject;
	cout << "Fave Student: ";
	cin >> favStudent;
	cout << "Hates Kids (1: True || 0: False): ";
	cin >> hatesKids;
}

//Prints teacher information without validation
void teacher::checkTeacher()
{
	cout << "Number of Classes: " << numClasses << endl;
	cout << "Number of Students: " << numStudents << endl;
	cout << "Subject: " << subject << endl;
	cout << "Favourite Student: " << getFavStudent() << endl;
	cout << "Hates Kids: " << getAttitude() << endl;
}

//Prints public teacher information 
//Prints private teacher information if user login successful
void teacher::printTeacher()
{
	int loginTries = 3;
	string userID;
	string password;
	bool loginSuccess;

	cout << "Employee Information" << endl;
	cout << "--------------------" << endl;
	cout << "First Name: " << firstname << endl;
	cout << "Last Name: " << lastname << endl;
	cout << "Number of Classes: " << numClasses << endl;
	cout << "Number of Students: " << numStudents << endl;
	cout << "Subject: " << subject << endl;
	cout << endl;

	do
	{
		cout << "Private Information Restricted. Please Enter User Login." << endl;
		cout << "User ID: ";
		cin >> userID;
		cout << "Password: ";
		cin >> password;
		cout << endl << endl;

		if (userID == getUserID() && password == getPassword())
		{
			loginSuccess = true;
			cout << "Login Successful" << endl;
			cout << "----------------" << endl;
			checkStaff();
			checkTeacher();
		}
		else
		{
			loginTries--;
			loginSuccess = false;
			if (loginTries == 0)
			{
				cout << "Too Many Invalid Attempts. Access Denied.";
			}
			else
			{
				cout << "Invalid login. Please try again." << endl << endl;
			}
		}
	} while (loginSuccess == false && loginTries > 0);
}