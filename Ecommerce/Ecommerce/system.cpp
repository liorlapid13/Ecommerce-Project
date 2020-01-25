#include "system.h"
//----------------------------------------------------------------------------------------//
System::System(const string& name)
{
	setName(name);
}
//----------------------------------------------------------------------------------------//
System::~System()
{
	vector<User*>::iterator itr = m_user_list.begin();
	vector<User*>::iterator itrEnd = m_user_list.end();

	for (; itr != itrEnd; ++itr)
		delete *itr;
}
//----------------------------------------------------------------------------------------//
void System::setName(const string& name)
{
	this->m_name = name;
}
//----------------------------------------------------------------------------------------//
const string& System::getName() const
{
	return m_name;
}
//----------------------------------------------------------------------------------------//
vector<User*>& System::getUserList()
{
	return m_user_list;
}
//----------------------------------------------------------------------------------------//
int System::getNumOfUsers() const
{
	return m_user_list.size();
}
//----------------------------------------------------------------------------------------//
vector<Product*>& System::getProductList()
{
	return m_product_list;
}
//----------------------------------------------------------------------------------------//
int System::getNumOfProducts() const
{
	return m_product_list.size();
}
//----------------------------------------------------------------------------------------//
/*
Receives a new user and adds it to the system user list
*/
void System::addUser(User& new_user)
{
	m_user_list.push_back(&new_user);
}
//----------------------------------------------------------------------------------------//
/*
Search for username in system user list.
*/
bool System::searchUsername(const string& username) const
{
	vector<User*>::const_iterator itr = m_user_list.begin();
	vector<User*>::const_iterator itrEnd = m_user_list.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getUserName() == username)
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

	vector<User*>::const_iterator itr = m_user_list.begin();
	vector<User*>::const_iterator itrEnd = m_user_list.end();

	for (; itr != itrEnd; ++itr)
	{
		if (strcmp(typeid(**itr).name(), typeid(Buyer).name()) == 0)
		{
			cout << ++counter << "\t";
			(*itr)->show();
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

	vector<User*>::const_iterator itr = m_user_list.begin();
	vector<User*>::const_iterator itrEnd = m_user_list.end();

	for (; itr != itrEnd; ++itr)
	{
		if (strcmp(typeid(**itr).name(), typeid(Seller).name()) == 0)
		{
			cout << ++counter << "\t";
			(*itr)->show();
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

	vector<User*>::const_iterator itr = m_user_list.begin();
	vector<User*>::const_iterator itrEnd = m_user_list.end();

	for (; itr != itrEnd; ++itr)
	{
		if (strcmp(typeid(**itr).name(), typeid(BuyerSeller).name()) == 0)
		{
			cout << ++counter << "\t";
			(*itr)->show();
			cout << "--------------------------------------------------\n";
		}
	}
}
//----------------------------------------------------------------------------------------//
/*
Receives a product name and prints all products in the system with that name
*/
void System::printProductsByName(const string& product_name) const
{
	vector<Product*>::const_iterator itr = m_product_list.begin();
	vector<Product*>::const_iterator itrEnd = m_product_list.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == product_name)
			(*itr)->printProduct();
	}
}	
//----------------------------------------------------------------------------------------//
/*
Receives a username and searches the system's user list to find a seller with the given name.
Returns a pointer to that seller
*/
Seller* System::findSeller(const string& username) const
{
	vector<User*>::const_iterator itr = m_user_list.begin();
	vector<User*>::const_iterator itrEnd = m_user_list.end();

	for ( ; itr != itrEnd; ++itr)
	{
		Seller* temp = dynamic_cast<Seller*>(*itr);
		if (temp)
		{
			if (temp->getUserName() == username)
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
Buyer* System::findBuyer(const string& username) const
{
	vector<User*>::const_iterator itr = m_user_list.begin();
	vector<User*>::const_iterator itrEnd = m_user_list.end();

	for (; itr != itrEnd; ++itr)
	{
		Buyer* temp = dynamic_cast<Buyer*>(*itr);
		if (temp)
		{
			if (temp->getUserName() == username)
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
BuyerSeller* System::findBuyerSeller(const string& username) const
{
	vector<User*>::const_iterator itr = m_user_list.begin();
	vector<User*>::const_iterator itrEnd = m_user_list.end();

	for (; itr != itrEnd; ++itr)
	{
		BuyerSeller* temp = dynamic_cast<BuyerSeller*>(*itr);
		if (temp)
		{
			if (temp->getUserName() == username)
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
	m_product_list.push_back(&new_product);
}
//----------------------------------------------------------------------------------------//
/*
Receives serial number from buyer menu, searches for item with matching serial number in the system's product list
and returns the product if found.
*/
Product* System::findProduct(int serial_number, const string& product_name) const
{
	vector<Product*>::const_iterator itr = m_product_list.begin();
	vector<Product*>::const_iterator itrEnd = m_product_list.end();

	for ( ; itr != itrEnd; ++itr)
	{
		if (((*itr)->getSerialNumber() == serial_number) && ((*itr)->getName() == product_name))
			return *itr;
	}

	return nullptr;
}
//----------------------------------------------------------------------------------------//
/*
Receives product name, returns true if any products with this name exist in the system, else false.
*/
bool System::productExist(const string& product_name) const
{
	vector<Product*>::const_iterator itr = m_product_list.begin();
	vector<Product*>::const_iterator itrEnd = m_product_list.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == product_name)
			return true;
	}

	return false;
}
//----------------------------------------------------------------------------------------//
/*
This operator adds a buyer to the system.
*/
void System::operator+=(const Buyer& buyer)
{
	User *new_user = new Buyer(buyer);
	Validation::checkAllocation(new_user);
	addUser(*new_user);
}
//----------------------------------------------------------------------------------------//
/*
This operator adds a seller to the system.
*/
void System::operator+=(const Seller& seller)
{
	User *new_user = new Seller(seller);
	Validation::checkAllocation(new_user);
	addUser(*new_user);
}
//----------------------------------------------------------------------------------------//
/*
This operator adds a buyerseller to the system.
*/
void System::operator+=(const BuyerSeller& buyerseller)
{
	User *new_user = new BuyerSeller(buyerseller);
	Validation::checkAllocation(new_user);
	addUser(*new_user);
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
	if (m_user_list.size() == 0)
	{
		cout << "Please create buyers or buyersellers before testing the '>' operator\n";
		cout << "--------------------------------------------------\n";
		return nullptr;
	}

	int selection;

	cout << "Please pick buyer no." << buyer_number << endl;
	cout << "--------------------------------------------------\n";

	vector<User*>::const_iterator itr = m_user_list.begin();
	vector<User*>::const_iterator itrEnd = m_user_list.end();

	for (; itr != itrEnd; ++itr)
	{
		Buyer* temp = dynamic_cast<Buyer*>(*itr);
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
void System::writeUserList() const
{
	ofstream out_file("User_list.txt", ios::trunc);
	if (this->m_user_list.empty())
		out_file << 0 << endl;
	else
	{
		out_file << this->m_user_list.size() << endl;

		vector<User*>::const_iterator itr = m_user_list.begin();
		vector<User*>::const_iterator itrEnd = m_user_list.end();

		for (; itr != itrEnd; ++itr)
			(*itr)->writeUser(out_file);
	}
	out_file.close();
}
//----------------------------------------------------------------------------------------//
void System::loadUserList(const char* file_name)
{
	ifstream in_file(file_name, ios::in);

	int num_of_users;
	in_file >> num_of_users;

	if (num_of_users == 0)
		in_file.close();
	else
	{
		User* user;
		string username, password, street, city, country;
		int house_number, zip_code;
		char delimiter;
		cout << "Reading users from file..\n";
		for (int i = 0; i < num_of_users; i++)
		{
			int user_type;
			in_file >> user_type >> delimiter;
			getline(in_file, username, '$');
			getline(in_file, password, '$');
			getline(in_file, country, '$');
			getline(in_file, city, '$');
			getline(in_file, street, '$');
			in_file >> house_number >> delimiter >> zip_code >> delimiter;
			Address address(street, house_number, zip_code, city, country);

			switch (user_type)
			{
				case 1:
				{
					user = new Buyer(username, password, address);
					addUser(*user);
					break;
				}
				case 2:
				{
					user = new Seller(username, password, address);
					addUser(*user);
					break;
				}
				case 3:
				{
					user = new BuyerSeller(username, password, address);
					addUser(*user);
					break;
				}
				default:
					cout << "Invalid user type read from file\n";
					break;
			}
		}

		in_file.close();
	}
}