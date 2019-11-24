#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "helper.h"
#include "date.h"
#include "buyer.h"

class Feedback
{
public:
	//C'tors
	Feedback() = default;
	Feedback(const Date& date, const char* description, Buyer& buyer);
	
	//D'tor
	~Feedback();

private:
	Feedback(const Feedback& other);	//remove copy c'tor

public:
	//Setters
	bool setDescription(const char* description);

	//Getters
	inline const Date& getDate()		const;
	inline const char* getDescription() const;
	inline const Buyer* getBuyer()		const;

private:
	Date	m_date;
	char*	m_description;
	Buyer*	m_buyer;
};

#endif // !__FEEDBACK_H