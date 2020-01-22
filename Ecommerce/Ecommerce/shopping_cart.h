#ifndef __SHOPPING_CART_H
#define __SHOPPING_CART_H

#include "order.h"
#include "product.h"

#include <vector>

class ShoppingCart
{
public:
	//C'tor
	ShoppingCart();
	
	//Setters
	void setProductList(vector<Product*> product_list);
	void setTotalPrice(float total_price);

	//Getters
	vector<Product*>&	getProductList();
	int					getNumProducts()	const;
	float				getTotalPrice()		const;
	
	//Methods
	void addItemToShoppingCart(Product& product);
	void returnItemsToShoppingCart(Order& order);

private:
	vector<Product*>	m_product_list;
	float				m_total_price;	
};

#endif // !__SHOPPING_CART_H
