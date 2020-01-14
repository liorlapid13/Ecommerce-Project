#ifndef __SHOPPING_CART_H
#define __SHOPPING_CART_H

#include "order.h"
#include "product.h"

class ShoppingCart
{
public:
	//C'tors
	ShoppingCart();
	ShoppingCart(const ShoppingCart& other);
	ShoppingCart(ShoppingCart&& other);
	
	//D'tors
	~ShoppingCart();
	
	//Setters
	void setNumProducts(int num_of_products);
	void setProductList(Product** product_list);
	void setTotalPrice(float total_price);

	//Getters
	Product**	getProductList()	const;
	int			getNumProducts()	const;
	float		getTotalPrice()		const;
	
	//Methods
	void addItemToShoppingCart(Product& product);
	void returnItemsToShoppingCart(Order& order);

	//Operators
	const ShoppingCart& operator=(const ShoppingCart& other);
	const ShoppingCart& operator=(ShoppingCart&& other);

private:
	int	        m_num_of_products;
	Product**	m_product_list;
	float		m_total_price;	
};

#endif // !__SHOPPING_CART_H
