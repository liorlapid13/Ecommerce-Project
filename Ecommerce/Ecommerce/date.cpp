#include "date.h"
//----------------------------------------------------------------------------------------//
Date::Date(const int day, const int month, const int year)
{
	m_year = year;
	m_month = month;
	m_day = day;
}
//----------------------------------------------------------------------------------------//
Date::Date(const Date& other)	//Copy C'tor
{
	m_year = other.m_year;
	m_month = other.m_month;
	m_day = other.m_day;
}
//----------------------------------------------------------------------------------------//
Date::~Date()
{
	//No memory allocation, why have a destructor?
}
//----------------------------------------------------------------------------------------//
bool Date::checkDate(const int day, const int month, const int year)
{
	//If invalid year/month/day 
	if (year > MAX_YEAR || year < MIN_YEAR)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	//Checks for February (leap year)
	if (month == 2)
	{
		if (isLeapYear(year))
			return (day <= 29);
		else
			return (day <= 28);
	}
 
	//Checks for April, June, September and November (months with 30 days)
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return (day <= 30);

	return true;
}
//----------------------------------------------------------------------------------------//
bool Date::isLeapYear(int year)
{
	//If year is divisable by 400 then it is a leap year
	//Else if year is divisable by 4 and not by 100 then it is a leap year
	return (((year % 4 == 0) &&	(year % 100 != 0)) || (year % 400 == 0));
}
//----------------------------------------------------------------------------------------//
const int Date::getDay() const
{
	return m_day;
}
//----------------------------------------------------------------------------------------//
const int Date::getMonth() const
{
	return m_month;
}
//----------------------------------------------------------------------------------------//
const int Date::getYear() const
{
	return m_year;
}
//----------------------------------------------------------------------------------------//