#ifndef __DATE_H
#define __DATE_H

#include "helper.h"

class Date
{
public:
	static const int MAX_YEAR = 2019;
	static const int MIN_YEAR = 2019;

public:
	//C'tors
	Date() = delete;
	Date(const unsigned int day, const unsigned int month, const unsigned int year);
	Date(const Date& other);	//Copy C'tor

	//D'tors
	~Date();

	//Setters
	bool setDay(const unsigned int day, const unsigned int month, const unsigned int year);
	bool setMonth(const unsigned int month);
	bool setYear(const unsigned int year);
		
	//Getters
	inline const unsigned int getDay() const;
	inline const unsigned int getMonth() const;
	inline const unsigned int getYear() const;

	//Input Checks
	bool isLeapYear(const unsigned int year);

private:
	unsigned int m_day;
	unsigned int m_month;
	unsigned int m_year;
};

#endif // !__DATE_H
