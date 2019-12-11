#ifndef __VALIDATION_H
#define __VALIDATION_H

#include <iostream>
#include <string.h>
using namespace std;

#pragma warning(disable: 4996)

const int MIN_USERNAME_LENGTH = 7;
const int MAX_USERNAME_LENGTH = 15;
const int MIN_PASSWORD_LENGTH = 6;
const int MAX_PASSWORD_LENGTH = 15;
const int MAX_STREET_LENGTH = 100;
const int MAX_COUNTRY_LENGTH = 30;
const int MAX_CITY_LENGTH = 30;

bool passwordCheck(const char* password);
bool usernameCheck(const char* username);
bool checkString(const int length, const char* string);
bool checkAllocation(void* ptr);

#endif // !__VALIDATION_H
