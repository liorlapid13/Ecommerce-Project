#include "shopping_cart.h"
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart(const Products** product_list, const int num_of_products)
{
	setProductList(product_list);
	setNumProducts(num_of_products);
}
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart(const ShoppingCart& other)	//copy c'tor
{
	setProductList(other.m_product_list);
	setNumProducts(other.m_num_of_products);
}
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart(const ShoppingCart&& other)	//move c'tor
{

}
//----------------------------------------------------------------------------------------//
bool ShoppingCart::setNumProducts(const int num_of_products)
{
	m_num_of_products = num_of_products;
}
//----------------------------------------------------------------------------------------//
bool ShoppingCart::setProductList(const Products** product_list)
{

}
//----------------------------------------------------------------------------------------//
const int ShoppingCart::getNumProducts() const
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