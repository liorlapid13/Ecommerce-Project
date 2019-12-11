#ifndef __SELLER_H
#define __SELLER_H

#include "helper.h"
#include "address.h"
#include "seller.h"
#include "feedback.h"
#include "product.h"

class Seller
{
public:
	//C'tor
	Seller() = delete;
	Seller(const char* username, const char* password, const Address& address);

	//D'tor
	~Seller();

private:
	Seller(const Seller& other);
	Seller(Seller&& other);

public:
	//Setters
	bool setUsername(const char* username);
	bool setPassword(const char* password);
	void setAddress(const Address& address);

	//Getters 
	const char* getUserName()				const;
	const char* getPassword()				const;
	const Address& getAddress()				const;
	const Feedback** getFeedbackList();
	const int getNumOfFeedbacks()			const;
	const Product** getStore();
	const int getNumOfProducts()			const;

	//QUESTION 3
	bool addProduct(Product& new_product);
	bool searchStore(unsigned int serial_number)	const;

	//QUESTION 4
	void addFeedback(Feedback& new_feedback);

	//QUESTION 9
	void printSellerInfo()							const;

private:
	char* m_username;
	char* m_password;
	Address m_address;
	Feedback** m_feedback_list;
	int m_num_of_feedbacks;				
	Product** m_store;
	int m_num_of_products;			
};

#endif // !__SELLER_H