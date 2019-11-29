#include "shopping_cart.h"
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart()
{
	m_product_list = nullptr;
	m_num_of_products = 0;
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
bool ShoppingCart::setNumProducts(int num_of_products)
{
	m_num_of_products = num_of_products;
}
//----------------------------------------------------------------------------------------//
bool ShoppingCart::setProductList(Products** product_list)
{
	if (m_product_list)
		delete[] m_product_list;
	m_product_list = product_list;
}
//----------------------------------------------------------------------------------------//
const int ShoppingCart::getNumProducts()  const
{
	return m_num_of_products;
}
//----------------------------------------------------------------------------------------//
Products** ShoppingCart::getProductList() const
{
	return m_product_list;
}
//----------------------------------------------------------------------------------------//
void ShoppingCart::addItemToShoppingCart(Products& product)
{
	if (!m_product_list)	//If empty shopping cart
	{
		m_num_of_products++;
		m_product_list = new Products*[m_num_of_products];
		m_product_list[0] = &product;
	}
	else
	{
		Products** temp = new Products*[m_num_of_products + 1];	//allocate memory for new product array in temporary pointer
		for (int i = 0; i < m_num_of_products; i++)				//copy each existing product to new array
			temp[i] = m_product_list[i];
		temp[m_num_of_products] = &product;						//add the new product to the new array
		m_num_of_products++;									//advance the counter for number of products
		m_product_list = temp;									//assign the new product array to the seller's store
		temp = nullptr;											//remove the temporary pointer from the store
	}
}
//----------------------------------------------------------------------------------------//