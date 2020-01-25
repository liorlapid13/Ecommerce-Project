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
	Seller(const string& username, const string& password, const Address& address);

	//D'tor
	virtual ~Seller();

	//Setters
	

	//Getters 
	vector<Feedback*>&		getFeedbackList();
	Array<Product *>&		getStore();
	int						getNumOfProducts()		const;
	int						getNumOfFeedbacks()		const;

	//Methods
	virtual void show()								const override;
	void showMe()									const;
	bool addProduct(Product& new_product);
	bool searchStore(const string& product_name);
	void addFeedback(Feedback& new_feedback);
	
	

protected:
	vector<Feedback*>	m_feedback_list;	
	Array<Product*>		m_store;

	Seller(const Seller& other);
	Seller(Seller&& other);
	const Seller& operator=(const Seller& other);
	const Seller& operator=(Seller&& other);

};

#endif // !__SELLER_H