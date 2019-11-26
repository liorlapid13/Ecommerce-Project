#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "helper.h"
#include "buyer.h"
#include "seller.h"

class System
{
public:
	//C'tor
	System() = delete;
	System(const char* name);

	//D'tor
	~System();

	//Setters
	bool setName(const char* name);

	//Getters
	inline const char* getName()		const;
	inline Buyer** getBuyerList();
	inline const int getNumOfBuyers()	const;
	inline Seller** getSellerList();
	inline const int getNumOfSellers()	const;

	//QUESTION 2
	Seller createSeller();
	void addSeller(Seller& new_seller);
	bool searchUsername(char* username)	const;

private:
	char*		m_name;
	Buyer**		m_buyer_list;
	int			m_num_of_buyers;
	Seller**	m_seller_list;
	int			m_num_of_sellers;
	
	System(const System& other);	//remove copy c'tor
};













#endif // !__SYSTEM_H

