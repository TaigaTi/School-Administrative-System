#include <iostream>
#include "Login.h"
#include "Staff.h"
#include "Teacher.h"
#include "TAssistant.h"

using namespace std;

int main()
{
	int staffType;
	int options;
	bool valid;
	bool newTask;
	string ans;

	staff general;
	teacher teacher;
	teachAssistant assist;
	login users[10];

	do 
	{
		cout << "What would you like to do?" << endl << endl;
		cout << "1: Create Employee Record" << endl;
		cout << "2: View Employee Record" << endl;
		cout << "3: Add Users" << endl;
		cout << endl;
		cout << "Task: ";
		cin >> options;

		//Create employee records
		if (options == 1)
		{
			do
			{
				cout << "What type of staff member would you like to add?" << endl << endl;
				cout << "1: General Staff" << endl << "2: Teacher" << endl << "3: Teacher's Assistant" << endl << endl;
				cout << "Staff Type: ";
				cin >> staffType;
				cout << endl;

				//Allows user to enter general staff information and verify if accurate
				if (staffType == 1)
				{
					do
					{
						valid = false;

						general.setStaff();

						cout << endl << endl;
						cout << "Please Verify Employee Information" << endl;
						cout << "----------------------------------" << endl;


						general.checkStaff();

						cout << endl << endl;

						cout << "Information Valid?" << endl << "1: Yes" << endl << "0: No" << endl;
						cin >> valid;
						cout << endl << endl;

						if (valid == false)
						{
							cout << "Please Re-Enter Employee Information." << endl << endl;
						}
					} while (valid == false);

					cout << "New Employee Added" << endl << endl;
				}
				//Allows user to enter teacher information and verify if accurate
				else if (staffType == 2)
				{
					do
					{
						valid = false;

						teacher.setStaff();
						teacher.setTeacher();

						cout << endl << endl;
						cout << "Please Verify Employee Information" << endl;
						cout << "----------------------------------" << endl;


						teacher.checkStaff();
						teacher.checkTeacher();

						cout << endl << endl;


						cout << "Information Valid?" << endl << "1: Yes" << endl << "0: No" << endl;
						cin >> valid;
						cout << endl << endl;

						if (valid == false)
						{
							cout << "Please Re-Enter Employee Information." << endl << endl;
						}
					} while (valid == false);

					cout << "New Employee Added" << endl << endl;
				}
				//Allows user to enter teaching assistant information and verify if accurate
				else if (staffType == 3)
				{
					do
					{
						valid = false;

						assist.setStaff();
						assist.setTeacher();
						assist.setTeachAssist();

						cout << endl << endl;
						cout << "Please Verify Employee Information" << endl;
						cout << "----------------------------------" << endl;

						assist.checkStaff();
						assist.checkTeacher();
						assist.checkTeachAssist();

						cout << endl << endl;


						cout << "Information Valid?" << endl << "1: Yes" << endl << "0: No" << endl;
						cin >> valid;
						cout << endl << endl;

						if (valid == false)
						{
							cout << "Please Re-Enter Employee Information." << endl << endl;
						}
					} while (valid == false);

					cout << "New Employee Added" << endl << endl;
				}
				else
				{
					cout << "Invalid Staff Type. Please try again later." << endl << endl;
				}

				cout << "Would you like to add another staff member? (y/n)" << endl;
				cin >> ans;

			} while (ans == "y" || ans == "Y");

			cout << endl << endl;
		}
		//View employee records
		else if (options == 2)
		{
			string fName;
			string lName;

			//Allows user to search for employee information
			cout << "Which employee would you like to view?" << endl;
			cin >> fName >> lName;
			cout << endl << endl;
			if (general.firstname == fName && general.lastname == lName)
			{
				general.printStaff();
			}
			else if (teacher.firstname == fName && teacher.lastname == lName)
			{
				teacher.printTeacher();
			}
			else if (assist.firstname == fName && assist.lastname == lName)
			{
				assist.printTeachAssist();
			}
			else
			{
				cout << "No Employee Record Found." << endl << endl;
			}

			cout << endl << endl;
		}
		//Add new users to the system
		else if (options == 3)
		{
			int i;
			string admin;
			string password;
			bool userTaken;

			cout << "Admin login required to add user." << endl;
			cout << "Username: ";
			cin >> admin;
			cout << "Password: ";
			cin >> password;
			cout << endl;

			users[0].getUserID() = "Admin";
			users[0].getPassword() = "Passw0rd";

			if (users[0].getUserID() == admin && users[0].getPassword() == password)
			{
				for (i = 1; i < 10; i++)
				{
					if (users[i].getUserID() != "")
					{
						userTaken = false;
					}
					else
					{
						userTaken = true;
					}

					if (userTaken == false)
					{
						string newUser;
						string newPassword;
						string passwordCheck;

						cout << "New User: ";
						cin >> newUser;
						cout << "Password: ";
						cin >> newPassword;
						cout << "Confirm Password: ";
						cin >> passwordCheck;

						do
						{
							if (passwordCheck == newPassword)
							{
								userTaken = true;
								users[i].getUserID() = newUser;
								users[i].getPassword() = newPassword;

								cout << endl;
								cout << "User Added." << endl << endl;

								i = 10;
							}
							else
							{
								cout << endl;
								cout << "Invalid Password Match." << endl;
								cout << "Please Re-Enter Information." << endl << endl;
								userTaken = false;
							}
						} while (userTaken = false);
					}
					else if(userTaken == true)
					{
						i++;
					}
				}
			}
			else
			{
				cout << "Access Denied" << endl << endl;
			}
		}

		cout << "Would you like to perform another task?" << endl;
		cout  << "1: Yes" << endl << "0: No" << endl;
		cin >> newTask;
		cout << endl << endl;
	} while (newTask == true);
}