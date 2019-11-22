#include "seller.h"
//----------------------------------------------------------------------------------------//
Seller::Seller(const char* username, const char* password, const Address& address):m_address(address)
{
	setUsername(username);
	setPassword(password);
	setNumOfFeedbacks(0);		//physical size of feedback list
	setFeedbackListSize(1);		//logical size of feedback lost
	setNumOfProducts(0);		//physical size of product list
	setProductsListSize(1);		//logical size of product list
	m_feedback_list = new Feedback[m_feedback_list_size];
	m_product_list = new Products[m_product_list_size];
}
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
}
//----------------------------------------------------------------------------------------//
Seller::~Seller()
{
	delete[] m_username;
	delete[] m_password;
	//add delete to feedback* and products*
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
bool Seller::setNumOfFeedbacks(const unsigned int numOfFeedbacks)
{
	m_num_of_feedbacks = numOfFeedbacks;
}
//----------------------------------------------------------------------------------------//
bool Seller::setFeedbackListSize(const unsigned int feedbackListSize)
{
	m_feedback_list_size = feedbackListSize;
}
//----------------------------------------------------------------------------------------//
bool Seller::setNumOfProducts(const unsigned int numOfProducts)
{
	m_num_of_products = numOfProducts;
}
//----------------------------------------------------------------------------------------//
bool Seller::setProductsListSize(const unsigned int productsListSize)
{
	m_product_list_size=productsListSize
}
//----------------------------------------------------------------------------------------//
const Products* Seller::getStore()  const
{
	return m_product_list;
}
//----------------------------------------------------------------------------------------//
const Feedback* Seller:: getFeedbacks()  const
{
	return m_feedback_list;
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