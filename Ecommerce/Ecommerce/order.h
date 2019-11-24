#ifndef __ORDER_H
#define __ORDER_H

#include "helper.h"
#include "shopping_cart.h"
#include "products.h"

class Order
{
public:
	//C'tors
	Order() = delete;
	Order(Products** product_list, const int list_size, const float total_price);

	//D'tors
	~Order();

private:
	Order(const Order& other);	//copy c'tor
	Order(Order&& other);		//move c'tor

	//Setters
	/* bool setProductList(Products** product_list, const int list_size); */
	bool setTotalPrice(const float total_price);
	bool setListSize(const int list_size);

	//Getters
	inline const Products** getProductList()	const;
	inline const int getListSize()				const;
	inline const float getTotalPrice()			const;

private:
	Products**	m_product_list;
	int			m_list_size;
	float		m_total_price;
};

#endif // !__ORDER_H
