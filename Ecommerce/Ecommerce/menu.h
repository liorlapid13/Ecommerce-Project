#ifndef __MENU_H
#define __MENU_H

#include "validation.h"
#include "buyer.h"
#include "seller.h"
#include "system.h"
#include "products.h"
#include "shopping_cart.h"

class Menu
{

public:
	static const int MAX_PRODUCT_NAME = 30;
	static const int MAX_FEEDBACK_LENGTH = 250;

	//Setters

	Menu(System* system);
	~Menu();
	
	System* getSystem();
	Seller* createSeller();
	Buyer* createBuyer();
	Products* createProduct();
	void newOrder(Buyer& buyer);
	void completeOrder(Buyer& buyer);
	void createFeedback(Buyer& buyer);
	void mainMenu();
	void signUp(int user_type);
	void logIn(int user_type);
	void buyerMenu(Buyer& buyer);
	void sellerMenu(Seller& seller);

private:
	System* m_system;
	Menu(const Menu& other);
};
#endif // !__MENU_H
