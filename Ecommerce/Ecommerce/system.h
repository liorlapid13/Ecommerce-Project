#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "validation.h"
#include "buyer.h"


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
	const char* getName()					const;
	Buyer** getBuyerList();
	int getNumOfBuyers()					const;
	Seller** getSellerList();
	int getNumOfSellers()					const;

	//QUESTIONS 1,2
	void addSeller(Seller& new_seller);
	void addBuyer(Buyer& new_buyer);
	bool searchUsername(char* username)				const;

	//QUESTION 3
	void newProduct(Product& new_product);

	//QUESTION 4
	Seller* findSeller(const char* username)		const;

	//Log-In
	Buyer* findBuyer(const char* username)			const;

	//QUESTIONS 8,9
	void printSellerList()							const;	//->Seller.printSellerInfo
	void printBuyerList()							const;	//->Buyer.printBuyerInfo

	//QUESTION 10
	void printProductsByName(char* product_name)	const;	//->Products.printProduct

	//QUESTION 5
	Product* findProduct(int serial_number)		const;
	

private:
	char*		m_name;
	Buyer**		m_buyer_list;
	int			m_num_of_buyers;
	Seller**	m_seller_list;
	int			m_num_of_sellers;
	Product**	m_product_list;
	int			m_num_of_products;
	
	System(const System& other);	//remove copy c'tor
};













#endif // !__SYSTEM_H

