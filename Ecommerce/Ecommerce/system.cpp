#include "system.h"
//----------------------------------------------------------------------------------------//
System::System(const char* name)
{
	//System Name
	setName(name);

	//User List
	m_user_list = nullptr;
	m_num_of_users = 0;
}
//----------------------------------------------------------------------------------------//
System::~System()
{
	int i;

	//System Name
	delete[] m_name;

	//User List
	for (i = 0; i < m_num_of_users; i++)
		delete m_user_list[i];		//Delete each user
	delete[] m_user_list;			//Delete list

	//Product List
	delete[] m_product_list;		//Delete list (products deleted in sellers' d'tor)
}
//----------------------------------------------------------------------------------------//
void System::setName(const char* name)
{
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
}
//----------------------------------------------------------------------------------------//
const char* System::getName() const
{
	return m_name;
}
//----------------------------------------------------------------------------------------//
User** System::getUserList()
{
	return m_user_list;
}
//----------------------------------------------------------------------------------------//
int System::getNumOfUsers() const
{
	return m_num_of_users;
}
//----------------------------------------------------------------------------------------//
Product** System::getProductList()
{
	return m_product_list;
}
//----------------------------------------------------------------------------------------//
int System::getNumOfProducts() const
{
	return m_num_of_products;
}
//----------------------------------------------------------------------------------------//
/*
Receives a new user and adds it to the system user list
*/
void System::addUser(User& new_user)
{
	if (!m_user_list)	//If empty user list
	{
		m_num_of_users++;
		m_user_list = new User*[m_num_of_users];
		Validation::checkAllocation(m_user_list);
		m_user_list[0] = &new_user;
	}
	else
	{
		User** temp = new User*[m_num_of_users + 1];	//allocate memory for new user list
		Validation::checkAllocation(temp);
		for (int i = 0; i < m_num_of_users; i++)		//copy each existing user to new list
			temp[i] = m_user_list[i];
		temp[m_num_of_users] = &new_user;				//add the new user to the new list
		m_num_of_users++;								//advance the counter for number of users
		delete[] m_user_list;							//delete the old user list
		m_user_list = temp;								//assign the new user list
		temp = nullptr;									//remove the temporary pointer
	}
}
//----------------------------------------------------------------------------------------//
/*
Search for username in system user list.
*/
bool System::searchUsername(const char* username) const
{
		//search for username in user list
		for (int i = 0; i < m_num_of_users; i++)
		{
			if (strcmp(m_user_list[i]->getUserName(), username) == 0)
				return false;
		}

	return true;
}
//----------------------------------------------------------------------------------------//
/*
Print list of all buyers in system
*/
void System::printBuyerList() const
{
	cout << "\t _________________\n";
	cout << "\t|                 |\n";
	cout << "\t|   Buyer List    |\n";
	cout << "\t|_________________|\n\n";

	cout << "--------------------------------------------------\n";

	int counter = 0;

	for (int i = 0; i < m_num_of_users; i++)
	{
		if (strcmp(typeid(*m_user_list[i]).name(), typeid(Buyer).name()) == 0)
		{
			cout << ++counter << "\t";
			m_user_list[i]->show();
			cout << "--------------------------------------------------\n";
		}
	}
}
//----------------------------------------------------------------------------------------//
/*Print list of all sellers in system
*/
void System::printSellerList() const
{
	cout << "\t __________________\n";
	cout << "\t|                  |\n";
	cout << "\t|   Seller List    |\n";
	cout << "\t|__________________|\n\n";

	cout << "--------------------------------------------------\n";

	int counter = 0;

	for (int i = 0; i < m_num_of_users; i++)
	{
		if (strcmp(typeid(*m_user_list[i]).name(), typeid(Seller).name()) == 0)
		{
			cout << ++counter << "\t";
			m_user_list[i]->show();
			cout << "--------------------------------------------------\n";
		}
	}
}
//----------------------------------------------------------------------------------------//
void System::printBuyerSellerList() const
{
	cout << "\t _______________________\n";
	cout << "\t|                       |\n";
	cout << "\t|    BuyerSeller List   |\n";
	cout << "\t|_______________________|\n\n";

	cout << "--------------------------------------------------\n";

	int counter = 0;

	for (int i = 0; i < m_num_of_users; i++)
	{
		BuyerSeller* temp = dynamic_cast<BuyerSeller*>(m_user_list[i]);
		if (temp)
		{
			cout << ++counter << "\t";
			m_user_list[i]->show();
			cout << "--------------------------------------------------\n";
		}
	}
}
//----------------------------------------------------------------------------------------//
/*
Receives a product name and prints all products in the system with that name
*/
void System::printProductsByName(char* product_name) const
{
	for (int i = 0; i < m_num_of_products; i++)
	{
		if (strcmp(m_product_list[i]->getName(), product_name) == 0)
			m_product_list[i]->printProduct();
	}
}	
//----------------------------------------------------------------------------------------//
/*
Receives a username and searches the system's user list to find a seller with the given name.
Returns a pointer to that seller
*/
Seller* System::findSeller(const char* username) const
{
	for (int i = 0; i < m_num_of_users; i++)
	{
		Seller* temp = dynamic_cast<Seller*>(m_user_list[i]);
		if (temp)
		{
			if (strcmp(temp->getUserName(), username) == 0)
				return temp;
		}
	}

	return nullptr;	//Seller not found
}
//----------------------------------------------------------------------------------------//
/*
Receives a username and searches the system's user list to find a buyer with the given name.
Returns a pointer to that buyer
*/
Buyer* System::findBuyer(const char* username) const
{
	for (int i = 0; i < m_num_of_users; i++)
	{
		Buyer* temp = dynamic_cast<Buyer*>(m_user_list[i]);
		if (temp)
		{
			if (strcmp(temp->getUserName(), username) == 0)
				return temp;
		}
	}

	return nullptr;	//Buyer not found
}
//----------------------------------------------------------------------------------------//
/*
Receives a username and searches the system's user list to find a buyerseller with the given name.
Returns a pointer to that buyerseller
*/
BuyerSeller* System::findBuyerSeller(const char* username) const
{
	for (int i = 0; i < m_num_of_users; i++)
	{
		BuyerSeller* temp = dynamic_cast<BuyerSeller*>(m_user_list[i]);
		if (temp)
		{
			if (strcmp(temp->getUserName(), username) == 0)
				return temp;
		}
	}

	return nullptr;	//BuyerSeller not found
}
//----------------------------------------------------------------------------------------//
/*
Receives a product and adds it to the system's product list
*/
void System::newProduct(Product& new_product)
{
	if (!m_product_list)	//If empty product list
	{
		m_num_of_products++;
		m_product_list = new Product*[m_num_of_products];
		Validation::checkAllocation(m_product_list);
		m_product_list[0] = &new_product;
	}
	else
	{
		Product** temp = new Product*[m_num_of_products + 1];	//allocate memory for new product list
		Validation::checkAllocation(temp);
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
and returns the product if found.
*/
Product* System::findProduct(int serial_number, const char* name) const
{
	for (int i = 0; i < m_num_of_products; i++)
	{
		if ((m_product_list[i]->getSerialNumber() == serial_number) && (strcmp(m_product_list[i]->getName(),name)==0))
			return m_product_list[i];
	}

	return nullptr;
}
//----------------------------------------------------------------------------------------//
/*
Receives product name, returns true if any products with this name exist in the system, else false.
*/
bool System::productExist(const char* product_name) const
{
	for (int i = 0; i < m_num_of_products; i++)
	{
		if (strcmp(m_product_list[i]->getName(), product_name) == 0)
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------------------//
/*
This operator adds a buyer to the system.
*/
void System::operator+=(Buyer& buyer)
{
	addUser(buyer);
}
//----------------------------------------------------------------------------------------//
/*
This operator adds a seller to the system.
*/
void System::operator+=(Seller& seller)
{
	addUser(seller);
}
//----------------------------------------------------------------------------------------//
/*
This operator adds a buyerseller to the system.
*/
void System::operator+=(BuyerSeller& buyerseller)
{
	addUser(buyerseller);
}
//----------------------------------------------------------------------------------------//
/*
This method is called upon from the ">" operator test method in the Menu class.
It asks the user to pick a buyer/buyerseller from the system's user list.
The selected buyer/buyerseller is then returned.
The use of dynamic cast is to allow buyers and buyersellers to be picked.
*/
Buyer* System::pickBuyer(int buyer_number) const
{
	int selection;

	cout << "Please pick buyer no." << buyer_number << endl;
	cout << "--------------------------------------------------\n";

	for (int i = 0; i < m_num_of_users; i++)
	{
		Buyer* temp = dynamic_cast<Buyer*>(m_user_list[i]);
		if (temp)
		{
			temp->show();
			cout << "Enter 1 to select this buyer or 2 for next: ";
			cin >> selection;
			cout << "--------------------------------------------------\n";

			while (selection != 1 && selection != 2)
			{
				cout << "Invalid number entered, please try again: ";
				cin >> selection;
				cout << "--------------------------------------------------\n";
			}

			if (selection == 1)
				return temp;
		}
	}

	cout << "No more buyers left, returning to operator tests menu...\n";
	return nullptr;
}
//----------------------------------------------------------------------------------------//