#ifndef __ORDER_H
#define __ORDER_H

#include "validation.h"
#include "product.h"


class Order
{
public:
	//C'tors
	Order() = delete;
	Order(vector<Product*> product_list, const float total_price);

	//Setters
	void setTotalPrice(const float total_price);

	//Getters
	vector<Product*>&	getProductList();
	int					getListSize()		const;
	float				getTotalPrice()		const;

private:
	vector<Product*>	m_product_list;
	float				m_total_price;
};

#endif // !__ORDER_H
