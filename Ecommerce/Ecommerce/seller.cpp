#include "seller.h"
#include "buyer.h"
//----------------------------------------------------------------------------------------//
Seller::Seller(const string& username, const string& password, const Address& address) 
	:User(username, password, address)
{
	
}
//----------------------------------------------------------------------------------------//
Seller::Seller(const Seller& other) :User(other), m_store(other.m_store)
{
	for (auto s : other.m_feedback_list)
		m_feedback_list.push_back(new Feedback(*s));
}
//----------------------------------------------------------------------------------------//
Seller::Seller(Seller&& other) : User(move(other)), m_store(move(other.m_store))
{
	m_feedback_list = move(other.m_feedback_list);
	other.m_feedback_list.clear();
}
//----------------------------------------------------------------------------------------//
Seller::~Seller()
{
	vector<Feedback*>::iterator itr = m_feedback_list.begin();
	vector<Feedback*>::iterator itrEnd = m_feedback_list.end();

	for (; itr != itrEnd; ++itr)
		delete *itr;
}
//----------------------------------------------------------------------------------------//
Array<Product*>& Seller::getStore()
{
	return m_store;
}
//----------------------------------------------------------------------------------------//
int Seller::getNumOfProducts() const
{
	return m_store.getSize();
}
//----------------------------------------------------------------------------------------//
vector<Feedback*>& Seller::getFeedbackList()  
{
	return m_feedback_list;
}
//----------------------------------------------------------------------------------------//
int Seller::getNumOfFeedbacks() const
{
	return m_feedback_list.size();
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
bool Seller::searchStore(const string& product_name)
{
	for (int i = 0; i < m_store.getSize(); i++)
	{
		if (m_store[i]->getName() == product_name)
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
	cout << "\tNumber of products: " << m_store.getSize() << endl;
	cout << "\tNumber of feedbacks: " << m_feedback_list.size() << endl;
}
//----------------------------------------------------------------------------------------//
/*
Receives a new feedback and adds it to the seller's feedback list
*/
void Seller::addFeedback(Feedback& new_feedback)
{
	m_feedback_list.push_back(&new_feedback);
}
//----------------------------------------------------------------------------------------//
const Seller& Seller::operator=(const Seller& other)
{
	if (this != &other)
	{
		User::operator=(other);
		m_store = other.m_store;
		
		vector<Feedback*>::iterator itr = m_feedback_list.begin();
		vector<Feedback*>::iterator itrEnd = m_feedback_list.end();

		for (; itr != itrEnd; ++itr)
			delete *itr;

		for (auto s : other.m_feedback_list)
			m_feedback_list.push_back(new Feedback(*s));
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

		vector<Feedback*>::iterator itr = m_feedback_list.begin();
		vector<Feedback*>::iterator itrEnd = m_feedback_list.end();

		for (; itr != itrEnd; ++itr)
			delete *itr;

		m_feedback_list = move(other.m_feedback_list);
		other.m_feedback_list.clear();
	}

	return *this;
}
//----------------------------------------------------------------------------------------//