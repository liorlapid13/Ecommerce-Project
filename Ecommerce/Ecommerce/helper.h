#ifndef __HELPER_H
#define __HELPER_H

#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

#include "buyer.h"
#include "address.h"
#include "seller.h"
#include "system.h"
#include "products.h"
#include "shopping_cart.h"

const int MIN_USERNAME_LENGTH = 7;
const int MAX_USERNAME_LENGTH = 15;
const int MIN_PASSWORD_LENGTH = 6;
const int MAX_PASSWORD_LENGTH = 15;
const int NUM_OF_CATEGORIES = 4;	//product categories
const int MAX_STREET_LENGTH = 100;
const int MAX_COUNTRY_LENGTH = 30;
const int MAX_CITY_LENGTH = 30;
const int MAX_PRODUCT_NAME = 30;
const int MAX_FEEDBACK_LENGTH = 250;

bool passwordCheck(const char* password);
bool usernameCheck(const char* username);
bool checkString(const int length, const char* string);
Seller* createSeller(System& system);
Buyer* createBuyer(System& system);
Products* createProduct();
void newOrder(Buyer& buyer);
void completeOrder(Buyer& buyer);
void createFeedback(Buyer& buyer, System& system);

#endif // !__HELPER_H