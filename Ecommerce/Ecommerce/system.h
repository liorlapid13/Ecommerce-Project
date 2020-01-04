#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "validation.h"
#include "buyerseller.h"

class System
{
public:
	//C'tors
	System() = delete;
	System(const char* name);

	//D'tor
	~System();

	//Setters
	void setName(const char* name);

	//Getters
	const char* getName()			const;
	User**		getUserList();
	int			getNumOfUsers()		const;
	Product**	getProductList();
	int			getNumOfProducts()	const;


	//Methods
	void addUser(User& new_user);
	bool searchUsername(char* username)						const;
	void newProduct(Product& new_product);
	void printBuyerSellerList()								const;
	void printSellerList()									const;
	void printBuyerList()									const;
	Seller* findSeller(const char* username)				const;
	Buyer* findBuyer(const char* username)					const;
	BuyerSeller* findBuyerSeller(const char* username)		const;
	void printProductsByName(char* product_name)			const;	//->Products.printProduct
	Product* findProduct(int serial_number, char* name)		const;
	bool productExist(const char* product_name)				const;
	
	Buyer* pickBuyer() const;

	//Operators
	void operator+=(Buyer& buyer);
	void operator+=(Seller& seller);
	void operator+=(BuyerSeller& buyerseller);

private:
	char*		m_name;
	User**		m_user_list;
	int			m_num_of_users;
	Product**	m_product_list;
	int			m_num_of_products;
	
	System(const System& other);	//copy c'tor removed
};













#endif // !__SYSTEM_H

