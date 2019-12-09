#include "order.h"
//----------------------------------------------------------------------------------------//
Order::Order(Products** product_list, const int list_size, const float total_price)
{
	m_product_list = product_list;
	setListSize(list_size);
	setTotalPrice(total_price);
}
//----------------------------------------------------------------------------------------//
/*
Order::Order(const Order& other) //copy c'tor
{
	m_product_list = other.m_product_list;
	setTotalPrice(other.m_total_price);
}
//----------------------------------------------------------------------------------------//
Order::Order(Order&& other) //move c'tor
{
	m_product_list = other.m_product_list;
	other.m_product_list = nullptr;
	m_total_price = other.m_total_price;
}
*/
//----------------------------------------------------------------------------------------//
Order::~Order()
{
	delete[] m_product_list;
}
//----------------------------------------------------------------------------------------//
bool Order::setTotalPrice(const float total_price)
{
	m_total_price = total_price;
}
//----------------------------------------------------------------------------------------//
bool Order::setListSize(const int list_size)
{
	m_list_size = list_size;
}
//----------------------------------------------------------------------------------------//
 Products** Order::getProductList() const
{
	return m_product_list;
}
//----------------------------------------------------------------------------------------//
const float Order::getTotalPrice() const
{
	return m_total_price;
}
//----------------------------------------------------------------------------------------//
const int Order::getListSize() const
{
	return m_list_size;
}
//----------------------------------------------------------------------------------------//