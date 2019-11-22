#ifndef __SHOPPING_CART_H
#define __SHOPPING_CART_H

#include "helper.h"
#include "products.h"

class ShoppingCart
{
public:
	//C'tors
	ShoppingCart();								//default c'tor
	ShoppingCart(const ShoppingCart& other);	//copy c'tor
	ShoppingCart(ShoppingCart&& other);			//move c'tor
	
	//D'tors
	~ShoppingCart();

	//Setters
	bool setNumProducts(const unsigned int num_of_products);
	bool setCartSize(const unsigned int cart_size);
	
	//Getters
	inline const Products** getProductList()	const;
	inline const unsigned int getNumProducts()	const;

private:
	unsigned int	m_num_of_products;	//physical size of shopping cart
	unsigned int	m_cart_size;		//logical size of shopping cart
	Products**		m_product_list;
};

#endif // !__SHOPPING_CART_H
