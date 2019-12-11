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

	//D'tors
	~Order();

public:
	//Setters
	void setTotalPrice(const float total_price);
    void setListSize(const int list_size);

	//Getters
	Product** getProductList()	const;
	const int getListSize()		const;
	const float getTotalPrice()	const;

private:
	Product**	m_product_list;
	int			m_list_size;
	float		m_total_price;

	Order(const Order& other);	//copy c'tor
};

#endif // !__ORDER_H
