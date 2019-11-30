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
	} while (system.searchUsername(username));
	//is this how to call a system class function to search buyer/seller list for the inputted username?

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
		cout << "Enter username: ";
		cin.ignore();
		cin.getline(username, MAX_USERNAME_LENGTH);
	} while (system.searchUsername(username));	//is this how to call a system class function to search buyer/seller list for the inputted username?

	char password[MAX_PASSWORD_LENGTH];
	cout << "Enter password: ";
	cin.ignore();
	cin.getline(password, MAX_PASSWORD_LENGTH);

	char country[MAX_COUNTRY_LENGTH];
	cout << "Enter country: ";
	cin.ignore();
	cin.getline(country, MAX_COUNTRY_LENGTH);

	char city[MAX_CITY_LENGTH];
	cout << "Enter city: ";
	cin.ignore();
	cin.getline(city, MAX_CITY_LENGTH);

	char street_name[MAX_STREET_LENGTH];
	cout << "Enter street name: ";
	cin.ignore();
	cin.getline(street_name, MAX_STREET_LENGTH);

	int house_number;
	cout << "Enter house number: ";
	cin.ignore();
	cin >> house_number;

	int zip_code;
	cout << "Enter zip_code: ";
	cin.ignore();
	cin >> zip_code;

	Address new_address(street_name, house_number, zip_code, city, country);
	return (new Buyer(username, password, new_address));
}
//----------------------------------------------------------------------------------------//
Products* createProduct()
{
	char product_name[MAX_PRODUCT_NAME];
	cout << "Enter product name: ";
	cin.ignore();
	cin.getline(product_name, MAX_PRODUCT_NAME);

	float price;
	cout << "Enter product item: ";
	cin.ignore();
	cin >> price;

	int category;
	cout << "Enter product category (0=KIDS, 1=ELECTRICAL, 2=CLOTHING, 4=OFFICE): ";
	cin.ignore();
	cin >> category;

	char username[MAX_USERNAME_LENGTH];
	cout << "Enter your username: ";
	cin.ignore();
	cin.getline(username, MAX_USERNAME_LENGTH);

	return (new Products(product_name, price, (Products::eCategory)category, username));
}
//----------------------------------------------------------------------------------------//
/*
This function presents the buyer with their shopping cart and asks him which item/s he wishes to add to his order.
The buyer's selections are saved in "product_index_array" which is a bucket array referring to the products'
original index in the shopping cart. 
1=item selected, 0=item not selected
If atleast one item is selected, the "product_index_array" is sent to a function that creates the new order and updates
the shopping cart.
*/
void newOrder(Buyer& buyer)
{
	int cart_size = buyer.getShoppingCart().getNumProducts();
	int* product_index_array = new int[cart_size];
	for (int i = 0; i < cart_size; i++)
		product_index_array[i] = 0;

	int selection;
	Products** temp = buyer.getShoppingCart().getProductList();

	cout << "Your Shopping Cart:\n";

	for (int i = 0; i < cart_size; i++)
	{
		temp[i]->printProduct;
		cout << "Enter " << i << " to add " << temp[i]->getName() <<" to your order\n";
	}
	
	cout << "Please enter the code/s of the product/s you wish to purchase (one by one)\n";

	cin >> selection;

	float total_price = 0;
	int	num_of_selected_products = 0;

	while (selection != -1)
	{
		if (selection >= cart_size || selection < 0)
			cout << "Invalid product number, please try again: ";
		else if (product_index_array[selection] == 1)
			cout << "Product already selected\n";
		else
		{
			product_index_array[selection] = 1;
			num_of_selected_products++;
			total_price += temp[selection]->getPrice();
			cout << temp[selection]->getName() << " added to order\n";
			cout << "Total price: " << total_price << endl;
			cout << "Enter the next product code or enter -1 to checkout: ";
		}

		cin >> selection;
	}

	if (num_of_selected_products == 0)
		cout << "No products selected, order cancelled\n";
	else
		buyer.createOrder(num_of_selected_products, product_index_array, total_price);

	temp = nullptr;
	delete[] product_index_array;
}
//----------------------------------------------------------------------------------------//
void completeOrder(Buyer& buyer)
{
	if (buyer.getCurrentOrder() != nullptr)
	{
		cout << "Your Order:\n";
		for (int i = 0; i < buyer.getCurrentOrder()->getListSize(); i++)
			buyer.getCurrentOrder()->getProductList()[i]->printProduct();
		cout << "Total price: " << buyer.getCurrentOrder()->getTotalPrice() << endl;
		cout << "Your funds: " << buyer.getWallet() << endl;
		cout << "Please enter 1 to pay, or 0 to cancel: ";
		int selection;
		cin >> selection;
		switch (selection)
		{
		case 0:
			cout << "Payment cancelled\n";
			break;
		case 1:
			if (buyer.payOrder())
				cout << "Order purchased successfully\n";
			else
				cout << "Insufficient funds in wallet, please top-up and try again\n";
			break;
		default:
			cout << "Invalid input, payment cancelled\n";
			break;
		}
	}
	else
		cout << "No Orders available\n";
}
//----------------------------------------------------------------------------------------//
/*
Presents buyer with his order history, and asks him to select seller for new feedback.
Once buyer selects a seller, calls buyer method "newFeedback" to create the new feedback if terms are met.
*/
void createFeedback(Buyer& buyer, System& system)
{
	cout << "Please select for which seller you wish to publish a feedback\n";
	for (int i = 0; i < buyer.getNumOrders(); i++)
	{
		cout << "Order No." << i + 1 << ": \n";
		for (int j = 0; j < buyer.getOrderHistory()[i]->getListSize(); j++)
		{
			buyer.getOrderHistory()[i]->getProductList()[j]->printProduct();
			cout << "Enter " << j << " to publish a feedback for this seller\n";
		}

		cout << "Please select a seller or enter -1 for next order: ";
		int selection;
		cin >> selection;

		while ((selection != -1) && selection >= (buyer.getOrderHistory()[i]->getListSize()))
		{
			cout << "Invalid input, please try again: ";
			cin >> selection;
		}

		if (selection != -1)
		{
			cout << "Seller selected, please enter feedback description (Max 250 letters):\n";
			char description[MAX_FEEDBACK_LENGTH];
			cin.getline(description, MAX_FEEDBACK_LENGTH);

			cout << "Enter day, month and year (for example, 30 11 2019): ";
			int day, month, year;
			cin >> day >> month >> year;
			Date date(day, month, year);
			if (buyer.newFeedback(system.findSeller(buyer.getOrderHistory()[i]->getProductList()[selection]->getSeller()),
				description, date))
				cout << "Feedback added successfully\n";
			else
				cout << "Feedback for this seller already exists, feedback cancelled\n";
			return;
		}
	}

	cout << "No more orders, feedback cancelled\n";
}
//----------------------------------------------------------------------------------------//