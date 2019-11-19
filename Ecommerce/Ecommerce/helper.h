#ifndef __HELPER_H
#define __HELPER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "buyer.h"
#include "address.h"

static const int MIN_USERNAME_LENGTH = 7;
static const int MAX_USERNAME_LENGTH = 15;
static const int MIN_PASSWORD_LENGTH = 6;
static const int MAX_PASSWORD_LENGTH = 15;
static const int NUM_OF_CATEGORIES = 4;	//product categories

bool passwordCheck(const char* password);
bool usernameCheck(const char* username);
bool checkOnlyLetters(const int length, const char* string);

#endif // !__HELPER_H