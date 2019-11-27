#include "seller.h"
//----------------------------------------------------------------------------------------//
Seller::Seller(const char* username, const char* password, const Address& address):m_address(address)
{
	setUsername(username);
	setPassword(password);
	m_num_of_feedbacks = 0;
	m_num_of_products = 0;
	m_feedback_list = nullptr;
	m_store = nullptr;
}
//----------------------------------------------------------------------------------------//
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
		delete m_store[i];
	delete[] m_store;
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
const Products** Seller::getStore() 
{
	return m_store;
}
//----------------------------------------------------------------------------------------//
const int Seller::getNumOfProducts() const
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
bool Seller::addProduct(Products& new_product)
{
	if (m_store != nullptr)
	{
		if (!searchStore(new_product.getSerialNumber()))
		{
			Products** temp = new Products*[m_num_of_products + 1];	//allocate memory for new product array in temporary pointer
			for (int i = 0; i < m_num_of_products; i++)				//copy each existing product to new array
				temp[i] = m_store[i];
			temp[m_num_of_products] = &new_product;					//add the new product to the new array
			m_num_of_products++;									//advance the counter for number of products
			m_store = temp;											//assign the new product array to the seller's store
			temp = nullptr;											//remove the temporary pointer from the store
			return true;
		}
		else
			return false;
	}
	else
	{
		m_store = new Products*[m_num_of_products + 1];			//allocate memory for new product array in temporary pointer
		m_store[m_num_of_products] = &new_product;				//add the new product to the new array
		m_num_of_products++;									//advance the counter for number of products
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Seller::searchStore(unsigned int serial_number) const
{
	for (int i = 0; i < m_num_of_products; i++)
	{
		if ((m_store[i]->getSerialNumber()) == serial_number)
			return false;
	}
	return true;
}
//----------------------------------------------------------------------------------------//
void Seller::printSellerInfo() const
{
	cout << "Username: " << m_username << endl;
	cout << "Address: ";
	m_address.printAddress();
}
//----------------------------------------------------------------------------------------//