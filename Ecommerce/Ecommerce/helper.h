#ifndef __HELPER_H
#define __HELPER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "buyer.h"
#include "address.h"

bool passwordCheck(const char* password);
bool usernameCheck(const char* username);
bool checkOnlyLetters(const int length, const char* string);

#endif // !__HELPER_H