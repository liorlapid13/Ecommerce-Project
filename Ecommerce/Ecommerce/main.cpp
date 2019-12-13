#include <iostream>
#include <string.h>
using namespace std;

#include "menu.h"

void main()
{
	System system("ECOM");

	Address ab1("Haamoraim", 8, 4671234, "Tel-Aviv", "Israel");

	Buyer b1("Lior13", "Aa1234", ab1);
	Buyer b2("Asi123", "Aa1234", ab1);
	Seller s1("Shahar77", "Aa1234", ab1);
	Seller s2("Yosi12", "Aa1234", ab1);

	system.addSeller(s1);
	system.addSeller(s2);
	system.addBuyer(b1);
	system.addBuyer(b2);

	Menu menu(&system);

	menu.mainMenu();
}