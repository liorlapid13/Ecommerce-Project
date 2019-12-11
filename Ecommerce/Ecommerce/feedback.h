#ifndef __FEEDBACK_H
#define __FEEDBACK_H


#include "date.h"
#include "buyer.h"

class Feedback
{
public:
	//C'tors
	Feedback() = default;
	Feedback(const Date& date, const char* description, Buyer& buyer, Product& product);
	
	//D'tor
	~Feedback();

private:
	Feedback(const Feedback& other);	//remove copy c'tor

public:
	//Setters
	bool setDescription(const char* description);

	//Getters
	const Date& getDate()		const;
	const char* getDescription() const;
	const Buyer* getBuyer()		const;
	const Product* getProduct()	const;

private:
	Date		m_date;
	char*		m_description;
	Buyer*		m_buyer;
	Product*	m_product;
};

#endif // !__FEEDBACK_H