#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "helper.h"
#include "date.h"
#include "buyer.h"

class Feedback
{
public:
	//C'tor
	Feedback() = delete;
	Feedback(const Date& date, const char* description, Buyer& buyer);

public:
	//Setters
	bool setDescription(const char* description);
	/*
	bool setDate(const Date& date);
	bool setBuyer(Buyer& buyer);
	*/

	//Getters
	inline const Date getDate() const;
	inline const char* getDescription() const;
	inline const Buyer* getBuyer() const;
	
private:
	Date	m_date;
	char*	m_description;
	Buyer*	m_buyer;
};

#endif // !__FEEDBACK_H
