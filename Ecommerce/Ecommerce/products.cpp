#include "products.h"
int Products::serial_num_generator = 1000000;	//Serial number contains 7 digits (starting at 1,000,000)
//----------------------------------------------------------------------------------------//
Products::Products(const char* name, float price, Products::eCategory category, char* seller)
{
	m_serial_number = ++serial_num_generator;
	setName(name);
	setPrice(price);
	setCategory(category);
	setSeller(seller);
}
//----------------------------------------------------------------------------------------//
Products::Products(const Products& other) //copy c'tor
{
	m_serial_number = other.m_serial_number;
	setName(other.m_name);
	setPrice(other.m_price);
	setCategory(other.m_category);
	setSeller(other.m_seller);
}
//----------------------------------------------------------------------------------------//
/*
Products::Products(Products&&other) //move c'tor
{
	m_name = other.m_name;
	other.m_name = nullptr;
	m_price = other.m_price;
	m_serialNumber = other.m_serialNumber;
	m_category = other.m_category;
	m_seller = other.m_seller;
	other.m_seller = nullptr;
}
*/
//----------------------------------------------------------------------------------------//
Products::~Products()
{
	delete[] m_name;
	delete[] m_seller;
}
//----------------------------------------------------------------------------------------//
bool Products::setName(const char* name)
{
	//check if name contains symbols/spaces/invalid characters
	for (int i = 0; i < strlen(name); i++)
	{
		if (name[i] < '0' || (name[i] > 'z'
			|| (name[i] > '9' && name[i] < 'A')
			|| (name[i] > 'Z' && name[i] < 'a' || name[i] != ' ')))
		{
			cout << "Name of products can only contain alphanumeric characters (lower/uppercase letters A-Z, numbers 0-9)\n";
			return false;
		}
	}

	delete[] m_name;
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
	return true;
}
//----------------------------------------------------------------------------------------//
bool Products::setPrice(const float price)
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
bool Products::setCategory(Products::eCategory category)
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
void Products::setSeller(char* seller)
{
	m_seller = new char[strlen(seller) + 1];
	strcpy(m_seller, seller);
}
//----------------------------------------------------------------------------------------//
const char* Products::getName() const
{
	return m_name;
}
//----------------------------------------------------------------------------------------//
const char* Products::getSeller() const
{
	return m_seller;
}
//----------------------------------------------------------------------------------------//
const float Products::getPrice() const
{
	return m_price;
}
//----------------------------------------------------------------------------------------//
const int Products::getSerialNumber() const
{
	return m_serial_number;
}
//----------------------------------------------------------------------------------------//
const Products::eCategory Products::getCategory() const
{
	return m_category;
}
//----------------------------------------------------------------------------------------//
void Products::printProduct() const
{
	cout << "--------------------------------------------------\n";
	cout << "Product name: " << m_name << endl;
	cout << "Serial number: " << m_serial_number << endl;
	cout << "Price: $" << m_price << " " << endl;
	cout << "Product type: " << categoryStr[m_category] << endl;
	cout << "Seller name: " << m_seller << endl;
	cout << "--------------------------------------------------\n";
}
//----------------------------------------------------------------------------------------//