#include "menu.h"
//----------------------------------------------------------------------------------------//
Menu::Menu(System* system)
{
	m_system = system;
}
//----------------------------------------------------------------------------------------//
Menu::~Menu()
{
	cout << "in d'tor menu\n";
}
//----------------------------------------------------------------------------------------//
System* Menu::getSystem() const
{
	return m_system;
}
//----------------------------------------------------------------------------------------//
/*
Asks the user to input details and creates a new user according to the selected type
*/
User* Menu::createUser(int user_type)
{
	char username[Validation::MAX_USERNAME_LENGTH + 1];
	cin.ignore();
	do
	{
		cout << "Enter username(If username exists you will be asked again):\n";
		cout << "Username must contain 6-15 alphanumeric characters (lower/uppercase letters A-Z, numbers 0-9)\n";
		cin.getline(username, Validation::MAX_USERNAME_LENGTH + 1);
	} while (!(m_system->searchUsername(username)));

	cout << "--------------------------------------------------\n";

	char password[Validation::MAX_PASSWORD_LENGTH + 1];
	cout << "Enter password\n";
	cout << "Password must contain 6-15 characters and atleast one of each of the following:\n";
	cout << "-Lowercase letter\n";
	cout << "-Uppercase letter\n";
	cout << "-Number\n";
	cin.getline(password, Validation::MAX_PASSWORD_LENGTH + 1);

	cout << "--------------------------------------------------\n";

	char country[Validation::MAX_COUNTRY_LENGTH + 1];
	cout << "Please enter country: ";
	cin.getline(country, Validation::MAX_COUNTRY_LENGTH + 1);

	cout << "--------------------------------------------------\n";

	char city[Validation::MAX_CITY_LENGTH + 1];
	cout << "Please enter city: ";
	cin.getline(city, Validation::MAX_CITY_LENGTH + 1);

	cout << "--------------------------------------------------\n";

	char street_name[Validation::MAX_STREET_LENGTH + 1];
	cout << "Please enter street name: ";
	cin.getline(street_name, Validation::MAX_STREET_LENGTH + 1);

	cout << "--------------------------------------------------\n";

	int house_number;
	cout << "Please enter house number: ";
	cin >> house_number;

	cout << "--------------------------------------------------\n";

	int zip_code;
	cout << "Please enter zip_code (7 digits): ";
	cin >> zip_code;

	cout << "--------------------------------------------------\n";

	Address new_address(street_name, house_number, zip_code, city, country);

	User* new_user;

	switch (user_type)
	{
	case 1:
		new_user = new Buyer(username, password, new_address);
		Validation::checkAllocation(new_user);
		break;
	case 2:
		new_user = new Seller(username, password, new_address);
		Validation::checkAllocation(new_user);
		break;
	case 3:
		new_user = new BuyerSeller(username, password, new_address);
		Validation::checkAllocation(new_user);
		break;
	}

	m_system->addUser(*new_user);
	return new_user;
}
//----------------------------------------------------------------------------------------//
/*
Asks the user to input details and creates a new product
*/
Product* Menu::createProduct(const char* seller_username)
{
	char product_name[Product::MAX_PRODUCT_NAME + 1];
	cout << "Enter product name\n";
	cout << "Product name can only contain alphanumeric characters (lower/uppercase letters A-Z, numbers 0-9) and spaces\n";
	cin.ignore();
	cin.getline(product_name, Product::MAX_PRODUCT_NAME + 1);

	float price;
	cout << "Enter product price (in dollars):$";
	cin >> price;

	int category;
	cout << "Enter product category (0=KIDS, 1=ELECTRICAL, 2=CLOTHING, 3=OFFICE): ";
	cin >> category;

	return (new Product(product_name, price, (Product::eCategory)category, seller_username));
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
	Validation::checkAllocation(product_index_array);
	for (int i = 0; i < cart_size; i++)
		product_index_array[i] = 0;

	int selection;
	Product** temp = buyer.getShoppingCart().getProductList();

	cout << "Your Shopping Cart:\n";

	for (int i = 0; i < cart_size; i++)
	{
		temp[i]->printProduct();
		cout << "Enter " << i << " to add " << temp[i]->getName() << " to your order\n";
		cout << "--------------------------------------------------\n";
	}

	cout << "Please enter the code/s of the product/s you wish to purchase (one by one)\n";
	cout << "If you wish to cancel press -1\n";

	cin >> selection;

	float total_price = 0;
	int	num_of_selected_products = 0;

	while (selection != -1)
	{
		if (selection >= cart_size || selection < 0)
			cout << "Invalid product number, please try again: ";
		else if (product_index_array[selection] == 1)
			cout << "Product already selected, please try again: ";
		else
		{
			product_index_array[selection] = 1;
			num_of_selected_products++;
			total_price += temp[selection]->getPrice();
			cout << temp[selection]->getName() << " added to order\n";
			cout << "Total price: $" << total_price << endl;
			cout << "--------------------------------------------------\n";
			cout << "Enter the next product code or enter -1 to finish: ";
		}

		cin >> selection;
	}

	if (num_of_selected_products == 0)
	{
		cout << "No products selected, order cancelled\n";
		cout << "--------------------------------------------------\n";
	}
	else
	{
		buyer.createOrder(num_of_selected_products, product_index_array, total_price);
		cout << "Order complete, to pay go to 3rd option in the buyer menu\n";
		cout << "--------------------------------------------------\n";
	}

	temp = nullptr;
	delete[] product_index_array;
}
//----------------------------------------------------------------------------------------//
/*
Receives a buyer from buyer menu, if an order exists, lets him pay for the order.
*/
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
		cout << "No existing order\n";
}
//----------------------------------------------------------------------------------------//
/*
Presents buyer with his order history, and asks him to select a product for new feedback.
Once buyer selects a product, calls buyer method "newFeedback" to create the new feedback if he hasn't 
submitted one for this product already.
*/
void Menu::createFeedback(Buyer& buyer)
{
	cout << "--------------------------------------------------\n";

	cout << "Please select for which product you wish to publish a feedback\n";
	for (int i = 0; i < buyer.getNumOrders(); i++)
	{
		cout << "Order No." << i + 1 << ": \n";
		for (int j = 0; j < buyer.getOrderHistory()[i]->getListSize(); j++)
		{
			buyer.getOrderHistory()[i]->getProductList()[j]->printProduct();
			cout << "Enter " << j << " to publish a feedback for this product\n";
			cout << "--------------------------------------------------\n";
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
			cin.ignore();
			cout << "Product selected, please enter feedback description (Max 250 letters):\n";
			char description[MAX_FEEDBACK_LENGTH + 1];
			cin.getline(description, MAX_FEEDBACK_LENGTH + 1);

			cout << "--------------------------------------------------\n";

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
		cout << "\t\t ___________\n";
		cout << "\t\t|           |\n";
		cout << "\t\t|   " << m_system->getName() << "    |\n";	
		cout << "\t\t|___________|\n";
		cout << "\t\t|           |\n";
		cout << "\t\t| MAIN MENU |\n";
		cout << "\t\t|___________|\n\n";
		cout << "--------------------------------------------------\n";
		cout << "Enter 1 to Log-In\n";
		cout << "Enter 2 to Sign-Up\n";
		cout << "Enter 3 to view User Lists\n";
		cout << "Enter 4 to Quit\n";
		cout << "--------------------------------------------------\n";
		cout << "Enter number of what you would like to do: ";

		int user_input;
		cin >> user_input;
		while (user_input != 1 && user_input != 2 && user_input != 3 && user_input != 4)
		{
			cout << "Invalid selection, please try again\n";
			cin >> user_input;
		}

		cout << "--------------------------------------------------\n";

		//Quit
		if (user_input == 4) 
		{
			quit_switch == 1;
			break;
		}

		cout << "Enter 1 for Buyer\n";
		cout << "Enter 2 for Seller\n";
		cout << "Enter 3 for BuyerSeller\n";
		int user_type;
		cin >> user_type;

		cout << "--------------------------------------------------\n";

		while (user_type != 1 && user_type != 2 && user_type != 3)
		{
			cout << "Invalid selection, please try again: ";
			cin >> user_type;
		}

		if (user_input == 2)
		{
			//Sign-up method
			this->signUp(user_type);
		}
		else if (user_input == 3)
		{
			//Print list of buyers/sellers/buyersellers
			if (user_type == 1)
				m_system->printBuyerList();
			else if (user_type == 2)
				m_system->printSellerList();
			else
				m_system->printBuyerSellerList();
		}
		else
		{
			//Log-in method
			this->logIn(user_type);
		}
	}
}
//----------------------------------------------------------------------------------------//
/*
Receives user type forwards user to user creation method
*/
void Menu::signUp(int user_type)
{
	cout << " _____________\n";
	cout << "|             |\n";
	cout << "|   Sign-Up   |\n";
	cout << "|_____________|\n\n";

	User* new_user = createUser(user_type);

	switch (user_type)
	{
		case 1:
		{
			Buyer* temp = dynamic_cast<Buyer*>(new_user);
			if (temp)
				this->buyerMenu(*temp);
			break;
		}
		case 2:
		{
			Seller* temp = dynamic_cast<Seller*>(new_user);
			if (temp)
				this->sellerMenu(*temp);
			break;
		}
		case 3:
		{
			BuyerSeller* temp = dynamic_cast<BuyerSeller*>(new_user);
			if (temp)
				this->buyerSellerMenu(*temp);
			break;
		}
	}
}
//----------------------------------------------------------------------------------------//
/*
Receives user type (1=buyer,2=seller,3=buyerseller) and asks user to input his log-in details (username and password).
Checks the relevant buyer/seller database and looks for a match of username and password.
If username/password are invalid, asks the user if he wants to continue trying or exit to main menu.
If username/password are correct, opens the corresponding buyer/seller menu.
*/
void Menu::logIn(int user_type)
{
	cout << " ____________\n";
	cout << "|            |\n";
	cout << "|   Log-In   |\n";
	cout << "|____________|\n\n";

	bool logged_in = 0;
	
	while (!logged_in)
	{
		cin.ignore();
		cout << "Enter username: ";
		char username[Validation::MAX_USERNAME_LENGTH + 1];
		cin.getline(username, Validation::MAX_USERNAME_LENGTH + 1);
		

		cout << "Enter password: ";
		char password[Validation::MAX_PASSWORD_LENGTH + 1];
		cin.getline(password, Validation::MAX_PASSWORD_LENGTH + 1);

		if (user_type == 1)
		{
			Buyer* buyer = m_system->findBuyer(username);
			if (buyer && (strcmp(buyer->getPassword(), password) == 0))
			{
				logged_in = 1;
				this->buyerMenu(*buyer);
			}
		}
		else if (user_type == 2)
		{
			Seller* seller = m_system->findSeller(username);
			if (seller && (strcmp(seller->getPassword(), password) == 0))
			{
				logged_in = 1;
				this->sellerMenu(*seller);
			}
		}
		else
		{
			BuyerSeller* buyerseller = m_system->findBuyerSeller(username);
			if (buyerseller && (strcmp(buyerseller->getPassword(), password) == 0))
			{
				logged_in = 1;
				this->buyerSellerMenu(*buyerseller);
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
/*
Once logged in as buyer, this method manages the menu of actions for buyers.
*/
void Menu::buyerMenu(Buyer& buyer)
{
	this->printBuyerMenu();

	int selection;
	cin >> selection;

	cout << "--------------------------------------------------\n";

	while (selection != 6)
	{
		switch (selection)
		{	
			case 1:	/*Add item to shopping cart - Question 5*/
			{
				addItemToShoppingCart(buyer);
				break;
			}
			case 2:	/*Create new order - Question 6*/
			{
				createNewOrder(buyer);
				break;
			}
			case 3: /*Pay for existing order - Question 7*/
			{
				completeOrder(buyer);
				break;
			}
			case 4: /*Publish new feedback - Question 4*/
			{
				publishNewFeedback(buyer);
				break;

			}
			case 5: /*Charge your wallet*/
			{
				chargeYourWallet(buyer);
				break;

			}
			default:
			{
				cout << "Invalid number entered\n";
				break;
			}
		}

		this->printBuyerMenu();
		cin >> selection;
	}

	cout << "Logging out...\n";
}
//----------------------------------------------------------------------------------------//
void Menu::printBuyerMenu() const
{
	cout << "\t\t ____________\n";
	cout << "\t\t|            |\n";
	cout << "\t\t| BUYER MENU |\n";
	cout << "\t\t|____________|\n\n";
	cout << "--------------------------------------------------\n";
	cout << "1\tAdd item to your Shopping Cart\n";	
	cout << "2\tCreate new order\n";				
	cout << "3\tPay for existing order\n";			
	cout << "4\tPublish a new feedback\n";			
	cout << "5\tCharge wallet\n";
	cout << "6\tLog-out\n";
	cout << "--------------------------------------------------\n";
	cout << "Enter number of what you would like to do: ";
}
//----------------------------------------------------------------------------------------//
void Menu::addItemToShoppingCart(Buyer& buyer)
{
	char product_name[Product::MAX_PRODUCT_NAME + 1];
	bool product_found = 0;
	while (!product_found)
	{
		cout << "Enter name of product you wish to buy: ";
		cin.ignore();
		cin.getline(product_name, Product::MAX_PRODUCT_NAME + 1);
		if (!(m_system->productExist(product_name)))
		{
			cout << "There is no " << product_name << " for sale in the system\n";
			cout << "Would you like to try again?\n";
			cout << "1 = Try again, 2 = Back to main menu\n";
			int retry;
			cin >> retry;
			while (retry != 1 && retry != 2)
			{
				cout << "Invalid input\n";
				cin >> retry;
			}

			if (retry == 2)
				return;
		}
		else
		{
			product_found = 1;
			cout << "--------------------------------------------------\n";
			m_system->printProductsByName(product_name);	//Question 10
		}
	}

	if (!product_found)
		return;

	cout << "Enter serial number of product you wish to buy: ";
	int serial_number;
	cin >> serial_number;

	Product* product = m_system->findProduct(serial_number, product_name);

	while (!product)
	{
		cout << "Invalid serial number, please try again:";
		cin >> serial_number;
		product = m_system->findProduct(serial_number, product_name);
	}
	
	buyer.m_shopping_cart.addItemToShoppingCart(*product);
	cout << product->getName() << " added to your shopping cart\n";
}
//----------------------------------------------------------------------------------------//
void Menu::createNewOrder(Buyer& buyer)
{
	if (!buyer.getShoppingCart().getNumProducts())
	{
		cout << "Error creating new order\n";
		cout << "You must first add products to your Shopping Cart\n";
	}
	else if (!buyer.getCurrentOrder())
		newOrder(buyer);
	else
	{
		cout << "Order already exists, you can only have a maximum of 1 order at a time\n";
		cout << "Enter 1 to cancel existing order and start a new one\n";
		cout << "Enter 2 to leave existing order\n";
		int input;
		cin >> input;
		while (input != 1 && input != 2)
		{
			cout << "Invalid input, please try again: ";
			cin >> input;
		}

		if (input == 1)
		{
			buyer.getShoppingCart().returnItemsToShoppingCart(*buyer.getCurrentOrder());
			buyer.setCurrentOrder(nullptr);
			cout << "Items returned to your shopping cart\n";
			cout << "--------------------------------------------------\n";
			newOrder(buyer);
		}
	}
}
//----------------------------------------------------------------------------------------//
void Menu::publishNewFeedback(Buyer& buyer)
{
	if (buyer.getNumOrders() == 0)
	{
		cout << "No products have been purchased\n";
		cout << "In order to submit a feedback you must first purchase a product\n";
	}
	else
		createFeedback(buyer);
}
//----------------------------------------------------------------------------------------//
void Menu::chargeYourWallet(Buyer& buyer)
{
	cout << "You currently have: $" << buyer.getWallet() << endl;
	cout << "How much do you want to add? $";
	double amount;
	cin >> amount;
	if (buyer.setWallet(amount))
		cout << "Funds added successfully! Your wallet: $" << buyer.getWallet() << endl;
	else
		cout << "Invalid amount entered, top-up denied\n";
}
//----------------------------------------------------------------------------------------//
/*
Once logged in as seller, this method manages the menu of actions for sellers.
*/
void Menu::sellerMenu(Seller& seller)
{
	this->printSellerMenu();

	int selection;
	cin >> selection;

	cout << "--------------------------------------------------\n";

	while (selection != 3)
	{
		switch (selection)
		{
			case 1: /*Add product to store*/
			{
				addProductToStore(seller);
				break;
			}
			case 2: /*Search product by name*/
			{
				searchProductByName();
				break;
			}
			default:
			{
				cout << "Invalid number entered\n";
				break;
			}
		}

		this->printSellerMenu();
		cin >> selection;
	}

	cout << "Logging out...\n";
}
//----------------------------------------------------------------------------------------//
void Menu::printSellerMenu() const
{
	cout << "\t\t _____________\n";
	cout << "\t\t|             |\n";
	cout << "\t\t| SELLER MENU |\n";
	cout << "\t\t|_____________|\n\n";
	cout << "--------------------------------------------------\n";
	cout << "1\tAdd new product to your Store\n";	
	cout << "2\tSearch for product by name\n";		
	cout << "3\tLog-out\n";
	cout << "--------------------------------------------------\n";
	cout << "Enter number of what you would like to do: ";
}
//----------------------------------------------------------------------------------------//
void Menu::addProductToStore(Seller& seller)
{
	Product* new_product = createProduct(seller.getUserName());
	Validation::checkAllocation(new_product);
	if (!seller.addProduct(*new_product))
	{
		delete new_product;
		cout << "Error! Product with this name already exists in your store!\n";
		cout << "Product not added\n";
	}
	else
	{
		m_system->newProduct(*new_product);
		cout << new_product->getName() << " added to your store successfully!\n";
	}
}
//----------------------------------------------------------------------------------------//
void Menu::searchProductByName()
{
	int search = 1;

	while (search == 1)
	{
		cout << "Enter name of product: ";
		char product_name[Product::MAX_PRODUCT_NAME + 1];
		cin.ignore();
		cin.getline(product_name, Product::MAX_PRODUCT_NAME + 1);
		if (!(m_system->productExist(product_name)))
		{
			cout << "There is no " << product_name << " for sale in the system\n";
			cout << "Would you like to try again?\n";
			cout << "1 = Try again, 2 = Back to main menu\n";
			cin >> search;
			while (search != 1 && search != 2)
			{
				cout << "Invalid input\n";
				cin >> search;
			}
		}
		else
		{
			search = 0;
			cout << "--------------------------------------------------\n";
			m_system->printProductsByName(product_name);
		}
	}
}
//----------------------------------------------------------------------------------------//
void Menu::buyerSellerMenu(BuyerSeller& buyerseller)
{
	this->printBuyerSellerMenu();

	int selection;
	cin >> selection;

	cout << "--------------------------------------------------\n";

	while (selection != 6)
	{
		switch (selection)
		{
		case 1:	/*Add item to shopping cart*/
		{
			addItemToShoppingCart(buyerseller);
			break;
		}
		case 2:	/*Create new order*/
		{
			createNewOrder(buyerseller);
			break;
		}
		case 3: /*Pay for existing order*/
		{
			completeOrder(buyerseller);
			break;
		}
		case 4: /*Publish new feedback*/
		{
			publishNewFeedback(buyerseller);
			break;

		}
		case 5: /*Charge your wallet*/
		{
			chargeYourWallet(buyerseller);
			break;

		}
		case 6: /*Add product to store*/
		{
			addProductToStore(buyerseller);
			break;
		}
		case 7: /*Search product by name*/
		{
			searchProductByName();
			break;
		}
		default:
		{
			cout << "Invalid number entered\n";
			break;
		}
		}

		this->printBuyerMenu();
		cin >> selection;
	}

	cout << "Logging out...\n";
}
//----------------------------------------------------------------------------------------//
void Menu::printBuyerSellerMenu() const
{
	cout << "\t\t ___________________\n";
	cout << "\t\t|                   |\n";
	cout << "\t\t| BUYER-SELLER MENU |\n";
	cout << "\t\t|___________________|\n\n";
	cout << "--------------------------------------------------\n";
	cout << "1\tAdd item to your Shopping Cart\n";
	cout << "2\tCreate new order\n";
	cout << "3\tPay for existing order\n";
	cout << "4\tPublish a new feedback\n";
	cout << "5\tCharge wallet\n";
	cout << "6\tAdd new product to your Store\n";	
	cout << "7\tSearch for product by name\n";		
	cout << "8\tLog-out\n";
	cout << "--------------------------------------------------\n";
	cout << "Enter number of what you would like to do: ";
}
//----------------------------------------------------------------------------------------//