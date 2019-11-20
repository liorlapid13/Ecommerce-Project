#include "buyer.h"
//----------------------------------------------------------------------------------------//
Buyer::Buyer(const char* username, const char* password, const Address& address):m_address(address)
{
	setUsername(username);
	setPassword(password);
	m_shoppingCart = new Products*[];
}
//----------------------------------------------------------------------------------------//
Buyer::Buyer(const Buyer& other, int numOfItemsInCart) :m_address(other.m_address)
{
	setUsername(other.m_username);
	setPassword(other.m_password);
	for (int i = 0; i < numOfItemsInCart; i++)
	{
		m_shoppingCart[i] = new Products(*(other.m_shoppingCart[i]));
	}
}
//----------------------------------------------------------------------------------------//
Buyer::Buyer(Buyer&&other) :m_address(other.m_address)
{
	m_username = other.m_username;
	other.m_username = nullptr;
	m_password = other.m_password;
	other.m_password = nullptr;

	m_shoppingCart = other.m_shoppingCart;
	other.m_shoppingCart = nullptr;
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
inline Products** Buyer::getShoppingCart() const
{
	return m_shoppingCart;
}
//----------------------------------------------------------------------------------------//
const char* Buyer::getUserName() const
{
	return m_username;
}
//----------------------------------------------------------------------------------------//
const char* Buyer::getPassword() const
{
	return m_password;
}
//----------------------------------------------------------------------------------------//
const Address Buyer::getAddress() const
{
	return m_address;
}
//----------------------------------------------------------------------------------------//