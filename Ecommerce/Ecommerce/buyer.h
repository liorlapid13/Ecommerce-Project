#ifndef __BUYER_H
#define __BUYER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "helper.h"
#include "address.h"

class Buyer
{
public:
	static const int MIN_USERNAME_LENGTH = 7;
	static const int MAX_USERNAME_LENGTH = 15;
	static const int MIN_PASSWORD_LENGTH = 6;
	static const int MAX_PASSWORD_LENGTH = 15;

public:
	//C'tor
	Buyer(const char* username,const char* password, const Address& address);
	
public:
	//Setters
	bool setUsername(const char* username);
	bool setPassword(const char* password);
	bool setAddress(const Address& address);

	inline const char* getUserName()  const;
	inline const char* getPassword()  const;
	inline const Address getAddress() const;

private:
	char* m_username;
	char* m_password;
	Address m_address;
};

#endif // __BUYER_H