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

	//QUESTIONS 1,2
	void addSeller(Seller& new_seller);
	void addBuyer(Buyer& new_buyer);
	bool searchUsername(char* username)	const;

	//QUESTIONS 8,9
	void printSellerList()				const;	//->Seller.printSellerInfo
	void printBuyerList()				const;	//->Buyer.printBuyerInfo

private:
	char*		m_name;
	Buyer**		m_buyer_list;
	int			m_num_of_buyers;
	Seller**	m_seller_list;
	int			m_num_of_sellers;
	
	System(const System& other);	//remove copy c'tor
};













#endif // !__SYSTEM_H

