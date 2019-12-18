#include "order.h"
//----------------------------------------------------------------------------------------//
Order::Order(Product** product_list, const int list_size, const float total_price)
{
	m_product_list = product_list;
	setListSize(list_size);
	setTotalPrice(total_price);
}
//----------------------------------------------------------------------------------------//
Order::~Order()
{
	delete[] m_product_list;
}
//----------------------------------------------------------------------------------------//
void Order::setTotalPrice(const float total_price)
{
	m_total_price = total_price;
}
//----------------------------------------------------------------------------------------//
void Order::setListSize(const int list_size)
{
	m_list_size = list_size;
}
//----------------------------------------------------------------------------------------//
 Product** Order::getProductList() const
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
	return m_list_size;
}
//----------------------------------------------------------------------------------------//