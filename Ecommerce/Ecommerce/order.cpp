#include "order.h"
//----------------------------------------------------------------------------------------//
Order::Order(vector<Product*> product_list, const float total_price)
{
	m_product_list = product_list;
	setTotalPrice(total_price);
}
//----------------------------------------------------------------------------------------//
Order::~Order()
{
	m_product_list.clear();
}
//----------------------------------------------------------------------------------------//
void Order::setTotalPrice(const float total_price)
{
	m_total_price = total_price;
}
//----------------------------------------------------------------------------------------//
 vector<Product*>& Order::getProductList() 
{
	return m_product_list;
}
//----------------------------------------------------------------------------------------//
float Order::getTotalPrice() const
{
	return m_total_price;
}
//----------------------------------------------------------------------------------------//
int Order::getListSize() const
{
	return m_product_list.size();
}
//----------------------------------------------------------------------------------------//