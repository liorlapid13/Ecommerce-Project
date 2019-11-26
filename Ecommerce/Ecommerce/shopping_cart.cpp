#include "shopping_cart.h"
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart()
{
	setNumProducts(0);
	m_product_list = nullptr;
}
//----------------------------------------------------------------------------------------//
/*
ShoppingCart::ShoppingCart(const ShoppingCart& other)	//copy c'tor
{
	m_product_list = new Products*[other.m_num_of_products];
	for (int i = 0; i < other.m_num_of_products; i++)
		m_product_list[i] = new Products(*(other.m_product_list[i]));
	setNumProducts(other.m_num_of_products);
}
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart(ShoppingCart&& other)	//move c'tor
{
	m_product_list = other.m_product_list;
	other.m_product_list = nullptr;
	m_num_of_products = other.m_num_of_products;
}
*/
//----------------------------------------------------------------------------------------//
ShoppingCart::~ShoppingCart()
{
	delete[] m_product_list;
}
//----------------------------------------------------------------------------------------//
bool ShoppingCart::setNumProducts(const unsigned int num_of_products)
{
	m_num_of_products = num_of_products;
}
//----------------------------------------------------------------------------------------//
const unsigned int ShoppingCart::getNumProducts() const
{
	return m_num_of_products;
}
//----------------------------------------------------------------------------------------//
const Products** ShoppingCart::getProductList() const
{
	return m_product_list;
}
//----------------------------------------------------------------------------------------//
void ShoppingCart::addItemToShoppingCart(Products& product)
{
	if (!m_product_list) //Empty shopping cart
	{
		m_num_of_products++;
		m_product_list = new Products*[m_num_of_products];
		m_product_list[0] = &product;
	}
	else //Shopping cart not empty
	{
		Products** temp = m_product_list;
		m_product_list = new Products*[m_num_of_products + 1];
		for (int i = 0; i < m_num_of_products; i++)
			m_product_list[i] = temp[i];
		m_product_list[m_num_of_products] = &product;
		m_num_of_products++;
		delete[] temp;
	}
}
//----------------------------------------------------------------------------------------//