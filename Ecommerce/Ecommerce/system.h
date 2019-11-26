#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "helper.h"
#include "buyer.h"
#include "seller.h"

class System
{

public:
	//C'tor
	System(const char* name);

	//D'tor
	~System();


	bool setName(const char* name);

	inline const char* getName()			const;
	inline const  Buyer** getBuyersArray();
	inline const int getNumOfBuyers()		const;
	inline const Seller** getSellersArray();
	inline const int getNumOfSellers()		const;




private:

	char* m_name;
	Buyer** m_buyers_array;
	int m_num_of_buyers;
	Seller** m_sellers_array;
	int m_num_of_sellers;
	
};













#endif // !__SYSTEM_H

