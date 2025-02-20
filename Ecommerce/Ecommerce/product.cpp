#include "product.h"
const string Product::categoryStr[] = { "Kids","Electrical","Clothing","Office" };
int Product::serial_num_generator = 1000;	//Serial number starting at 1,000
//----------------------------------------------------------------------------------------//
Product::Product(const string& name, float price, Product::eCategory category, const string& seller_name)
{
	m_serial_number = ++serial_num_generator;
	setName(name);
	setPrice(price);
	setCategory(category);
	setSellerName(seller_name);
}
//----------------------------------------------------------------------------------------//
bool Product::setName(const string &name)
{
	string::const_iterator itr = name.begin();
	string::const_iterator itrEnd = name.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr < '0' || *itr > 'z' || (*itr > '9' && *itr < 'A')	|| (*itr > 'Z' && *itr < 'a')) 
			&& (*itr != ' '))
		{
			cout << "Name of products can only contain alphanumeric characters (lower/uppercase letters A-Z, numbers 0-9)\n";
			return false;
		}
	}

	this->m_name = name;
	return true;
}
//----------------------------------------------------------------------------------------//
bool Product::setPrice(const float price)
{
	if (price <= 0)
	{
		cout << "The price of the products should be a positive number\n";
		return false;
	}
	else
	{
		m_price = price;
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Product::setCategory(Product::eCategory category)
{
	if (category > NUM_OF_CATEGORIES - 1 || category < 0)
	{
		cout << "Category number should be between 0-3\n";
		return false;
	}
	else
	{
		m_category = category;
		return true;
	}
}
//----------------------------------------------------------------------------------------//
void Product::setSellerName(const string& seller_name)
{
	this->m_seller = seller_name;
}
//----------------------------------------------------------------------------------------//
const string& Product::getName() const
{
	return m_name;
}
//----------------------------------------------------------------------------------------//
const string& Product::getSeller() const
{
	return m_seller;
}
//----------------------------------------------------------------------------------------//
float Product::getPrice() const
{
	return m_price;
}
//----------------------------------------------------------------------------------------//
int Product::getSerialNumber() const
{
	return m_serial_number;
}
//----------------------------------------------------------------------------------------//
Product::eCategory Product::getCategory() const
{
	return m_category;
}
//----------------------------------------------------------------------------------------//
void Product::printProduct() const
{
	cout << *this;
}
//----------------------------------------------------------------------------------------//
ostream& operator<<(ostream& os, const Product& product)
{
	os << "Product name: " << product.m_name << endl 
		<< "Serial number: " << product.m_serial_number << endl
		<< "Price: $" << product.m_price << endl 
		<< "Product type: " << product.categoryStr[product.m_category] << endl
		<< "Seller name: " << product.m_seller << endl 
		<< "--------------------------------------------------\n";

	return os;
}
//----------------------------------------------------------------------------------------//