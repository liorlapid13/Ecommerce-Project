#include "helper.h"
//----------------------------------------------------------------------------------------//
bool checkString(const int length, const char* string)
{
	//scan string for any characters that are not a space or letter
	for (int i = 0; i < length; i++)
	{
		//Check for invalid characters
		if (string[i] != '-' && string[i] != ' ' && (string[i] < 'A' || string[i] > 'z'
			|| (string[i] > 'Z' && string[i] < 'a'))) //KI#1,2
		{
			return false;
		}
	}

	return true;
}
//----------------------------------------------------------------------------------------//
bool passwordCheck(const char* password)
{
	//check if length of password is valid
	if (strlen(password) < MIN_PASSWORD_LENGTH || strlen(password) > MAX_PASSWORD_LENGTH)
	{
		cout << "Password must contain 6-15 characters\n";
		return false;
	}
	else
	{
		bool uppercase_found = 0, lowercase_found = 0, number_found = 0;

		//scans the password for lowercase/uppercase letters and numbers
		for (int i = 0; i < strlen(password),
			(uppercase_found == 0 || lowercase_found == 0 || number_found == 0); i++)
		{
			//check if password has spaces
			if (password[i] == ' ')
			{
				cout << "Invalid space in password\n";
				return false;
			}
			//check for number
			if (password[i] >= '0' && password[i] <= '9' && !number_found)
				number_found = 1;
			//check for lowercase letter
			if (password[i] >= 'a' && password[i] <= 'z' && !lowercase_found)
				lowercase_found = 1;
			//check for uppercase letter
			if (password[i] >= 'A' && password[i] <= 'Z' && !uppercase_found)
				uppercase_found = 1;
		}

		//check if lowercase letter, uppercase letter and number were found in password
		if (!uppercase_found || !lowercase_found || !number_found)
		{
			cout << "Password must contain at least one lowercase character, uppercase character and number\n";
			return false;
		}
		else
			return true;
	}
}
//----------------------------------------------------------------------------------------//
bool usernameCheck(const char* username)
{
	//check if username length is valid
	if (strlen(username) < MIN_USERNAME_LENGTH || strlen(username) > MAX_USERNAME_LENGTH)
	{
		cout << "Username must contain 6-15 characters\n";
		return false;
	}
	else
	{
		//check if name contains symbols/spaces/invalid characters
		for (int i = 0; i < strlen(username); i++)
		{
			if (username[i] < '0' || (username[i] > 'z'
				|| (username[i] > '9' && username[i] < 'A')
				|| (username[i] > 'Z' && username[i] < 'a')
				))
			{
				cout << "Username can only contain alphanumeric characters (lower/uppercase letters A-Z, numbers 0-9)\n";
				return false;
			}
		}
		return true;
	}
}
//----------------------------------------------------------------------------------------//
Seller* createSeller(System& system)
{
	char username[MAX_USERNAME_LENGTH];
	do
	{
		cout << "Please enter username: ";
		cin.ignore();
		cin.getline(username, MAX_USERNAME_LENGTH);
	} while (system.searchUsername(username));	//is this how to call a system class function to search buyer/seller list for the inputted username?

	char password[MAX_PASSWORD_LENGTH];
	cout << "Please enter password: ";
	cin.ignore();
	cin.getline(password, MAX_PASSWORD_LENGTH);

	char country[MAX_COUNTRY_LENGTH];
	cout << "Please enter country: ";
	cin.ignore();
	cin.getline(country, MAX_COUNTRY_LENGTH);

	char city[MAX_CITY_LENGTH];
	cout << "Please enter city: ";
	cin.ignore();
	cin.getline(city, MAX_CITY_LENGTH);

	char street_name[MAX_STREET_LENGTH];
	cout << "Please enter street name: ";
	cin.ignore();
	cin.getline(street_name, MAX_STREET_LENGTH);

	int house_number;
	cout << "Please enter house number: ";
	cin.ignore();
	cin >> house_number;

	int zip_code;
	cout << "Please enter zip_code: ";
	cin.ignore();
	cin >> zip_code;

	Address new_address(street_name, house_number, zip_code, city, country);
	return (new Seller(username, password, new_address));
}
//----------------------------------------------------------------------------------------//
Buyer* createBuyer(System& system)
{
	char username[MAX_USERNAME_LENGTH];
	do
	{
		cout << "Please enter username: ";
		cin.ignore();
		cin.getline(username, MAX_USERNAME_LENGTH);
	} while (system.searchUsername(username));	//is this how to call a system class function to search buyer/seller list for the inputted username?

	char password[MAX_PASSWORD_LENGTH];
	cout << "Please enter password: ";
	cin.ignore();
	cin.getline(password, MAX_PASSWORD_LENGTH);

	char country[MAX_COUNTRY_LENGTH];
	cout << "Please enter country: ";
	cin.ignore();
	cin.getline(country, MAX_COUNTRY_LENGTH);

	char city[MAX_CITY_LENGTH];
	cout << "Please enter city: ";
	cin.ignore();
	cin.getline(city, MAX_CITY_LENGTH);

	char street_name[MAX_STREET_LENGTH];
	cout << "Please enter street name: ";
	cin.ignore();
	cin.getline(street_name, MAX_STREET_LENGTH);

	int house_number;
	cout << "Please enter house number: ";
	cin.ignore();
	cin >> house_number;

	int zip_code;
	cout << "Please enter zip_code: ";
	cin.ignore();
	cin >> zip_code;

	Address new_address(street_name, house_number, zip_code, city, country);
	return (new Buyer(username, password, new_address));
}
//----------------------------------------------------------------------------------------//