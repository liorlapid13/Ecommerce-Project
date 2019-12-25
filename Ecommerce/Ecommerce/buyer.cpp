#include "buyer.h"
//----------------------------------------------------------------------------------------//
Buyer::Buyer(const char* username, const char* password, const Address& address) :User(username, password, address), m_shopping_cart()
{
	setWallet(0);
	setNumOrders(0);
	setCurrentOrder(nullptr);
	m_order_history = nullptr;
}
//----------------------------------------------------------------------------------------//
Buyer::~Buyer()
{
	delete m_current_order;

	for (int i = 0; i < m_num_of_orders; i++)
		delete m_order_history[i];

	delete[] m_order_history;
}
//----------------------------------------------------------------------------------------//
bool Buyer::setWallet(const double funds)
{
	if (funds <= 0)
		return false;

	m_wallet += funds;
	return true;
}
//----------------------------------------------------------------------------------------//
void Buyer::setNumOrders(const int num_of_orders)
{
	m_num_of_orders = num_of_orders;
}
//----------------------------------------------------------------------------------------//
void Buyer::setCurrentOrder(Order* order)
{
	m_current_order = order;
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
const Address& Buyer::getAddress() const
{
	return m_address;
}
//----------------------------------------------------------------------------------------//
Order* Buyer::getCurrentOrder() const
{
	return m_current_order;
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
void Buyer::show() const
{
	User::show();
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
	Product** new_shopping_cart = new Product*[new_shopping_cart_size];
	Validation::checkAllocation(new_shopping_cart);
	Product** new_order_product_list = new Product*[num_of_selected_products];
	Validation::checkAllocation(new_order_product_list);
	
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
	Validation::checkAllocation(m_current_order);
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
/*
After current order has been paid for, this method moves the order into the buyer's order history.
*/
void Buyer::addOrderToHistory()
{
	if (!m_order_history)	//If empty order list
	{
		m_num_of_orders++;
		m_order_history = new Order*[m_num_of_orders];
		Validation::checkAllocation(m_order_history);
		m_order_history[0] = m_current_order;
	}
	else
	{
		Order** temp = new Order*[m_num_of_orders + 1];		//allocate memory for new order list
		Validation::checkAllocation(temp);
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
bool Buyer::newFeedback(Product* product, Seller* seller, const char* description, const Date& date)
{
	if (seller->getNumOfFeedbacks() != 0)
	{
		for (int i = 0; i < seller->getNumOfFeedbacks(); i++)
		{
			if (seller->getFeedbackList()[i]->getBuyer() == this && seller->getFeedbackList()[i]->getProduct() == product)
				return false;
		}
	}

	Feedback* new_feedback= new Feedback(date, description, *this, *product);
	seller->addFeedback(*new_feedback);
	return true;
}
//----------------------------------------------------------------------------------------//