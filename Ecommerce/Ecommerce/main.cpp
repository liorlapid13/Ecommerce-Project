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

void main()
{
		System system("ECOM");
		
		int input;
		cout << "Enter 1 to read user list from file or 2 to continue: ";
		cin >> input;

		while (input != 1 && input != 2)
		{
			cout << "Invalid input, please try again: ";
			cin >> input;
		}

		if (input == 1)
			system.loadUserList("User_list.txt");

		cout << "--------------------------------------------------\n";

		Menu menu(&system);

		menu.mainMenu();
}