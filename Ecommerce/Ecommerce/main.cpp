#include <iostream>
#include <string.h>
using namespace std;

#include "menu.h"

void main()
{
	System system("ECOM");
	Menu menu(&system);

	menu.mainMenu();
}