#include "date.h"
//----------------------------------------------------------------------------------------//
Date::Date(const int day, const int month, const int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}
//----------------------------------------------------------------------------------------//
bool Date::setDay(const int day)
{
	if (day < 1 || day > 30)
	{
		cout << "Invalid day entered\n";
		return false;
	}
	else
	{
		m_day = day;
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Date::setMonth(const int month)
{	
	if (month < 1 || month > 12)
	{
		cout << "Invalid month entered\n";
		return false;
	}
	else
	{
		m_month = month;
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Date::setYear(const int year)
{
	if (year < CURRENT_YEAR)
	{
		cout << "Invalid year entered\n";
		return false;
	}
	else
	{
		m_year = year;
		return true;
	}
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