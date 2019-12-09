#include "menu.h"

Menu::Menu(System* system)
{
	m_system = system;
}
//----------------------------------------------------------------------------------------//
Menu::~Menu()
{
}
//----------------------------------------------------------------------------------------//
System* Menu::getSystem()
{
	return m_system;
}
//----------------------------------------------------------------------------------------//
Seller* Menu::createSeller()
{
	char username[MAX_USERNAME_LENGTH];
	do
	{
		cout << "Please enter username: ";
		cin.ignore();
		cin.getline(username, MAX_USERNAME_LENGTH);
	} while (m_system->searchUsername(username));
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
	Seller* new_seller = new Seller(username, password, new_address);
	m_system->addSeller(*new_seller);
	return new_seller;
}
//----------------------------------------------------------------------------------------//
Buyer* Menu::createBuyer()
{
	char username[MAX_USERNAME_LENGTH];
	do
	{
		cout << "Enter username: ";
		cin.ignore();
		cin.getline(username, MAX_USERNAME_LENGTH);
	} while (m_system->searchUsername(username));	//is this how to call a system class function to search buyer/seller list for the inputted username?

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
	Buyer* new_buyer = new Buyer(username, password, new_address);
	m_system->addBuyer(*new_buyer);
	return new_buyer;
}
//----------------------------------------------------------------------------------------//
Products* Menu::createProduct()
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
void Menu::newOrder(Buyer& buyer)
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
		cout << "Enter " << i << " to add " << temp[i]->getName() << " to your order\n";
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
void Menu::completeOrder(Buyer& buyer)
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
Presents buyer with his order history, and asks him to select product for new feedback.
Once buyer selects a product, calls buyer method "newFeedback" to create the new feedback if he hasn't 
submitted one for this product already.
*/
void Menu::createFeedback(Buyer& buyer)
{
	cout << "Please select for which product you wish to publish a feedback\n";
	for (int i = 0; i < buyer.getNumOrders(); i++)
	{
		cout << "Order No." << i + 1 << ": \n";
		for (int j = 0; j < buyer.getOrderHistory()[i]->getListSize(); j++)
		{
			buyer.getOrderHistory()[i]->getProductList()[j]->printProduct();
			cout << "Enter " << j << " to publish a feedback for this product\n";
		}

		cout << "Please select a product or enter -1 for next order: ";
		int selection;
		cin >> selection;

		while ((selection != -1) && selection >= (buyer.getOrderHistory()[i]->getListSize()))
		{
			cout << "Invalid input, please try again: ";
			cin >> selection;
		}

		if (selection != -1)
		{
			cout << "Product selected, please enter feedback description (Max 250 letters):\n";
			char description[MAX_FEEDBACK_LENGTH];
			cin.getline(description, MAX_FEEDBACK_LENGTH);

			cout << "Enter day, month and year (for example, 30 11 2019): ";
			int day, month, year;
			cin >> day >> month >> year;
			Date date(day, month, year);
			if (buyer.newFeedback(buyer.getOrderHistory()[i]->getProductList()[selection],
				m_system->findSeller(buyer.getOrderHistory()[i]->getProductList()[selection]->getSeller()),
				description, date))
				cout << "Feedback added successfully\n";
			else
				cout << "You have already submitted a feedback for this product, feedback cancelled\n";
			return;
		}
	}

	cout << "No more orders, feedback cancelled\n";
}
//----------------------------------------------------------------------------------------//
void Menu::mainMenu()
{
	bool quit_switch = 0;

	while (!quit_switch)
	{
		cout << "Welcome to " << m_system->getName() << endl;
		cout << "Enter 1 to Log-In\n";
		cout << "Enter 2 to Sign-Up\n";
		cout << "Enter 3 to Quit\n";

		int user_input;
		cin >> user_input;
		while (user_input != 1 && user_input != 2 && user_input != 3)
		{
			cout << "Invalid selection, please try again\n";
			cin >> user_input;
		}

		//Quit
		if (user_input == 3) 
		{
			quit_switch == 1;
			break;
		}

		cout << "Enter 1 for Buyer\n";
		cout << "Enter 2 for Seller\n";
		int user_type;
		cin >> user_type;
		while (user_type != 1 && user_type != 2)
		{
			cout << "Invalid selection, please try again\n";
			cin >> user_type;
		}

		if (user_input == 2)
		{
			//Sign-up method
			this->signUp(user_type);
		}
		else
		{
			/*Log-In Method*/
			
		}
	}
}
//----------------------------------------------------------------------------------------//
void Menu::signUp(int user_type)
{
	if (user_type == 1)
	{
		//buyerMenu(createBuyer());
	}
	else
	{
		//sellerMenu(createSeller());
	}
}
//----------------------------------------------------------------------------------------//
/*
Receives user type (1=buyer,2=seller) and asks user to input his log-in details (username and password).
Checks the relevant buyer/seller database and looks for a match of username and password.
If username/password are invalid, asks the user if he wants to continue trying or exit to main menu.
If username/password are correct, opens the corresponding buyer/seller menu.
*/
void Menu::logIn(int user_type)
{
	bool logged_in = 0;

	while (!logged_in)
	{
		cout << "Enter username: ";
		char username[MAX_USERNAME_LENGTH];
		cin.ignore();
		cin >> username;

		cout << "Enter password: ";
		char password[MAX_PASSWORD_LENGTH];
		cin.ignore();
		cin >> password;

		if (user_type == 1)
		{
			Buyer* buyer = m_system->findBuyer(username);
			if (!buyer)
				break;
			else if (strcmp(buyer->getPassword(), password) == 0)
			{
				logged_in = 1;
				this->buyerMenu(*buyer);
			}
		}
		else
		{
			Seller* seller = m_system->findSeller(username);
			if (!seller)
				break;
			else if (strcmp(seller->getPassword(), password) == 0)
			{
				logged_in = 1;
				this->sellerMenu(*seller);
			}
		}
		
		if (!logged_in)
		{
			cout << "Username/Password incorrect! Would you like to try again?\n";
			cout << "Enter 1 to try again or -1 to return to main menu: ";
			int retry;
			cin >> retry;
			while (retry != 1 && retry != -1)
			{
				cout << "Invalid input, please try again: ";
				cin >> retry;
			}

			if (retry == -1)
			{
				logged_in = 1;
			}
		}
	}
}
//----------------------------------------------------------------------------------------//