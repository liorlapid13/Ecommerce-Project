#include "shopping_cart.h"
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart()
{
	setCartSize(1);		//logical size of cart
	setNumProducts(0);	//physical size of cart
	m_product_list = new Products*[m_cart_size];
}
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart(const ShoppingCart& other)	//copy c'tor
{
	m_product_list = new Products*[other.m_cart_size];
	for (int i = 0; i < other.m_num_of_products; i++)
		m_product_list[i] = new Products(*(other.m_product_list[i]));
	setCartSize(other.m_cart_size);
	setNumProducts(other.m_num_of_products);
}
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart(ShoppingCart&& other)	//move c'tor
{
	m_product_list = other.m_product_list;
	other.m_product_list = nullptr;
	m_num_of_products = other.m_num_of_products;
	m_cart_size = other.m_cart_size;
}
//----------------------------------------------------------------------------------------//
ShoppingCart::~ShoppingCart()
{
	for (int i = 0; i < m_cart_size; i++)
		delete m_product_list[i];
	delete[] m_product_list;
}
//----------------------------------------------------------------------------------------//
bool ShoppingCart::setNumProducts(const unsigned int num_of_products)
{
	m_num_of_products = num_of_products;
}
//----------------------------------------------------------------------------------------//
bool ShoppingCart::setCartSize(const unsigned int cart_size)
{
	m_cart_size = cart_size;
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
//----------------------------------------------------------------------------------------//