#include "system.h"
//----------------------------------------------------------------------------------------//
System::System(const char* name)
{
	//System Name
	setName(name);

	//Buyer List
	m_buyer_list = nullptr;
	m_num_of_buyers = 0;

	//Seller List
	m_seller_list = nullptr;
	m_num_of_buyers = 0;
}
//----------------------------------------------------------------------------------------//
System::~System()
{
	int i;

	//System Name
	delete[] m_name;

	//Buyer List
	for (i = 0; i < m_num_of_buyers; i++)
		delete m_buyer_list[i];		//Delete each buyer
	delete[] m_buyer_list;			//Delete the list itself

	//Seller List
	for (i = 0; i < m_num_of_sellers; i++)
		delete m_seller_list[i];	//Delete each seller
	delete[] m_seller_list;			//Delete the list itself
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
Buyer** System::getBuyerList()
{
	return m_buyer_list;
}
//----------------------------------------------------------------------------------------//
const int System::getNumOfBuyers() const
{
	return m_num_of_buyers;
}
//----------------------------------------------------------------------------------------//
Seller** System::getSellerList()
{
	return m_seller_list;
}
//----------------------------------------------------------------------------------------//
const int System::getNumOfSellers() const
{
	return m_num_of_sellers;
}
//----------------------------------------------------------------------------------------//
void System::addBuyer(Buyer& new_buyer)
{
	if (!m_buyer_list)	//If empty buyer list
	{
		m_num_of_buyers++;
		m_buyer_list = new Buyer*[m_num_of_buyers];
		m_buyer_list[0] = &new_buyer;
	}
	else
	{
		Buyer** temp = new Buyer*[m_num_of_buyers + 1];	//allocate memory for new buyer list
		for (int i = 0; i < m_num_of_buyers; i++)		//copy each existing buyer to new list
			temp[i] = m_buyer_list[i];
		temp[m_num_of_buyers] = &new_buyer;				//add the new buyer to the new list
		m_num_of_buyers++;								//advance the counter for number of buyers
		delete[] m_buyer_list;							//delete the old buyer list
		m_buyer_list = temp;							//assign the new buyer list
		temp = nullptr;									//remove the temporary pointer
	}
}
//----------------------------------------------------------------------------------------//
void System::addSeller(Seller& new_seller)
{
	if (!m_seller_list)	//If empty seller list
	{
		m_num_of_sellers++;
		m_seller_list = new Seller*[m_num_of_sellers];
		m_seller_list[0] = &new_seller;
	}
	else
	{
		Seller** temp = new Seller*[m_num_of_sellers + 1];	//allocate memory for new seller array in temporary parameter
		for (int i = 0; i < m_num_of_sellers; i++)			//copy each existing seller to new array
			temp[i] = m_seller_list[i];
		temp[m_num_of_sellers] = &new_seller;				//add the new seller to the new array
		m_num_of_sellers++;									//advance the counter for number of sellers
		delete[] m_seller_list;								//delete the old seller list
		m_seller_list = temp;								//assign the new seller array
		temp = nullptr;										//remove the temporary pointer
	}
}
//----------------------------------------------------------------------------------------//
/*
Search for username in system user lists.
*/
bool System::searchUsername(char* username)	const
{
		//search for username in buyer list
		for (int i = 0; i < m_num_of_buyers; i++)
		{
			if (strcmp(m_buyer_list[i]->getUserName(), username) == 0)
				return false;
		}

		//search for username in seller list
		for (int i = 0; i < m_num_of_sellers; i++)
		{
			if (strcmp(m_buyer_list[i]->getUserName(), username) == 0)
				return false;
		}


	return true;
}
//----------------------------------------------------------------------------------------//
void System::printBuyerList() const
{
	cout << "Buyer List\n";
	for (int i = 0; i < m_num_of_buyers; i++)
		m_buyer_list[i]->printBuyerInfo();
}
//----------------------------------------------------------------------------------------//
void System::printSellerList() const
{
	cout << "Seller List\n";
	for (int i = 0; i < m_num_of_sellers; i++)
		m_seller_list[i]->printSellerInfo();
}
//----------------------------------------------------------------------------------------//
void System::printProductsByName(char* product_name) const
{
	for (int i = 0; i < m_num_of_products; i++)
	{
		if (strcmp(m_product_list[i]->getName(), product_name) == 0)
			m_product_list[i]->printProduct();
	}
}	
//----------------------------------------------------------------------------------------//
Seller* System::findSeller(const char* username) const
{
	for (int i = 0; i < m_num_of_sellers; i++)
	{
		if (strcmp(m_seller_list[i]->getUserName(), username) == 0)
			return m_seller_list[i];
	}

	return nullptr;	//Seller not found
}
//----------------------------------------------------------------------------------------//
Buyer* System::findBuyer(const char* username) const
{
	for (int i = 0; i < m_num_of_buyers; i++)
	{
		if (strcmp(m_buyer_list[i]->getUserName(), username) == 0)
			return m_buyer_list[i];
	}

	return nullptr;	//Buyer not found
}
//----------------------------------------------------------------------------------------//
void System::newProduct(Product& new_product)
{
	if (!m_product_list)	//If empty product list
	{
		m_num_of_sellers++;
		m_product_list = new Product*[m_num_of_products];
		m_product_list[0] = &new_product;
	}
	else
	{
		Product** temp = new Product*[m_num_of_products + 1];	//allocate memory for new product list
		for (int i = 0; i < m_num_of_products; i++)				//copy each existing product to new list
			temp[i] = m_product_list[i];
		temp[m_num_of_products] = &new_product;					//add the new product to the new list
		m_num_of_products++;									//advance the counter for number of products
		delete[] m_product_list;								//delete the old product list
		m_product_list = temp;									//assign the new product list
		temp = nullptr;											//initialize the temporary pointer
	}
}
//----------------------------------------------------------------------------------------//
/*
Receives serial number from buyer menu, searches for item with matching serial number in the system's product list
*/
Product* System::findProduct(int serial_number) const
{
	for (int i = 0; i < m_num_of_products; i++)
	{
		if (m_product_list[i]->getSerialNumber() == serial_number)
			return m_product_list[i];
	}

	return nullptr;
}
//----------------------------------------------------------------------------------------//