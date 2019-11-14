#ifndef __HELPER_H
#define __HELPER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "buyer.h"

static const int MAX_STRING_LENGTH = 255; //for address

struct Address
{
	char* street_name;
	int house_number;
	int zip_code;
	char* city;
	char* country;
};

bool passwordCheck(const char* password);
bool usernameCheck(const char* username);
bool addressCheck(Address& address);
bool checkOnlyLetters(int length, char* string);

#endif // !__HELPER_H