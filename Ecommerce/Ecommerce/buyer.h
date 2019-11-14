#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "helper.h"


/*
static const int MAX_STRING_LENGTH = 255; //for address

struct Address
{
	char* street_name;
	int house_number;
	int zip_code;
	char* city;
	char* country;
};
*/
class Buyer
{
public:
	static const int MIN_USERNAME_LENGTH = 7;
	static const int MAX_USERNAME_LENGTH = 15;
	static const int MIN_PASSWORD_LENGTH = 6;
	static const int MAX_PASSWORD_LENGTH = 15;
	

public:
	Buyer(const char* username,const char* password, Address& address);
	
public:
	bool setUsername(const char* username);
	bool setPassword(const char* password);
	bool setAddress(Address& address);

private:
	char* m_username;
	char* m_password;
	Address m_address;
};











#endif // __BUYER_H