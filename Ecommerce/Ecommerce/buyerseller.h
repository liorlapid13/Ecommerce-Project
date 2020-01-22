#ifndef __BUYERSELLER_H
#define __BUYERSELLER_H

#include "buyer.h"

class BuyerSeller : public Buyer, public Seller
{
public:
	friend class System;

	//C'tors
	BuyerSeller() = delete;
	BuyerSeller(const string& username, const string& password, const Address& address);

	//Methods
	void show()	const override;

private:
	BuyerSeller(const BuyerSeller& other);
	BuyerSeller(BuyerSeller&& other);

	//Operators
	const BuyerSeller& operator=(const BuyerSeller& other);
	const BuyerSeller& operator=(BuyerSeller&& other);
};

#endif // !__BUYERSELLER_H
