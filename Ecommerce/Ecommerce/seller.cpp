#include "seller.h"
#include "buyer.h"
//----------------------------------------------------------------------------------------//
Seller::Seller(const char* username, const char* password, const Address& address) :User(username, password, address)
{
	m_num_of_feedbacks = 0;
	m_feedback_list = nullptr;
}
//----------------------------------------------------------------------------------------//
Seller::Seller(const Seller& other) :User(other), m_store(other.m_store)
{
	m_num_of_feedbacks = other.m_num_of_feedbacks;
	if (other.m_num_of_feedbacks != 0)
	{
		m_feedback_list = new Feedback*[other.m_num_of_feedbacks];
		for (int i = 0; i < other.m_num_of_feedbacks; i++)
			m_feedback_list[i] = new Feedback(*other.m_feedback_list[i]);
	}
	else
		m_feedback_list = nullptr;
}
//----------------------------------------------------------------------------------------//
Seller::Seller(Seller&& other) : User(move(other)), m_store(move(other.m_store))
{
	m_num_of_feedbacks = other.m_num_of_feedbacks;

	m_feedback_list = other.m_feedback_list;
	other.m_feedback_list = nullptr;
}
//----------------------------------------------------------------------------------------//
Seller::~Seller()
{
	int i;

	for (i = 0; i < m_num_of_feedbacks; i++)
		delete m_feedback_list[i];
	delete[] m_feedback_list;
}
//----------------------------------------------------------------------------------------//
Array<Product *>& Seller::getStore() 
{
	return m_store;
}
//----------------------------------------------------------------------------------------//
int Seller::getNumOfProducts() const
{
	return m_store.m_size;
}
//----------------------------------------------------------------------------------------//
Feedback** Seller::getFeedbackList()  
{
	return m_feedback_list;
}
//----------------------------------------------------------------------------------------//
int Seller::getNumOfFeedbacks() const
{
	return m_num_of_feedbacks;
}
//----------------------------------------------------------------------------------------//
/*
Receives a new product and adds it to the seller's store
*/
bool Seller::addProduct(Product& new_product)
{
		if (!searchStore(new_product.getName()))
		{
			m_store += &new_product;
			return true;
		}
		else
			return false;
}
//----------------------------------------------------------------------------------------//
/*
Checks if product already exists in seller's store by name
*/
bool Seller::searchStore(const char* product_name) const
{
	for (int i = 0; i < m_store.m_size; i++)
	{
		if (strcmp(m_store.m_arr[i]->getName(), product_name) == 0)
			return true;
	}
	return false;
}
//----------------------------------------------------------------------------------------//
void Seller::show() const
{
	User::show();
	showMe();
}
//----------------------------------------------------------------------------------------//
void Seller::showMe() const
{
	cout << "\tNumber of products: " << m_store.m_size << endl;
	cout << "\tNumber of feedbacks: " << m_num_of_feedbacks << endl;
}
//----------------------------------------------------------------------------------------//
/*
Receives a new feedback and adds it to the seller's feedback list
*/
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
const Seller& Seller::operator=(const Seller& other)
{
	if (this != &other)
	{
		User::operator=(other);
		m_store = other.m_store;
		
		for (int i = 0; i < m_num_of_feedbacks; i++)
			delete m_feedback_list[i];
		delete[] m_feedback_list;

		m_num_of_feedbacks = other.m_num_of_feedbacks;

		if (other.m_num_of_feedbacks != 0)
		{
			m_feedback_list = new Feedback*[other.m_num_of_feedbacks];
			for (int i = 0; i < other.m_num_of_feedbacks; i++)
				m_feedback_list[i] = new Feedback(*other.m_feedback_list[i]);
		}
		else
			m_feedback_list = nullptr;

	}

	return *this;
}
//----------------------------------------------------------------------------------------//
const Seller& Seller::operator=(Seller&& other)
{
	if (this != &other)
	{
		User::operator=(move(other));
		m_store = move(other.m_store);

		for (int i = 0; i < m_num_of_feedbacks; i++)
			delete m_feedback_list[i];
		delete[] m_feedback_list;

		m_num_of_feedbacks = other.m_num_of_feedbacks;

		m_feedback_list = other.m_feedback_list;
		other.m_feedback_list = nullptr;
	}

	return *this;
}
//----------------------------------------------------------------------------------------//