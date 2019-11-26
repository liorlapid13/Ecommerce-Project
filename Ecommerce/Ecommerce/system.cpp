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
Seller System::createSeller()
{
	char username[MAX_USERNAME_LENGTH];
	char password[MAX_PASSWORD_LENGTH];
	
	char street_name[MAX_STREET_LENGTH];
	int house_number;
	char city[MAX_CITY_LENGTH];
	char country[MAX_COUNTRY_LENGTH];
	int zip_code;

	do
	{
	cout << "Please enter username: ";
	cin.ignore();
	cin.getline(username, MAX_USERNAME_LENGTH);
	} while (searchUsername(username));

	cout << "Please enter password: ";
	cin.ignore();
	cin.getline(password, MAX_PASSWORD_LENGTH);

	cout << "Please enter country: ";
	cin.ignore();
	cin.getline(country, MAX_COUNTRY_LENGTH);

	cout << "Please enter city: ";
	cin.ignore();
	cin.getline(city, MAX_CITY_LENGTH);

	cout << "Please enter street name: ";
	cin.ignore();
	cin.getline(street_name, MAX_STREET_LENGTH);

	cout << "Please enter house number: ";
	cin.ignore();
	cin >> house_number;

	cout << "Please enter zip_code: ";
	cin.ignore();
	cin >> zip_code;
	
	/*
	Now we need to create a Seller with an Address from these parameters.
	Option 1: Create Address and use Copy/Move C'tor			<--- probably the better option
	Option 2: Create new Seller C'tor with address' fields
	*/

}
//----------------------------------------------------------------------------------------//
void System::addSeller(Seller& new_seller)
{

}
//----------------------------------------------------------------------------------------//
bool System::searchUsername(char* username)	const
{
	//search for username in buyer list
	for (int i = 0; i < m_num_of_buyers; i++)
	{
		if (strcmp(m_buyer_list[i]->getUserName(),username) == 0)
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