#include "seller.h"
//----------------------------------------------------------------------------------------//
Seller::Seller(const char* username, const char* password, const Address& address)
{
	setUsername(username);
	setPassword(password);
	setAddress(address);
}
//----------------------------------------------------------------------------------------//
Seller::~Seller()
{
	delete[] m_username;
	delete[] m_password;
	//delete address?
}
//----------------------------------------------------------------------------------------//
bool Seller::setUsername(const char* username)
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
bool Seller::setPassword(const char* password)
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
bool Seller::setAddress(const Address& address)
{
	m_address = address;
}
//----------------------------------------------------------------------------------------//
const char* Seller::getUserName() const
{
	return m_username;
}
//----------------------------------------------------------------------------------------//
const char* Seller::getPassword() const
{
	return m_password;
}
//----------------------------------------------------------------------------------------//
const Address Seller::getAddress() const
{
	return m_address;
}
//----------------------------------------------------------------------------------------//