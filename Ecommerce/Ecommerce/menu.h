#ifndef __MENU_H
#define __MENU_H

#include "validation.h"
#include "system.h"

class Menu
{
public:
	//Constants
	static const int MAX_FEEDBACK_LENGTH = 250;

	//C'tors
	Menu() = delete;
	Menu(System* system);

	//D'tor
	~Menu();
	
	//Getters
	System* getSystem()	const;

	//Methods
	User* createUser(int user_type);
	Product* createProduct(const char* seller_username);
	void newOrder(Buyer& buyer);
	void completeOrder(Buyer& buyer);
	void createFeedback(Buyer& buyer);
	void mainMenu();
	void signUp(int user_type);
	void logIn(int user_type);
	void buyerMenu(Buyer& buyer);
	void printBuyerMenu()					const;
	void sellerMenu(Seller& seller);
	void printSellerMenu()					const;
	void buyerSellerMenu(BuyerSeller& buyerseller);
	void printBuyerSellerMenu()				const;
	void addProductToShoppingCart(Buyer& buyer);
	void createNewOrder(Buyer& buyer);
	void publishNewFeedback(Buyer& buyer);
	void chargeYourWallet(Buyer& buyer);
	void addProductToStore(Seller& seller);
	void searchProductByName();
	void operatorTests();
	void printOperatorTestsMenu()			const;
	void shoppingCartCompareOperatorTest()	const;
	void printOperatorTest();
	void addUserOperatorTest();

private:
	System* m_system;

	Menu(const Menu& other);
	const Menu& operator=(const Menu& other) = delete;
};
#endif // !__MENU_H
