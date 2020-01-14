#include "order.h"
//----------------------------------------------------------------------------------------//
Order::Order(Product** product_list, const int list_size, const float total_price)
{
	m_product_list = product_list;
	setListSize(list_size);
	setTotalPrice(total_price);
}
//----------------------------------------------------------------------------------------//
Order::Order(const Order& other)
{
	*this = other;
}
//----------------------------------------------------------------------------------------//
Order::Order(Order&& other)
{
	*this = move(other);
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
const Order& Order::operator=(const Order& other)
{
	if (this != &other)
	{
		m_list_size = other.m_list_size;
		m_total_price = other.m_total_price;

		delete[] m_product_list;
		m_product_list = new Product*[other.m_list_size];
		for (int i = 0; i < other.m_list_size; i++)
			m_product_list[i] = other.m_product_list[i];
	}
	
	return *this;
}
//----------------------------------------------------------------------------------------//
const Order& Order::operator=(Order&& other)
{
	if (this != &other)
	{
		m_list_size = other.m_list_size;
		m_total_price = other.m_total_price;

		delete[] m_product_list;
		m_product_list = other.m_product_list;
		for (int i = 0; i < other.m_list_size; i++)
		{
			m_product_list[i] = other.m_product_list[i];
			other.m_product_list[i] = nullptr;
		}
		other.m_product_list = nullptr;
		other.m_list_size = 0;
	}

	return *this;
}
//----------------------------------------------------------------------------------------//