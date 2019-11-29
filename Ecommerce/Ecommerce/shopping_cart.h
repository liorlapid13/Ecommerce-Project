#ifndef __SHOPPING_CART_H
#define __SHOPPING_CART_H

#include "helper.h"
#include "products.h"

class ShoppingCart
{
public:
	//C'tors
	ShoppingCart();								//default c'tor
	
	//D'tors
	~ShoppingCart();

private:
	ShoppingCart(const ShoppingCart& other);	//copy c'tor
	ShoppingCart(ShoppingCart&& other);			//move c'tor
	
public:
	//Setters
	bool setNumProducts(int num_of_products);
	bool setProductList(Products** product_list);

	//Getters
	inline Products** getProductList()			const;
	inline const int getNumProducts()           const;

	//QUESTION 5
	void addItemToShoppingCart(Products& product);

private:
	int	            m_num_of_products;
	Products**		m_product_list;
};

#endif // !__SHOPPING_CART_H
