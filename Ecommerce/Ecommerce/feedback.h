#ifndef __FEEDBACK_H
#define __FEEDBACK_H


#include "date.h"
#include "product.h"

class Buyer;

class Feedback
{
public:
	//C'tors
	Feedback() = default;
	Feedback(const Date& date, const char* description, Buyer& buyer, Product& product);
	
	//D'tor
	~Feedback();
	
	//Setters
	bool setDescription(const char* description);

	//Getters
	const Date& getDate()		 const;
	const char* getDescription() const;
	Buyer* getBuyer()			 const;
	const Product* getProduct()	 const;

private:
	Date		m_date;
	char*		m_description;
	Buyer*		m_buyer;
	Product*	m_product;

	Feedback(const Feedback& other);	//remove copy c'tor
};

#endif // !__FEEDBACK_H