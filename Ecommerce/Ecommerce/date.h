#ifndef __DATE_H
#define __DATE_H

#include "validation.h"

class Date
{
public:
	//Constants
	static const int MAX_YEAR = 2020;
	static const int MIN_YEAR = 2019;

	//C'tors
	Date() = delete;
	Date(const unsigned int day, const unsigned int month, const unsigned int year);

	//D'tors
	~Date();

	//Setters
	bool setDay(const unsigned int day, const unsigned int month, const unsigned int year);
	bool setMonth(const unsigned int month);
	bool setYear(const unsigned int year);
		
	//Getters
	unsigned int getDay()	const;
	unsigned int getMonth() const;
	unsigned int getYear()	const;

	//Input Checks
	bool isLeapYear(const unsigned int year) const;

private:
	unsigned int m_day;
	unsigned int m_month;
	unsigned int m_year;
};

#endif // !__DATE_H
