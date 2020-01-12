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

	//Methods
	void show()	const override;

private:
	BuyerSeller(const BuyerSeller& other);
	const BuyerSeller& operator=(const BuyerSeller& other) = delete;
};

#endif // !__BUYERSELLER_H
