#include "feedback.h"
//----------------------------------------------------------------------------------------//
Feedback::Feedback(const Date& date, const char* description, Buyer& buyer) :m_date(date)
{
	m_buyer = &buyer;
	setDescription(description);
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
const Buyer* Feedback::getBuyer() const
{
	return m_buyer;
}
//----------------------------------------------------------------------------------------//