#ifndef __SELLER_H
#define __SELLER_H

#include "validation.h"
#include "feedback.h"
#include "user.h"

class Buyer;

class Seller : virtual public User
{
public:
	//C'tors
	Seller() = delete;
	Seller(const char* username, const char* password, const Address& address);

	//D'tor
	virtual ~Seller();

	//Setters
	

	//Getters 
	Feedback**		getFeedbackList();
	int				getNumOfFeedbacks()		const;
	Product**		getStore();
	int				getNumOfProducts()		const;

	//Methods
	virtual void show()								const override;
	void showMe()									const;
	bool addProduct(Product& new_product);
	bool searchStore(const char* product_name)		const;
	void addFeedback(Feedback& new_feedback);
	
protected:
	Feedback**	m_feedback_list;
	int			m_num_of_feedbacks;				
	Product**	m_store;
	int			m_num_of_products;

private:
	
};

#endif // !__SELLER_H