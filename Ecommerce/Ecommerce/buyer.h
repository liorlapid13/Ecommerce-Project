#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "validation.h"
#include "address.h"
#include "products.h"
#include "shopping_cart.h"
#include "order.h"

class Buyer
{
public:
	//C'tors
	Buyer() = delete;
	Buyer(const char* username, const char* password, const Address& address);

	//D'tors
	~Buyer();

private:
	Buyer(const Buyer& other);	//copy c'tor
	Buyer(Buyer&& other);		//move c'tor

public:
	//Setters
	bool setUsername(const char* username);
	bool setPassword(const char* password);
	void setAddress(const Address& address);
	bool setWallet(const double funds);
	void setNumOrders(const int num_of_orders);
	void setCurrentOrder(Order* order);

	//Getters
	inline const char* getUserName()		const;
	inline const char* getPassword()		const;
	inline const Address& getAddress()		const;
	inline ShoppingCart& getShoppingCart();
	inline Order* getCurrentOrder()			const;
	inline double getWallet()				const;
	inline Order** getOrderHistory()		const;
	inline int getNumOrders()				const;

	//QUESTION 8
	void printBuyerInfo()					const;

	//QUESTION 7
	bool payOrder();
	void addOrderToHistory();

	//QUESTION 6
	void createOrder(int num_of_selected_products, int* product_index_array, float total_price);

	//QUESTION 4
	bool newFeedback(Products* product,Seller* seller, const char* description, const Date& date);

private:
	char*			m_username;
	char*			m_password;
	Address			m_address;
	double			m_wallet;
	ShoppingCart	m_shopping_cart;
	Order*			m_current_order;
	Order**			m_order_history;
	int				m_num_of_orders;
};

#endif // __BUYER_H