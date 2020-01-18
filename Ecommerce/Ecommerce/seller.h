#ifndef __SELLER_H
#define __SELLER_H

#include "validation.h"
#include "feedback.h"
#include "user.h"
#include "array.h"

class Buyer;

class Seller : virtual public User
{
public:
	friend class System;

	//C'tors
	Seller() = delete;
	Seller(const char* username, const char* password, const Address& address);
	

	//D'tor
	virtual ~Seller();

	//Setters
	

	//Getters 
	Feedback**				getFeedbackList();
	int						getNumOfFeedbacks()		const;
	Array<Product *>&		getStore();
	int						getNumOfProducts()		const;

	//Methods
	virtual void show()								const override;
	void showMe()									const;
	bool addProduct(Product& new_product);
	bool searchStore(const char* product_name)		const;
	void addFeedback(Feedback& new_feedback);
	
	

protected:
	Feedback**		m_feedback_list;
	int				m_num_of_feedbacks;		
	Array<Product*> m_store;

	Seller(const Seller& other);
	Seller(Seller&& other);
	//Operators
	const Seller& operator=(const Seller& other);
	const Seller& operator=(Seller&& other);

};

#endif // !__SELLER_H