#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "validation.h"
#include "order.h"
#include "shopping_cart.h"
#include "seller.h"

class Buyer
{
public:
	//C'tors
	Buyer() = delete;
	Buyer(const char* username, const char* password, const Address& address);

	//D'tors
	~Buyer();
	
	//Setters
	bool setUsername(const char* username);
	bool setPassword(const char* password);
	void setAddress(const Address& address);
	bool setWallet(const double funds);
	void setNumOrders(const int num_of_orders);
	void setCurrentOrder(Order* order);

	//Getters
	const char*		getUserName()			const;
	const char*		getPassword()			const;
	const Address&	getAddress()			const;
	ShoppingCart&	getShoppingCart();
    Order*			getCurrentOrder()		const;
	double			getWallet()				const;
    Order**			getOrderHistory()		const;
	int				getNumOrders()			const;

	//QUESTION 8
	void printBuyerInfo()					const;

	//QUESTION 7
	bool payOrder();
	void addOrderToHistory();

	//QUESTION 6
	void createOrder(int num_of_selected_products, int* product_index_array, float total_price);

	//QUESTION 4
	bool newFeedback(Product* product,Seller* seller, const char* description, const Date& date);

private:
	char*			m_username;
	char*			m_password;
	Address			m_address;
	double			m_wallet;
	ShoppingCart	m_shopping_cart;
	Order*			m_current_order;
	Order**			m_order_history;
	int				m_num_of_orders;

	Buyer(const Buyer& other);	//copy c'tor removed
};

#endif // __BUYER_H