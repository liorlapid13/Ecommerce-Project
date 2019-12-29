#include "shopping_cart.h"
//----------------------------------------------------------------------------------------//
ShoppingCart::ShoppingCart()
{
	m_product_list = nullptr;
	m_num_of_products = 0;
	m_total_price = 0;
}
//----------------------------------------------------------------------------------------//
ShoppingCart::~ShoppingCart()
{
	delete[] m_product_list;
}
//----------------------------------------------------------------------------------------//
int ShoppingCart::getNumProducts()  const
{
	return m_num_of_products;
}
//----------------------------------------------------------------------------------------//
Product** ShoppingCart::getProductList() const
{
	return m_product_list;
}
//----------------------------------------------------------------------------------------//
float ShoppingCart::getTotalPrice() const
{
	return m_total_price;
}
//----------------------------------------------------------------------------------------//
void ShoppingCart::setProductList(Product** product_list)
{
	if (m_product_list)
		delete[] m_product_list;
	m_product_list = product_list;
}
//----------------------------------------------------------------------------------------//
void ShoppingCart::setNumProducts(int num_of_products)
{
	m_num_of_products = num_of_products;
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
	if (!m_product_list)	//If empty shopping cart
	{
		m_num_of_products++;
		m_product_list = new Product*[m_num_of_products];
		Validation::checkAllocation(m_product_list);
		m_product_list[0] = &product;
		m_total_price += product.getPrice();
	}
	else
	{
		Product** temp = new Product*[m_num_of_products + 1];	//allocate memory for new product list
		Validation::checkAllocation(temp);
		for (int i = 0; i < m_num_of_products; i++)				//copy each existing product to new list
			temp[i] = m_product_list[i];
		temp[m_num_of_products] = &product;						//add the new product to the new list
		m_num_of_products++;									//advance the counter for number of products
		m_total_price += product.getPrice();					//update total price of shopping cart
		delete[] m_product_list;								//delete the old product list
		m_product_list = temp;									//assign the new product list
		temp = nullptr;											//remove the temporary pointer
	}
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

	delete[] order.getProductList();
	order.setListSize(0);
}
//----------------------------------------------------------------------------------------//