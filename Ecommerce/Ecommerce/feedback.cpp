#include "feedback.h"
//----------------------------------------------------------------------------------------//
Feedback::Feedback(Date date, char* description, Buyer* buyer)
{
	setDate(date);
	setDescription(description);
	setBuyer(buyer);
}
//----------------------------------------------------------------------------------------//
bool Feedback::setDate(const Date& date)
{
	
}
//----------------------------------------------------------------------------------------//
bool Feedback::setDescription(const char* description)
{
	
}
//----------------------------------------------------------------------------------------//
bool Feedback::setBuyer(const Buyer* buyer)
{

}
//----------------------------------------------------------------------------------------//
const Date Feedback::getDate() const
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