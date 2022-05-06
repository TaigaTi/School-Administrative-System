#include "Login.h"

login::login()
{
	userID = "Admin";
	password = "Passw0rd";
}

//Access user id & password
string login::getUserID()
{
	return userID;
}
string login::getPassword()
{
	return password;
}