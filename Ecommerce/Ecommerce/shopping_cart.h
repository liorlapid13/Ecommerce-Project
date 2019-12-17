#ifndef __SHOPPING_CART_H
#define __SHOPPING_CART_H

#include "order.h"
#include "product.h"

class ShoppingCart
{
public:
	//C'tors
	ShoppingCart();
	
	//D'tors
	~ShoppingCart();
	
	//Setters
	void setNumProducts(int num_of_products);
	void setProductList(Product** product_list);

	//Getters
	Product**	getProductList()	const;
	int			getNumProducts()	const;

	//QUESTION 5
	void addItemToShoppingCart(Product& product);

	//QUESTION 6
	void returnItemsToShoppingCart(Order& order);

private:
	int	        m_num_of_products;
	Product**	m_product_list;

	ShoppingCart(const ShoppingCart& other); //copy c'tor
};

#endif // !__SHOPPING_CART_H
