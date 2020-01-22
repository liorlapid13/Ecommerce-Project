#include "feedback.h"
#include "buyer.h"
//----------------------------------------------------------------------------------------//
Feedback::Feedback(const Date& date, const string& description, Buyer& buyer, Product& product) :m_date(date)
{
	setDescription(description);
	m_buyer = &buyer;
	m_product = &product;
}
//----------------------------------------------------------------------------------------//
bool Feedback::setDescription(const string& description)
{
	if (description.length() == 0)
	{
		cout << "Cannot enter empty description\n";
		return false;
	}
	else
	{
		this->m_description = description;
		return true;
	}
}
//----------------------------------------------------------------------------------------//
const Date& Feedback::getDate() const
{
	return m_date;
}
//----------------------------------------------------------------------------------------//
const string& Feedback::getDescription() const
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