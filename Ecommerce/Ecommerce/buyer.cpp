#include "buyer.h"
//----------------------------------------------------------------------------------------//
Buyer::Buyer(const string& username, const string& password, const Address& address) 
		:User(username, password, address), m_shopping_cart()
{
	setWallet(0);
	setCurrentOrder(nullptr);
}
//----------------------------------------------------------------------------------------//
Buyer::Buyer(const Buyer& other) :User(other), m_shopping_cart(other.m_shopping_cart)
{
	m_wallet = other.m_wallet;
	m_current_order = new Order(*other.m_current_order);

	for (auto s : other.m_order_history)
		m_order_history.push_back(new Order(*s));
}
//----------------------------------------------------------------------------------------//
Buyer::Buyer(Buyer&& other) :User(move(other)), m_shopping_cart(other.m_shopping_cart)
{
	m_wallet = other.m_wallet;
	m_current_order = other.m_current_order;
	other.m_current_order = nullptr;

	m_order_history = move(other.m_order_history);
	other.m_order_history.clear();
}
//----------------------------------------------------------------------------------------//
Buyer::~Buyer()
{
	delete m_current_order;

	vector<Order*>::iterator itr = m_order_history.begin();
	vector<Order*>::iterator itrEnd = m_order_history.end();

	for (; itr != itrEnd; ++itr)
		delete *itr;
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
 vector<Order*>& Buyer::getOrderHistory()
{
	return m_order_history;
}
//----------------------------------------------------------------------------------------//
int Buyer::getNumOrders() const
{
	return m_order_history.size();
}
//----------------------------------------------------------------------------------------//
void Buyer::show() const
{
	User::show();
	showMe();
}
//----------------------------------------------------------------------------------------//
void Buyer::showMe() const
{
	cout << "\tWallet: " << m_wallet << endl;
	cout << "\tOrders completed: " << m_order_history.size() << endl;
}
//----------------------------------------------------------------------------------------//
/*
Receives a bucket array representing the index of items in the shopping cart, with 1's and 0's.
1=item selected for new order, 0=item not selected.
All 1's will be moved to the order product list, and all 0's will stay in the shopping cart.
*/
void Buyer::createOrder(vector<int> product_index_array, float total_price)
{
	vector<Product*> new_shopping_cart;
	vector<Product*> new_order_product_list;
	
	vector<int>::iterator itrIndex = product_index_array.begin();
	vector<Product*>::iterator itr = m_shopping_cart.getProductList().begin();
	vector<Product*>::iterator itrEnd = m_shopping_cart.getProductList().end();

	for (; itr != itrEnd; ++itr, ++itrIndex)
	{
		switch (*itrIndex)
		{
		case 0: //Item not selected in order, stays in shopping cart
			new_shopping_cart.push_back(*itr);
			break;
		case 1:	//Item selected in order, move to order product list
			new_order_product_list.push_back(*itr);
			break;
		}
	}
	
	//Update shopping cart
	m_shopping_cart.setProductList(new_shopping_cart);
	m_shopping_cart.setTotalPrice(m_shopping_cart.getTotalPrice() - total_price);

	//Create new order
	m_current_order = new Order(new_order_product_list, total_price);
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
	m_order_history.push_back(m_current_order);
	m_current_order = nullptr;
}
//----------------------------------------------------------------------------------------//
/*
Checks if feedback by this buyer already exists in seller's feedback list.
If not, creates the feedback and adds it to list via a seller class method "addFeedback".
*/
bool Buyer::newFeedback(Product* product, Seller* seller, const string& description, const Date& date)
{
	if (seller->getNumOfFeedbacks() != 0)
	{
		vector<Feedback*>::iterator itr = seller->getFeedbackList().begin();
		vector<Feedback*>::iterator itrEnd = seller->getFeedbackList().end();

		for (; itr != itrEnd; ++itr)
		{
			if ((*itr)->getBuyer() == this && (*itr)->getProduct() == product)
				return false;
		}
	}

	Feedback* new_feedback= new Feedback(date, description, *this, *product);
	seller->addFeedback(*new_feedback);
	return true;
}
//----------------------------------------------------------------------------------------//
bool Buyer::operator>(const Buyer& other) const
{
	if (this->m_shopping_cart.getTotalPrice() > other.m_shopping_cart.getTotalPrice())
		return true;
	return false;
}
//----------------------------------------------------------------------------------------//
const Buyer& Buyer::operator=(const Buyer& other)
{
	if (this != &other)
	{
		User::operator=(other);
		m_wallet = other.m_wallet;
		
		delete m_current_order;
		if (other.m_current_order)
			m_current_order = new Order(*other.m_current_order);
		else
			m_current_order = nullptr;

		vector<Order*>::iterator itr = m_order_history.begin();
		vector<Order*>::iterator itrEnd = m_order_history.end();

		for (; itr != itrEnd; ++itr)
			delete *itr;

		m_order_history.clear();

		for (auto s : other.m_order_history)
			m_order_history.push_back(new Order(*s));

		m_shopping_cart = other.m_shopping_cart;
	}

	return *this;
}
//----------------------------------------------------------------------------------------//
const Buyer& Buyer::operator=(Buyer&& other)
{
	if (this != &other)
	{
		User::operator=(move(other));
		m_wallet = other.m_wallet;
		
		delete m_current_order;
		m_current_order = other.m_current_order;
		other.m_current_order = nullptr;

		vector<Order*>::iterator itr = m_order_history.begin();
		vector<Order*>::iterator itrEnd = m_order_history.end();

		for (; itr != itrEnd; ++itr)
			delete *itr;

		m_order_history.clear();

		m_order_history = move(other.m_order_history);
		other.m_order_history.clear();

		m_shopping_cart = other.m_shopping_cart;
	}

	return *this;
}
//----------------------------------------------------------------------------------------//