#include "TAssistant.h"
#include <iostream>

using namespace std;

teachAssistant::teachAssistant()
{
	hatesTeacher = true;
	uniStudent = true;
}

bool teachAssistant::getHatesTeacher()
{
	return hatesTeacher;
}

bool  teachAssistant::getUni()
{
	return uniStudent;
}

void teachAssistant::setTeachAssist()
{
	cout << "Hates Teacher (1: True || 0: False): ";
	cin >> hatesTeacher;
	cout << "University Student (1: True || 0: False): ";
	cin >> uniStudent;
}

//Prints teaching assistant information without validation
void teachAssistant::checkTeachAssist()
{
	cout << "Hates Teacher: " << getHatesTeacher() << endl;
	cout << "University Student: " << getUni() << endl;
}

//Prints public teaching assistant information
//Prints private teaching assistant information if login successful
void teachAssistant::printTeachAssist()
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
			checkTeachAssist();
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