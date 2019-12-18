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
	Seller* createSeller();
	Buyer* createBuyer();
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

private:
	System* m_system;

	Menu(const Menu& other); //copy c'tor removed
};
#endif // !__MENU_H
