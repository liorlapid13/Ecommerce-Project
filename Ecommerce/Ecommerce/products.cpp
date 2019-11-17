#include "products.h"

Products::Products(const char* name, float price, int serialNumber, Products::eCategory category)
{
	setName(name);
	setPrice(price);
	setSerialNumber(serialNumber);
	setCategory(category);
}
Products::~Products()
{
	delete[] m_name;
}


//----------------------------------------------------------------------------------------//
bool Products::setName(const char* name)
{
	//check if name contains symbols/spaces/invalid characters
	for (int i = 0; i < strlen(name); i++)
	{
		if (name[i] < '0' || (name[i] > 'z'
			|| (name[i] > '9' && name[i] < 'A')
			|| (name[i] > 'Z' && name[i] < 'a' || name[i] != ' ')
			))
		{
			cout << "Name of products can only contain alphanumeric characters (lower/uppercase letters A-Z, numbers 0-9)\n";
			return false;
		}
	}
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
	return true;

}
//----------------------------------------------------------------------------------------//
void Products::setPrice(float price)
{
	m_price = price;
}
//----------------------------------------------------------------------------------------//
void Products::setSerialNumber(int serialNumber)
{
	m_serialNumber = serialNumber;
}
//----------------------------------------------------------------------------------------//
bool Products::setCategory(Products::eCategory category)
{
	if (category >= NUM_OF_CATEGORIES || category < 0)
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
const char* Products::getName()     const
{
	return m_name;
}
//----------------------------------------------------------------------------------------//
float Products::getPrice()          const
{
	return m_price;
}
//----------------------------------------------------------------------------------------//
int Products::getSerialNumber()       const
{
	return m_serialNumber;
}
//----------------------------------------------------------------------------------------//
Products::eCategory Products::getCategory()     const
{
	return m_category;
}
//----------------------------------------------------------------------------------------//