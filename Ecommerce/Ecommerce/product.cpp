#include "product.h"
const char* Product::categoryStr[] = { "Kids","Electrical","Clothing","Office" };
int Product::serial_num_generator = 1000;	//Serial number starting at 1,000
//----------------------------------------------------------------------------------------//
Product::Product(const char* name, float price, Product::eCategory category, const char* seller_name)
{
	m_serial_number = ++serial_num_generator;
	setName(name);
	setPrice(price);
	setCategory(category);
	setSellerName(seller_name);
}
//----------------------------------------------------------------------------------------//
Product::Product(const Product& other) //copy c'tor
{
	m_serial_number = other.m_serial_number;
	setName(other.m_name);
	setPrice(other.m_price);
	setCategory(other.m_category);
	setSellerName(other.m_seller);
}
//----------------------------------------------------------------------------------------//
Product::Product(Product&&other) //move c'tor
{
	m_name = other.m_name;
	other.m_name = nullptr;
	m_price = other.m_price;
	m_serial_number = other.m_serial_number;
	m_category = other.m_category;
	m_seller = other.m_seller;
	other.m_seller = nullptr;
}

//----------------------------------------------------------------------------------------//
Product::~Product()
{
	delete[] m_name;
	delete[] m_seller;
}
//----------------------------------------------------------------------------------------//
bool Product::setName(const char* name)
{
	//check if name contains symbols/spaces/invalid characters
	for (int i = 0; i < strlen(name); i++)
	{
		if ((name[i] < '0' || name[i] > 'z' 
		|| (name[i] > '9' && name[i] < 'A')
		|| (name[i] > 'Z' && name[i] < 'a') )&& ( name[i] != ' '))
		{ 
			cout << "Name of products can only contain alphanumeric characters (lower/uppercase letters A-Z, numbers 0-9)\n";
			return false;
		}
	}

	delete[] m_name;
	m_name = new char[strlen(name) + 1];
	Validation::checkAllocation(m_name);
	strcpy(m_name, name);
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
void Product::setSellerName(const char* seller_name)
{
	m_seller = new char[strlen(seller_name) + 1];
	Validation::checkAllocation(m_seller);
	strcpy(m_seller, seller_name);
}
//----------------------------------------------------------------------------------------//
const char* Product::getName() const
{
	return m_name;
}
//----------------------------------------------------------------------------------------//
const char* Product::getSeller() const
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
}