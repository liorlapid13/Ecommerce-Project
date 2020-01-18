#include "buyerseller.h"
//----------------------------------------------------------------------------------------//
BuyerSeller::BuyerSeller(const string& username, const string& password, const Address& address) : User(username, password, address),
	Buyer(username, password, address), Seller(username, password, address)
{

}
//----------------------------------------------------------------------------------------//
BuyerSeller::BuyerSeller(const BuyerSeller& other) :User(other), Buyer(other), Seller(other)
{

}
//----------------------------------------------------------------------------------------//
BuyerSeller::BuyerSeller(BuyerSeller&& other) :User(move(other)), Buyer(move(other)), Seller(move(other))
{

}
//----------------------------------------------------------------------------------------//
BuyerSeller::~BuyerSeller()
{

}
//----------------------------------------------------------------------------------------//
void BuyerSeller::show() const
{
	User::show();
	Buyer::showMe();
	Seller::showMe();
}
//----------------------------------------------------------------------------------------//
const BuyerSeller& BuyerSeller::operator=(const BuyerSeller& other)
{
	if (this != &other)
	{
		Buyer::operator=(other);
		Seller::operator=(other);
	}

	return *this;
}
//----------------------------------------------------------------------------------------//
const BuyerSeller& BuyerSeller::operator=(BuyerSeller&& other)
{
	if (this != &other)
	{
		Buyer::operator=(move(other));
		Seller::operator=(move(other));
	}

	return *this;
}
//----------------------------------------------------------------------------------------//
