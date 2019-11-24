#include "date.h"
//----------------------------------------------------------------------------------------//
Date::Date(const unsigned int day, const unsigned int month, const unsigned int year)
{
	setYear(year);
	setMonth(month);
	setDay(day, month, year);
}
//----------------------------------------------------------------------------------------//
Date::~Date()
{
	//No memory allocation, why have a destructor?
}
//----------------------------------------------------------------------------------------//
bool Date::setYear(const unsigned int year)
{
	//Check if year is in valid range
	if (year > MAX_YEAR || year < MIN_YEAR)
		return false;
	
	m_year = year;
	return true;
}
//----------------------------------------------------------------------------------------//
bool Date::setMonth(const unsigned int month)
{
	//Check if month is in valid range
	if (month < 1 || month > 12)
		return false;

	m_month = month;
	return true;
}
//----------------------------------------------------------------------------------------//
bool Date::setDay(const unsigned int day, const unsigned int month, const unsigned int year)
{
	//Check if day is in valid range
	if (day < 1 || day > 31)
		return false;

	//Checks for February (leap year)
	if (month == 2)
	{
		if (isLeapYear(year))
		{
			if (day > 29)
				return false;
		}
		else if (day > 28)
			return false;
	}

	//Checks for April, June, September and November (months with 30 days)
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;

	m_day = day;
	return true;
}
//----------------------------------------------------------------------------------------//
bool Date::isLeapYear(unsigned int year)
{
	//If year is divisable by 400 then it is a leap year
	//Else if year is divisable by 4 and not by 100 then it is a leap year
	return (((year % 4 == 0) &&	(year % 100 != 0)) || (year % 400 == 0));
}
//----------------------------------------------------------------------------------------//
const unsigned int Date::getDay() const
{
	return m_day;
}
//----------------------------------------------------------------------------------------//
const unsigned int Date::getMonth() const
{
	return m_month;
}
//----------------------------------------------------------------------------------------//
const unsigned int Date::getYear() const
{
	return m_year;
}
//----------------------------------------------------------------------------------------//