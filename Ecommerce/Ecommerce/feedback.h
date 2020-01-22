#ifndef __FEEDBACK_H
#define __FEEDBACK_H

#include "date.h"
#include "product.h"

class Buyer;

class Feedback
{
public:
	//C'tors
	Feedback() = delete;
	Feedback(const Date& date, const string& description, Buyer& buyer, Product& product);

	//Setters
	bool setDescription(const string& description);

	//Getters
	const Date&		getDate()			const;
	const string&	getDescription()	const;
	Buyer*			getBuyer()			const;
	const Product*	getProduct()		const;

	//Operators
	friend ostream& operator<<(ostream& os, const Feedback& feedback);

private:
	Date		m_date;
	string		m_description;
	Buyer*		m_buyer;
	Product*	m_product;
};

#endif // !__FEEDBACK_H