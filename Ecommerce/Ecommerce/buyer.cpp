#include "buyer.h"
//----------------------------------------------------------------------------------------//
Buyer::Buyer(const char* username, const char* password, 
	const Address& address) : m_address(address), m_shopping_cart()
{
	setUsername(username);
	setPassword(password);
	m_order= nullptr;
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
const ShoppingCart& Buyer::getShoppingCart() const
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
void Buyer::printBuyerInfo() const
{
	cout << "Username: " << m_username << endl;
	cout << "Address: "; 
	m_address.printAddress();
}
//----------------------------------------------------------------------------------------//
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
		case 0:
			new_shopping_cart[cart_index] = m_shopping_cart.getProductList()[i];
			cart_index++;
			break;
		case 1:
			new_order_product_list[order_index] = m_shopping_cart.getProductList()[i];
			order_index++;
			break;
		}
	}

	m_shopping_cart.setNumProducts(new_shopping_cart_size);
	m_shopping_cart.setProductList(new_shopping_cart);

	m_order = new Order(new_order_product_list, num_of_selected_products, total_price);
}
//----------------------------------------------------------------------------------------//