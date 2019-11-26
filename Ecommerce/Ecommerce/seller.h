#ifndef __SELLER_H
#define __SELLER_H

#include "helper.h"
#include "address.h"
#include "seller.h"
#include "feedback.h"
#include "products.h"

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
	bool setNumOfFeedbacks(const unsigned int numOfFeedbacks);
	bool setNumOfProducts(const unsigned int numOfProducts);
	void setAddress(const Address& address);

	//add gets 
	inline const char* getUserName()		   const;
	inline const char* getPassword()		   const;
	inline const Address& getAddress()		   const;
	inline const Feedback** getFeedbackList();
	inline const int getNumOfFeedbacks()	   const;
	inline const Products** getStore();
	inline const int getNumOfProducts()		   const;

private:
	char* m_username;
	char* m_password;
	Address m_address;
	Feedback** m_feedback_list;
	int m_num_of_feedbacks;				
	Products** m_product_list;
	int m_num_of_products;			
};

#endif // !__SELLER_H