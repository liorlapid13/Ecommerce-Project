#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

#include "menu.h"

void main()
{
	System system("ECOM");
	Menu menu(&system);

	menu.mainMenu();


}