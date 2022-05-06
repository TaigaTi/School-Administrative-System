#pragma once

#include "Staff.h"
#include "Login.h"

using namespace std;

//Base of staff information
//Inherited by all classifications of staff
class staff : public login
{
	public:
		string firstname;
		string lastname;

		staff();


		//Initializes general staff information
		void setStaff();

		//Prints staff information without validation
		void checkStaff();

		//Prints public staff information 
		//Prints private staff information if user login successful
		void printStaff();

		int getID();
		int getSalary();

		string getCell();
		string getAddress();

	private:
		int employeeID;
		int salary;
		string cellNum;
		string address;
};