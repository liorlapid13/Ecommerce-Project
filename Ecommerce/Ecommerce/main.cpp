/*
E-Commerce project written by:
Shahar Chalfon
ID: 204351845

Lior Lapid
ID: 316266055

Both students:
Group: A
Day: Sunday
Proffessor: Keren Kalif

Project information and user guide are located in the attached README file
*/

#include <iostream>
#include <string.h>
using namespace std;

#include "menu.h"

#pragma warning(disable: 4996)

#include <crtdbg.h>

void main()
{
	{
		System system("ECOM");

		Menu menu(&system);

		menu.mainMenu();

	}
	
	cout << _CrtDumpMemoryLeaks();
	cout << endl;
	system("pause");
	
}