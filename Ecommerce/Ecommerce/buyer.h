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