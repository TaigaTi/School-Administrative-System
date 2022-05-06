#include "Staff.h"
#include <iostream>

staff::staff()
{
	firstname = "John";
	lastname = "Doe";
	employeeID = 284693;
	salary = 60000;
	cellNum = "555-5555";
	address = "Outside Somewhere";
}


//Initializes general staff information
void staff::setStaff()
{
	cout << "First Name: ";
	cin >> firstname;
	cout << "Last Name: ";
	cin >> lastname;
	cout << "Employee ID: ";
	cin >> employeeID;
	cout << "Salary: ";
	cin >> salary;
	cout << "Cell Number: ";
	cin >> cellNum;
	cout << "Address: ";
	cin >> address;

}

//Prints staff information without validation
void staff::checkStaff()
{
	cout << "First Name: " << firstname << endl;
	cout << "Last Name: " << lastname << endl;
	cout << "Employee ID: " << getID() << endl;
	cout << "Salary: " << getSalary() << endl;
	cout << "Cell Number: " << getCell() << endl;
	cout << "Address: " << getAddress() << endl;
}

//Prints public staff information 
//Prints private staff information if user login successful
void staff::printStaff()
{
	int loginTries = 3;
	string userID;
	string password;
	bool loginSuccess;

	cout << "Employee Information" << endl;
	cout << "--------------------" << endl;
	cout << "First Name: " << firstname << endl;
	cout << "Last Name: " << lastname << endl;
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

int staff::getID()
{
	return employeeID;
}

int staff::getSalary()
{
	return salary;
}

string staff::getCell()
{
	return cellNum;
}

string staff::getAddress()
{
	return address;
}