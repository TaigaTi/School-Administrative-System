#pragma once
#include <string>

using namespace std;

//Login details inherited by all staff
class login
{
	public:
		login();

		//Access user id & password
		string getUserID();
		string getPassword();

	private:
		string userID;
		string password;
};