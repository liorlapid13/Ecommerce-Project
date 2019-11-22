#ifndef __SELLER_H
#define __SELLER_H

#include "helper.h"
#include "address.h"
#include "seller.h"
#include "feedback.h"

class Seller
{
public:
	//C'tor
	Seller() = delete;
	Seller(const char* username, const char* password, const Address& address);
	Seller(const Seller& other);
	Seller(Seller&& other);

	//D'tor
	~Seller();

public:
	//Setters
	bool setUsername(const char* username);
	bool setPassword(const char* password);
	bool setNumOfFeedbacks(const unsigned int numOfFeedbacks);
	bool setFeedbackListSize(const unsigned int feedbackListSize);
	bool setNumOfProducts(const unsigned int numOfProducts);
	bool setProductsListSize(const unsigned int productsListSize);

	//add gets 
	inline const char* getUserName()  const;
	inline const char* getPassword()  const;
	inline const Address& getAddress() const;
	inline const Feedback* getFeedbacks()  const;
	inline const Products* getStore()  const;

private:
	char* m_username;
	char* m_password;
	Address m_address;
	Feedback* m_feedback_list;
	unsigned int m_num_of_feedbacks;			//physical size of feedback list
	unsigned int m_feedback_list_size;		//logical size of feedback list
	Products* m_product_list;
	unsigned int m_num_of_products;			//physical size of store
	unsigned int m_product_list_size;		//logical size of store
};

#endif // !__SELLER_H