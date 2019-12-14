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
Feedback::~Feedback()
{
	delete[]m_description;
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