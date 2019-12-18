#include "seller.h"
#include "buyer.h"
//----------------------------------------------------------------------------------------//
Seller::Seller(const char* username, const char* password, const Address& address) :m_address(address), m_username(nullptr), m_password(nullptr)
{
	setUsername(username);
	setPassword(password);
	m_num_of_feedbacks = 0;
	m_num_of_products = 0;
	m_feedback_list = nullptr;
	m_store = nullptr;
}
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
bool Seller::setPassword(const char* password)
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
void Seller::setAddress(const Address& address)
{

	m_address.setCity(address.getCity());
	m_address.setCountry(address.getCountry());
	m_address.setHouseNumber(address.getHouseNumber());
	m_address.setZipCode(address.getZipCode());
	m_address.setStreetName(address.getStreetName());
}
//----------------------------------------------------------------------------------------//
Product** Seller::getStore() 
{
	return m_store;
}
//----------------------------------------------------------------------------------------//
int Seller::getNumOfProducts() const
{
	return m_num_of_products;
}
//----------------------------------------------------------------------------------------//
Feedback** Seller::getFeedbackList()  
{
	return m_feedback_list;
}
int Seller::getNumOfFeedbacks() const
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
bool Seller::addProduct(Product& new_product)
{
	if (m_store != nullptr)
	{
		if (!searchStore(new_product.getName()))
		{
			Product** temp = new Product*[m_num_of_products + 1];	//allocate memory for new product list
			Validation::checkAllocation(temp);
			for (int i = 0; i < m_num_of_products; i++)				//copy each existing product to new list
				temp[i] = m_store[i];
			temp[m_num_of_products] = &new_product;					//add the new product to the new list
			m_num_of_products++;									//advance the counter for number of products
			delete[] m_store;										//delete the old store
			m_store = temp;											//assign the new product array to the seller's store
			temp = nullptr;											//remove the temporary pointer from the store
			return true;
		}
		else
			return false;
	}
	else
	{
		m_store = new Product*[m_num_of_products + 1];			//allocate memory for new product array in temporary pointer
		Validation::checkAllocation(m_store);
		m_store[m_num_of_products] = &new_product;				//add the new product to the new array
		m_num_of_products++;									//advance the counter for number of products
		return true;
	}
}
//----------------------------------------------------------------------------------------//
/*
Checks if product already exists in seller's store by name
*/
bool Seller::searchStore(const char* product_name) const
{
	for (int i = 0; i < m_num_of_products; i++)
	{
		if (strcmp(m_store[i]->getName(), product_name) == 0)
			return true;
	}
	return false;
}
//----------------------------------------------------------------------------------------//
void Seller::printSellerInfo() const
{
	cout << "Username: " << m_username << endl;
	cout << "\tAddress: ";
	m_address.printAddress();
}
//----------------------------------------------------------------------------------------//
void Seller::addFeedback(Feedback& new_feedback)
{
	if (!m_feedback_list)	//If empty feedback list
	{
		m_num_of_feedbacks++;
		m_feedback_list = new Feedback*[m_num_of_feedbacks];
		Validation::checkAllocation(m_feedback_list);
		m_feedback_list[0] = &new_feedback;
	}
	else
	{
		Feedback** temp = new Feedback*[m_num_of_feedbacks + 1];	//allocate memory for new feedback list
		Validation::checkAllocation(temp);
		for (int i = 0; i < m_num_of_feedbacks; i++)				//copy each existing feedback to new list
			temp[i] = m_feedback_list[i];
		temp[m_num_of_feedbacks] = &new_feedback;					//add the new feedback to the new list
		m_num_of_feedbacks++;										//advance the counter for number of feedbacks
		delete[] m_feedback_list;									//delete the old feedback list
		m_feedback_list = temp;										//assign the new feedback list
		temp = nullptr;												//initialize the temporary pointer
	}
}
//----------------------------------------------------------------------------------------//