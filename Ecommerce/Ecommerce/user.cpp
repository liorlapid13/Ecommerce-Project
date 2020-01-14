#include "user.h"
//----------------------------------------------------------------------------------------//
User::User(const char* username, const char* password, const Address& address) : m_address(address), m_username(nullptr), m_password(nullptr)
{
	setUsername(username);
	setPassword(password);
}
//----------------------------------------------------------------------------------------//
User::User(const User& other) :m_address(other.m_address), m_username(nullptr), m_password(nullptr)
{
	setUsername(other.m_username);
	setPassword(other.m_username);
}
//----------------------------------------------------------------------------------------//
User::User(User&& other) :m_address(move(other.m_address))
{
	m_username = strdup(other.m_username);
	other.m_username = nullptr;

	m_password = strdup(other.m_password);
	other.m_password = nullptr;
}
//----------------------------------------------------------------------------------------//
User::~User()
{
	delete[] m_username;
	delete[] m_password;
}
//----------------------------------------------------------------------------------------//
bool User::setUsername(const char* username)
{
	//check validity of username
	if (!Validation::usernameCheck(username))
		return false;
	else
	{
		delete[] m_username;
		m_username = new char[strlen(username) + 1];
		Validation::checkAllocation(m_username);
		strcpy(m_username, username);
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool User::setPassword(const char* password)
{
	//check validity of password
	if (!Validation::passwordCheck(password))
		return false;
	else
	{
		delete[] m_password;
		m_password = new char[strlen(password) + 1];
		Validation::checkAllocation(m_password);
		strcpy(m_password, password);
		return true;
	}
}
//----------------------------------------------------------------------------------------//
void User::setAddress(const Address& address)
{

	m_address.setCity(address.getCity());
	m_address.setCountry(address.getCountry());
	m_address.setHouseNumber(address.getHouseNumber());
	m_address.setZipCode(address.getZipCode());
	m_address.setStreetName(address.getStreetName());
}
//----------------------------------------------------------------------------------------//
const char* User::getUserName() const
{
	return m_username;
}
//----------------------------------------------------------------------------------------//
const char* User::getPassword() const
{
	return m_password;
}
//----------------------------------------------------------------------------------------//
const Address& User::getAddress() const
{
	return m_address;
}
//----------------------------------------------------------------------------------------//
void User::show() const
{
	cout << "Username: " << m_username << endl;
	cout << "\tAddress: ";
	m_address.printAddress();
}
//----------------------------------------------------------------------------------------//
const User& User::operator=(const User& other)
{
	if (this != &other)
	{
		delete[] m_username;
		m_username = strdup(other.m_username);

		delete[] m_password;
		m_password = strdup(other.m_password);

		m_address = other.m_address;
	}

	return *this;
}
//----------------------------------------------------------------------------------------//
const User& User::operator=(User&& other)
{
	if (this != &other)
	{
		delete[] m_username;
		m_username = other.m_username;
		other.m_username = nullptr;

		delete[] m_password;
		m_password = other.m_password;
		other.m_password = nullptr;

		m_address = move(other.m_address);
	}
	
	return *this;
}
//----------------------------------------------------------------------------------------//