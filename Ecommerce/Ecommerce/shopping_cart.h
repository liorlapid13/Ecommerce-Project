#ifndef __SHOPPING_CART_H
#define __SHOPPING_CART_H

#include "helper.h"
#include "products.h"

class ShoppingCart
{
public:
	//C'tors
	ShoppingCart(const Products** product_list, const int num_of_products);
	ShoppingCart(const ShoppingCart& other);	//copy c'tor
	ShoppingCart(const ShoppingCart&& other);	//move c'tor
	
	//D'tors
	~ShoppingCart();

	//Setters
	bool setNumProducts(const int num_of_products);
	bool setProductList(const Products** product_list);
	
	//Getters
	inline const Products** getProductList()	const;
	inline const int getNumProducts()			const;

private:
	Products**	m_product_list;
	int			m_num_of_products;
};

#endif // !__SHOPPING_CART_H
