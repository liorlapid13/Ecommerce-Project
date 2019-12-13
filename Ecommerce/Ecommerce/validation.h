#ifndef __VALIDATION_H
#define __VALIDATION_H

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

#pragma warning(disable: 4996)

class Validation
{
public:
	static const int MIN_USERNAME_LENGTH = 6;
	static const int MAX_USERNAME_LENGTH = 15;
	static const int MIN_PASSWORD_LENGTH = 6;
	static const int MAX_PASSWORD_LENGTH = 15;
	static const int MAX_STREET_LENGTH = 100;
	static const int MAX_COUNTRY_LENGTH = 30;
	static const int MAX_CITY_LENGTH = 30;

	static bool passwordCheck(const char* password);
	static bool usernameCheck(const char* username);
	static bool checkString(const int length, const char* string);
	static void checkAllocation(void* ptr);
};

#endif // !__VALIDATION_H
