#include "shopping_cart.h"
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart()
{
	m_total_price = 0;
}
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart(const ShoppingCart& other)
{
	*this = other;
}
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart(ShoppingCart&& other)
{
	*this = move(other);
}
//----------------------------------------------------------------------------------------//
ShoppingCart::~ShoppingCart()
{
	m_product_list.clear();
}
//----------------------------------------------------------------------------------------//
int ShoppingCart::getNumProducts()  const
{
	return m_product_list.size();
}
//----------------------------------------------------------------------------------------//
vector<Product*>& ShoppingCart::getProductList()
{
	return m_product_list;
}
//----------------------------------------------------------------------------------------//
float ShoppingCart::getTotalPrice() const
{
	return m_total_price;
}
//----------------------------------------------------------------------------------------//
void ShoppingCart::setProductList(vector<Product*> product_list)
{
	m_product_list = product_list;
}
//----------------------------------------------------------------------------------------//
void ShoppingCart::setTotalPrice(float total_price)
{
	m_total_price = total_price;
}
//----------------------------------------------------------------------------------------//
/*
Receives a new product and adds it to the buyer's shopping cart
*/
void ShoppingCart::addItemToShoppingCart(Product& product)
{
	m_product_list.push_back(&product);
}
//----------------------------------------------------------------------------------------//
/*
Receives order of a buyer from buyer menu, after buyer selected to cancel it.
Returns all items placed in order to the shopping cart.
*/
void ShoppingCart::returnItemsToShoppingCart(Order& order)
{
	for (int i = 0; i < order.getListSize(); i++)
		this->addItemToShoppingCart(*order.getProductList()[i]);

	order.getProductList().clear();
}
//----------------------------------------------------------------------------------------//
const ShoppingCart& ShoppingCart::operator=(const ShoppingCart& other)
{
	if (this != &other)
	{
		m_total_price = other.m_total_price;
		m_product_list = other.m_product_list;
	}
	return *this;
}
//----------------------------------------------------------------------------------------//
const ShoppingCart& ShoppingCart::operator=(ShoppingCart&& other)
{
	if (this != &other)
	{
		m_total_price = other.m_total_price;
		m_product_list = move(other.m_product_list);
	}

	return *this;
}
//----------------------------------------------------------------------------------------//