#include "buyer.h"
//----------------------------------------------------------------------------------------//
Buyer::Buyer(const char* username, const char* password, Address& address)
{
	setUsername(username);
	setPassword(password);
	setAddress(address);
}
//----------------------------------------------------------------------------------------//
bool Buyer::setUsername(const char* username)
{
	//check validity of username
	if (!usernameCheck(username))
		return false;
	else
	{
		m_username = new char[strlen(username) + 1];
		strcpy(m_username, username);
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Buyer::setPassword(const char* password)
{
	//check validity of password
	if (!passwordCheck(password))
		return false;
	else
	{
		m_password = new char[strlen(password) + 1];
		strcpy(m_password, password);
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Buyer::setAddress(Address& address)
{
	if (!addressCheck(address))
		return false;
	else
	{
		//insert set for a valid address
	}
}
//----------------------------------------------------------------------------------------//