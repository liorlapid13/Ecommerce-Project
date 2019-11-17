#ifndef __DATE_H
#define __DATE_H

#include "helper.h"

class Date
{
public:
	static const int CURRENT_YEAR = 2019;

public:
	//C'tor
	Date(const int day, const int month, const int year);
	
public:
	//Setters
	bool setDay(const int day);
	bool setMonth(const int month);
	bool setYear(const int year);

	//Getters
	inline const int getDay() const;
	inline const int getMonth() const;
	inline const int getYear() const;

private:
	int m_day;
	int m_month;
	int m_year;
};

#endif // !__DATE_H
