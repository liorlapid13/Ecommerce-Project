#include "feedback.h"
#include "buyer.h"
//----------------------------------------------------------------------------------------//
Feedback::Feedback(const Date& date, const char* description, Buyer& buyer, Product& product) :m_date(date)
{
	m_buyer = &buyer;
	setDescription(description);
	m_product = &product;
}
//----------------------------------------------------------------------------------------//
Feedback::Feedback(const Feedback& other) :m_date(other.m_date)
{
	*this = other;
}
//----------------------------------------------------------------------------------------//
Feedback::Feedback(Feedback&& other) :m_date(other.m_date)
{
	*this = move(other);
}
//----------------------------------------------------------------------------------------//
Feedback::~Feedback()
{
	delete[]m_description;
}
//----------------------------------------------------------------------------------------//
bool Feedback::setDescription(const char* description)
{
	if (strlen(description) == 0)
	{
		cout << "Cannot enter empty description\n";
		return false;
	}
	else
	{
		delete[] m_description;
		m_description = new char[strlen(description) + 1];
		Validation::checkAllocation(m_description);
		strcpy(m_description, description);
		return true;
	}
}
//----------------------------------------------------------------------------------------//
const Date& Feedback::getDate() const
{
	return m_date;
}
//----------------------------------------------------------------------------------------//
const char* Feedback::getDescription() const
{
	return m_description;
}
//----------------------------------------------------------------------------------------//
Buyer* Feedback::getBuyer() const
{
	return m_buyer;
}
//----------------------------------------------------------------------------------------//
const Product* Feedback::getProduct() const
{
	return m_product;
}
//----------------------------------------------------------------------------------------//
ostream& operator<<(ostream& os, const Feedback& feedback)
{
	os << "Feedback date: " << feedback.m_date << "Feedback Description:\n" << feedback.m_description << endl
		<< "Buyer name: " << feedback.m_buyer->getUserName() << endl << *feedback.m_product;
	return os;
}
//----------------------------------------------------------------------------------------//
const Feedback& Feedback::operator=(const Feedback& other)
{
	if (this != &other)
	{
		m_date = other.m_date;

		delete[] m_description;
		m_description = strdup(other.m_description);

		m_buyer = other.m_buyer;
		m_product = other.m_product;
	}

	return *this;
}
//----------------------------------------------------------------------------------------//
const Feedback& Feedback::operator=(Feedback&& other)
{
	if (this != &other)
	{
		m_date = other.m_date;

		delete[] m_description;
		m_description = other.m_description;
		other.m_description = nullptr;

		m_buyer = other.m_buyer;
		m_product = other.m_product;
	}

	return *this;
}
//----------------------------------------------------------------------------------------//