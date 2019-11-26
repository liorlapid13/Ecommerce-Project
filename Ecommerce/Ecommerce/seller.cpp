#include "seller.h"
//----------------------------------------------------------------------------------------//
Seller::Seller(const char* username, const char* password, const Address& address):m_address(address)
{
	setUsername(username);
	setPassword(password);
	setNumOfFeedbacks(0);		
	setNumOfProducts(0);		
	m_feedback_list = nullptr;
	m_product_list = nullptr;
}
/*
Seller::Seller(const Seller& other):m_address(other.m_address)
{
	setUsername(other.m_username);
	setPassword(other.m_password);
	m_feedback_list = other.m_feedback_list;
	m_product_list = other.m_product_list;
}
Seller::Seller(Seller&& other):m_address(other.m_address)
{
	m_username = other.m_username;
	other.m_username = nullptr;
	m_password = other.m_password;
	other.m_password = nullptr;
	m_feedback_list = other.m_feedback_list;
	other.m_feedback_list = nullptr;
	m_product_list = other.m_product_list;
	other.m_product_list = nullptr;
}*/
//----------------------------------------------------------------------------------------//
Seller::~Seller()
{
	int i;

	delete[] m_username;
	delete[] m_password;
	for ( i = 0; i < m_num_of_products; i++)
		delete m_product_list[i];
	delete[] m_product_list;
	for (i = 0; i < m_num_of_feedbacks; i++)
		delete m_feedback_list[i];
	delete[] m_feedback_list;
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
void Seller::setAddress(const Address& address)
{

	m_address.setCity(address.getCity());
	m_address.setCountry(address.getCountry());
	m_address.setHouseNumber(address.getHouseNumber());
	m_address.setZipCode(address.getZipCode());
	m_address.setStreetName(address.getStreetName());
}
//----------------------------------------------------------------------------------------//
bool Seller::setNumOfFeedbacks(const unsigned int numOfFeedbacks)
{
	m_num_of_feedbacks = numOfFeedbacks;
}
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//
bool Seller::setNumOfProducts(const unsigned int numOfProducts)
{
	m_num_of_products = numOfProducts;
}
//----------------------------------------------------------------------------------------//
const Products** Seller::getStore() 
{
	return m_product_list;
}
//----------------------------------------------------------------------------------------//
const int Seller::getNumOfProducts()		 const
{
	return m_num_of_products;
}
//----------------------------------------------------------------------------------------//
const Feedback** Seller::getFeedbackList()  
{
	return m_feedback_list;
}
const int Seller::getNumOfFeedbacks() const
{
	return m_num_of_feedbacks;
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
const Address& Seller::getAddress() const
{
	return m_address;
}
//----------------------------------------------------------------------------------------//