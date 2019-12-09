#include "buyer.h"
//----------------------------------------------------------------------------------------//
Buyer::Buyer(const char* username, const char* password, 
	const Address& address) : m_address(address), m_shopping_cart()
{
	setUsername(username);
	setPassword(password);
	setWallet(0);
	setNumOrders(0);
	m_current_order = nullptr;
	m_order_history = nullptr;
	
}
//----------------------------------------------------------------------------------------//
/*
Buyer::Buyer(const Buyer& other) : m_address(other.m_address), m_shoppingCart(other.m_shoppingCart)	//copy c'tor
{
	setUsername(other.m_username);
	setPassword(other.m_password);
}
//----------------------------------------------------------------------------------------//
Buyer::Buyer(Buyer&& other) : m_address(other.m_address), m_shoppingCart(other.m_shoppingCart)	//move c'tor
{
	m_username = other.m_username;
	other.m_username = nullptr;
	m_password = other.m_password;
	other.m_password = nullptr;
}
*/
//----------------------------------------------------------------------------------------//
Buyer::~Buyer()
{
	delete[] m_username;
	delete[] m_password;
}
//----------------------------------------------------------------------------------------//
bool Buyer::setWallet(const double funds)
{
	if (funds < 0)
	{
		cout << "Cannot top-up wallet with negative funds\n";
		return false;
	}

	m_wallet = funds;
	return true;
}
//----------------------------------------------------------------------------------------//
bool Buyer::setUsername(const char* username)
{
	//check validity of username
	if (!usernameCheck(username))
		return false;
	else
	{
		delete[] m_username;
		m_username = new char[strlen(username) + 1];
		strcpy(m_username, username);
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Buyer::setPassword(const char* password)
{
	//check validity of password
	if (!passwordCheck(password))
		return false;
	else
	{
		delete[] m_password;
		m_password = new char[strlen(password) + 1];
		strcpy(m_password, password);
		return true;
	}
}
//----------------------------------------------------------------------------------------//
void Buyer::setAddress(const Address& address)
{
	
	m_address.setCity(address.getCity());
	m_address.setCountry(address.getCountry());
	m_address.setHouseNumber(address.getHouseNumber());
	m_address.setZipCode(address.getZipCode());
	m_address.setStreetName(address.getStreetName());
}
//----------------------------------------------------------------------------------------//
void Buyer::setNumOrders(const int num_of_orders)
{
	m_num_of_orders = num_of_orders;
}
//----------------------------------------------------------------------------------------//
ShoppingCart& Buyer::getShoppingCart()
{
	return m_shopping_cart;
}
//----------------------------------------------------------------------------------------//
const char* Buyer::getUserName() const
{
	return m_username;
}
//----------------------------------------------------------------------------------------//
const char* Buyer::getPassword() const
{
	return m_password;
}
//----------------------------------------------------------------------------------------//
Order* Buyer::getCurrentOrder() const
{
	return m_current_order;
}
//----------------------------------------------------------------------------------------//
const Address& Buyer::getAddress() const
{
	return m_address;
}
//----------------------------------------------------------------------------------------//
double Buyer::getWallet() const
{
	return m_wallet;
}
//----------------------------------------------------------------------------------------//
 Order** Buyer::getOrderHistory() const
{
	return m_order_history;
}
//----------------------------------------------------------------------------------------//
int Buyer::getNumOrders() const
{
	return m_num_of_orders;
}
//----------------------------------------------------------------------------------------//
void Buyer::printBuyerInfo() const
{
	cout << "Username: " << m_username << endl;
	cout << "Address: "; 
	m_address.printAddress();
}
//----------------------------------------------------------------------------------------//
/*
Receives a bucket array representing the index of items in the shopping cart, with 1's and 0's.
1=item selected for new order, 0=item not selected.
All 1's will be moved to the order product list, and all 0's will stay in the shopping cart.
*/
void Buyer::createOrder(int num_of_selected_products, int* product_index_array, float total_price)
{
	int new_shopping_cart_size = m_shopping_cart.getNumProducts() - num_of_selected_products;
	Products** new_shopping_cart = new Products*[new_shopping_cart_size];
	Products** new_order_product_list = new Products*[num_of_selected_products];
	
	int cart_index = 0, order_index = 0;

	for (int i = 0; i < m_shopping_cart.getNumProducts(); i++)
	{
		switch (product_index_array[i])
		{
		case 0: //Item not selected in order, stays in shopping cart
			new_shopping_cart[cart_index] = m_shopping_cart.getProductList()[i];
			cart_index++;
			break;
		case 1:	//Item selected in order, move to order product list
			new_order_product_list[order_index] = m_shopping_cart.getProductList()[i];
			order_index++;
			break;
		}
	}
	
	//Update shopping cart
	m_shopping_cart.setNumProducts(new_shopping_cart_size);
	m_shopping_cart.setProductList(new_shopping_cart);

	//Create new order
	m_current_order = new Order(new_order_product_list, num_of_selected_products, total_price);
}
//----------------------------------------------------------------------------------------//
/*
Checks if buyer has enough funds to pay for order
If he does, remove funds from wallet and move the order to order history
*/
bool Buyer::payOrder()
{
	if (getCurrentOrder()->getTotalPrice() > getWallet())
		return false;
	else
	{
		setWallet(getWallet() - (getCurrentOrder()->getTotalPrice()));
		this->addOrderToHistory();
		return true;
	}
}
//----------------------------------------------------------------------------------------//
void Buyer::addOrderToHistory()
{
	if (!m_order_history)	//If empty order list
	{
		m_num_of_orders++;
		m_order_history = new Order*[m_num_of_orders];
		m_order_history[0] = m_current_order;
	}
	else
	{
		Order** temp = new Order*[m_num_of_orders + 1];		//allocate memory for new order list
		for (int i = 0; i < m_num_of_orders; i++)			//copy each existing order to new list
			temp[i] = m_order_history[i];
		temp[m_num_of_orders] = m_current_order;			//add the new order to the new list
		m_num_of_orders++;									//advance the counter for number of orders
		delete[] m_order_history;							//delete the old order list
		m_order_history = temp;								//assign the new order list
		temp = nullptr;										//initialize the temporary pointer
	}

	m_current_order = nullptr;
}
//----------------------------------------------------------------------------------------//
/*
Checks if feedback by this buyer already exists in seller's feedback list.
If not, creates the feedback and adds it to list via a seller class method "addFeedback".
*/
bool Buyer::newFeedback(Products* product, Seller* seller, const char* description, const Date& date)
{
	if (seller->getNumOfFeedbacks() != 0)
	{
		for (int i = 0; i < seller->getNumOfFeedbacks(); i++)
		{
			if (seller->getFeedbackList()[i]->getBuyer() == this && seller->getFeedbackList()[i]->getProduct() == product)
				return false;
		}
	}

	Feedback new_feedback(date, description, *this, *product);
	seller->addFeedback(new_feedback);
	return true;
}
//----------------------------------------------------------------------------------------//