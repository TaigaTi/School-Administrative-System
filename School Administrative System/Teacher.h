#pragma once
#include "Staff.h"

//Teacher information, inherits staff attributes
class teacher : public staff
{
public:
		int numClasses;
		int numStudents;
		string subject;

		teacher();

		string getFavStudent();

		bool getAttitude();

		//Initializes teacher information
		void setTeacher();

		//Prints teacher information without validation
		void checkTeacher();

		//Prints public teacher information 
		//Prints private teacher information if user login successful
		void printTeacher();

	private:
		string favStudent;
		bool hatesKids;
};