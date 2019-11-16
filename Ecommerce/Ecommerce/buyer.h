#ifndef __BUYER_H
#define __BUYER_H

#include "helper.h"

class Buyer
{
public:
<<<<<<< Updated upstream
	static const int MIN_USERNAME_LENGTH = 7;
	static const int MAX_USERNAME_LENGTH = 15;
	static const int MIN_PASSWORD_LENGTH = 6;
	static const int MAX_PASSWORD_LENGTH = 15;
	

public:
	Buyer(const char* username,const char* password, Address& address);
=======
	//C'tor
	Buyer(const char* username,const char* password, const Address& address);
>>>>>>> Stashed changes
	
	//D'tor
	~Buyer();

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