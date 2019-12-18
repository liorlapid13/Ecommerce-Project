#include <iostream>
#include <string.h>
using namespace std;

#include "menu.h"

#pragma warning(disable: 4996)

void main()
{
	System system("ECOM");

	Menu menu(&system);

	menu.mainMenu();
}