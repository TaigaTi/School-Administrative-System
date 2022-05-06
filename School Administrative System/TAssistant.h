#pragma once
#include "Teacher.h"

//Teacher assistant, inherits teacher attributes
class teachAssistant : public teacher
{
public:
	teachAssistant();

	bool getHatesTeacher();

	bool getUni();

	void setTeachAssist();

	//Prints teaching assistant information without validation
	void checkTeachAssist();

	//Prints public teaching assistant information
	//Prints private teaching assistant information if login successful
	void printTeachAssist();

private:
	bool hatesTeacher;
	bool uniStudent;
};
