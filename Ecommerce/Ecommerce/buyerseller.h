#ifndef __BUYERSELLER_H
#define __BUYERSELLER_H

#include "buyer.h"

class BuyerSeller : public Buyer, public Seller
{
public:
	//C'tors
	BuyerSeller() = delete;
	BuyerSeller(const char* username, const char* password, const Address& address);

	//D'tor
	~BuyerSeller();

	//Setters

	//Getters
	const char*		getUserName()			const override;
	const char*		getPassword()			const override;
	const Address&	getAddress()			const override;

	//Methods
	void show()								const override;

private:
	BuyerSeller(const BuyerSeller& other); //remove copy c'tor
};

#endif // !__BUYERSELLER_H
