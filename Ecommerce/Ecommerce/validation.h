#ifndef __VALIDATION_H
#define __VALIDATION_H

#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

#pragma warning(disable: 4996)

class Validation
{
public:
	//Constants
	static const int MAX_STRING_LENGTH = 50;
	static const int MIN_USERNAME_LENGTH = 6;
	static const int MAX_USERNAME_LENGTH = 24;
	static const int MIN_PASSWORD_LENGTH = 6;
	static const int MAX_PASSWORD_LENGTH = 15;
	static const int MAX_STREET_LENGTH = 100;
	static const int MAX_COUNTRY_LENGTH = 30;
	static const int MAX_CITY_LENGTH = 30;

	//Methods
	static bool passwordCheck(const string& password);
	static bool usernameCheck(const string& username);
	static bool checkString(const string& string);
	static void checkAllocation(void* ptr);
};

#endif // !__VALIDATION_H
