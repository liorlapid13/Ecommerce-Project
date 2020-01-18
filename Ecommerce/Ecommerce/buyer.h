#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "validation.h"
#include "order.h"
#include "shopping_cart.h"
#include "seller.h"

class Buyer : virtual public User
{
public:
	friend class Menu;
	friend class System;

	//C'tor
	Buyer() = delete;
	Buyer(const char* username, const char* password, const Address& address);
	

	//D'tors
	virtual ~Buyer();
	
	//Setters
	bool setWallet(const double funds);
	void setNumOrders(const int num_of_orders);
	void setCurrentOrder(Order* order);

	//Getters
	ShoppingCart&		getShoppingCart();
    Order*				getCurrentOrder()		const;
	double				getWallet()				const;
    Order**				getOrderHistory()		const;
	int					getNumOrders()			const;

	//Methods
	virtual void show()									const override;
	void showMe()										const;
	bool payOrder();
	void addOrderToHistory();
	void createOrder(int num_of_selected_products, int* product_index_array, float total_price);
	bool newFeedback(Product* product, Seller* seller, const char* description, const Date& date);

	//Operators
	bool operator>(const Buyer& other)			const;
	

protected:
	double			m_wallet;
	ShoppingCart	m_shopping_cart;
	Order*			m_current_order;
	Order**			m_order_history;
	int				m_num_of_orders;

	const Buyer& operator=(const Buyer& other);
	const Buyer& operator=(Buyer&& other);
	Buyer(const Buyer& other);
	Buyer(Buyer&& other);
};

#endif // __BUYER_H