#ifndef __SHOPPING_CART_H
#define __SHOPPING_CART_H

#include "validation.h"
#include "product.h"

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
	bool setProductList(Product** product_list);

	//Getters
	Product** getProductList()			const;
	const int getNumProducts()           const;

	//QUESTION 5
	void addItemToShoppingCart(Product& product);

	//QUESTION 6
	void returnItemsToShoppingCart(Order& order);

private:
	int	            m_num_of_products;
	Product**		m_product_list;
};

#endif // !__SHOPPING_CART_H
