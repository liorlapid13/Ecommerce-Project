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
	Date(const int day, const int month, const int year);
	Date(const Date& other);	//Copy C'tor

	//D'tors
	~Date();

	//Setters
	/*
	bool setDay(const int day);
	bool setMonth(const int month);
	bool setYear(const int year);
	*/
	
	//Getters
	inline const int getDay() const;
	inline const int getMonth() const;
	inline const int getYear() const;

	//Input Checks
	bool checkDate(const int day, const int month, const int year);
	bool isLeapYear(const int year);

private:
	int m_day;
	int m_month;
	int m_year;
};

#endif // !__DATE_H
