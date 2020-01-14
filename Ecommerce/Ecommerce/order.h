#ifndef __ORDER_H
#define __ORDER_H

#include "validation.h"
#include "product.h"

class Order
{
public:
	//C'tors
	Order() = delete;
	Order(Product** product_list, const int list_size, const float total_price);
	Order(const Order& other);
	Order(Order&& other);

	//D'tors
	~Order();

	//Setters
	void setTotalPrice(const float total_price);
    void setListSize(const int list_size);

	//Getters
	Product**	getProductList()	const;
	int			getListSize()		const;
	float		getTotalPrice()		const;

	//Operators
	const Order& operator=(const Order& other);
	const Order& operator=(Order&& other);

private:
	Product**	m_product_list;
	int			m_list_size;
	float		m_total_price;
};

#endif // !__ORDER_H
