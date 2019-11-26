#include "system.h"
//----------------------------------------------------------------------------------------//
System::System(const char* name)
{
	setName(name);
	m_buyers_array = nullptr;
	m_num_of_buyers = 0;
	m_sellers_array = nullptr;
	m_num_of_buyers = 0;
}
//----------------------------------------------------------------------------------------//
System::~System()
{
	int i;
	delete[] m_name;
	for (i = 0; i < m_num_of_buyers; i++)
		delete m_buyers_array[i];
	delete[] m_buyers_array;
	for (i = 0; i < m_num_of_sellers; i++)
		delete m_sellers_array[i];
	delete[] m_sellers_array;
}
//----------------------------------------------------------------------------------------//
bool System::setName(const char* name)
{
	//check if name contains symbols/spaces/invalid characters
	for (int i = 0; i < strlen(name); i++)
	{
		if (name[i] < '0' || (name[i] > 'z'
			|| (name[i] > '9' && name[i] < 'A')
			|| (name[i] > 'Z' && name[i] < 'a' || name[i] != ' ')))
		{
			cout << "Name of system can only contain alphanumeric characters (lower/uppercase letters A-Z, numbers 0-9)\n";
			return false;
		}
	}

	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
	return true;
}
//----------------------------------------------------------------------------------------//
const char* System::getName() const
{
	return m_name;
}
//----------------------------------------------------------------------------------------//
const  Buyer** System::getBuyersArray()
{
	return m_buyers_array;
}
//----------------------------------------------------------------------------------------//
const int System::getNumOfBuyers() const
{
	return m_num_of_buyers;
}
//----------------------------------------------------------------------------------------//
const Seller** System::getSellersArray()
{
	return m_sellers_array;
}
//----------------------------------------------------------------------------------------//
const int System::getNumOfSellers() const
{
	return m_num_of_sellers;
}