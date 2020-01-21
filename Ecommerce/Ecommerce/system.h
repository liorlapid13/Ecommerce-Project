#ifndef __SYSTEM_H
#define __SYSTEM_H

#include "validation.h"
#include "buyerseller.h"

class System
{
public:
	//C'tors
	System() = delete;
	System(const string& name);

	//D'tor
	~System();

	//Setters
	void setName(const string& name);

	//Getters
	const string&		getName()			const;
	vector<User*>&		getUserList();
	int					getNumOfUsers()		const;
	vector<Product*>&	getProductList();
	int					getNumOfProducts()	const;


	//Methods
	void addUser(User& new_user);
	bool searchUsername(const string& username)				const;
	void newProduct(Product& new_product);
	void printBuyerSellerList()								const;
	void printSellerList()									const;
	void printBuyerList()									const;
	Seller* findSeller(const string& username)				const;
	Buyer* findBuyer(const string& username)				const;
	BuyerSeller* findBuyerSeller(const string& username)	const;
	void printProductsByName(const string& product_name)	const;	//->Products.printProduct
	Product* findProduct(int serial_number, const string& product_name)	const;
	bool productExist(const string& product_name)			const;
	
	Buyer* pickBuyer(int buyer_number)						const;

	//Operators
	void operator+=(const Buyer& buyer);
	void operator+=(const Seller& seller);
	void operator+=(const BuyerSeller& buyerseller);

private:
	string				m_name;
	vector<User*>		m_user_list;
	vector<Product*>	m_product_list;
	
	System(const System& other);
	const System& operator=(const System& other) = delete;
};













#endif // !__SYSTEM_H

