#ifndef __SELLER_H
#define __SELLER_H

#include "validation.h"
#include "address.h"
#include "feedback.h"

class Buyer;

class Seller
{
public:
	//C'tors
	Seller() = delete;
	Seller(const char* username, const char* password, const Address& address);

	//D'tor
	~Seller();

	//Setters
	bool setUsername(const char* username);
	bool setPassword(const char* password);
	void setAddress(const Address& address);

	//Getters 
	const char*		getUserName()			const;
	const char*		getPassword()			const;
	const Address&	getAddress()			const;
	Feedback**		getFeedbackList();
	int				getNumOfFeedbacks()		const;
	Product**		getStore();
	int				getNumOfProducts()		const;

	//QUESTION 3
	bool addProduct(Product& new_product);
	bool searchStore(const char* product_name)	const;

	//QUESTION 4
	void addFeedback(Feedback& new_feedback);

	//QUESTION 9
	void printSellerInfo() const;
	
	//TESTS
	void printFeedbackList();

private:
	char*		m_username;
	char*		m_password;
	Address		m_address;
	Feedback**	m_feedback_list;
	int			m_num_of_feedbacks;				
	Product**	m_store;
	int			m_num_of_products;

	Seller(const Seller& other); //copy c'tor
};

#endif // !__SELLER_H