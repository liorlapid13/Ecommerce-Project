#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "helper.h"
#include "address.h"
#include "products.h"
#include "shopping_cart.h"

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

	//Getters
	inline const char* getUserName()				const;
	inline const char* getPassword()				const;
	inline const Address& getAddress()				const;
	inline const ShoppingCart& getShoppingCart()	const;

private:
	char*			m_username;
	char*			m_password;
	Address			m_address;
	ShoppingCart	m_shoppingCart;
};

#endif // __BUYER_H