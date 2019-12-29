#include "buyerseller.h"
//----------------------------------------------------------------------------------------//
BuyerSeller::BuyerSeller(const char* username, const char* password, const Address& address) : User(username, password, address),
	Buyer(username, password, address), Seller(username, password, address)
{

}
//----------------------------------------------------------------------------------------//
BuyerSeller::~BuyerSeller()
{

}
//----------------------------------------------------------------------------------------//
const char* BuyerSeller::getUserName() const
{
	return m_username;
}
//----------------------------------------------------------------------------------------//
const char* BuyerSeller::getPassword() const
{
	return m_password;
}
//----------------------------------------------------------------------------------------//
const Address& BuyerSeller::getAddress() const
{
	return m_address;
}
//----------------------------------------------------------------------------------------//
void BuyerSeller::show() const
{
	User::show();
	Buyer::showMe();
	Seller::showMe();
}
//----------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------//
