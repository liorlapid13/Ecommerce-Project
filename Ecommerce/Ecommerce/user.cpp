#include "user.h"
//----------------------------------------------------------------------------------------//
User::User(const string& username, const string& password, const Address& address) : m_address(address)
{
	setUsername(username);
	setPassword(password);
}
//----------------------------------------------------------------------------------------//
User::User(const User& other) :m_address(other.m_address)
{
	setUsername(other.m_username);
	setPassword(other.m_password);
}
//----------------------------------------------------------------------------------------//
User::User(User&& other) :m_address(move(other.m_address))
{
	m_username = move(other.m_username);
	m_password = move(other.m_password);
}
//----------------------------------------------------------------------------------------//
User::~User()
{

}
//----------------------------------------------------------------------------------------//
bool User::setUsername(const string& username)
{
	//check validity of username
	if (!Validation::usernameCheck(username))
		return false;
	else
	{
		this->m_username = username;
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool User::setPassword(const string& password)
{
	//check validity of password
	if (!Validation::passwordCheck(password))
		return false;
	else
	{
		this->m_password = password;
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
const string& User::getUserName() const
{
	return m_username;
}
//----------------------------------------------------------------------------------------//
const string& User::getPassword() const
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
		m_username = other.m_username;
		m_password = other.m_password;
		m_address = other.m_address;
	}

	return *this;
}
//----------------------------------------------------------------------------------------//
const User& User::operator=(User&& other)
{
	if (this != &other)
	{
		m_username = move(other.m_username);
		m_password = move(other.m_password);
		m_address = move(other.m_address);
	}
	
	return *this;
}
//----------------------------------------------------------------------------------------//
void User::writeUser(ofstream& out_file) const
{
	string type = typeid(*this).name() + 6;
	int user_type;
	if (type == "Buyer")
		user_type = 1;
	else if (type == "Seller")
		user_type = 2;
	else
		user_type = 3;

	out_file << user_type << "$" << m_username << "$" << m_password << "$";
	m_address.writeAddress(out_file);
}
//----------------------------------------------------------------------------------------//