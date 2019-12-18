#include <iostream>
#include <string.h>
using namespace std;

#include "menu.h"
#include <crtdbg.h>

#pragma warning(disable: 4996)

void main()
{
	System system("ECOM");
	/*
	Address ab1("Haamoraim", 8, 4671234, "Tel-Aviv", "Israel");

	Buyer b1("buyer1", "Aa1234", ab1);
	Buyer b2("buyer2", "Aa1234", ab1);
	Seller s1("seller1", "Aa1234", ab1);
	Seller s2("seller2", "Aa1234", ab1);

	system.addSeller(s1);
	system.addSeller(s2);
	system.addBuyer(b1);
	system.addBuyer(b2);
	 */

	Menu menu(&system);

	menu.mainMenu();
	cout << _CrtDumpMemoryLeaks();
	std::system("pause");

}