#ifndef __USER_H
#define __USER_H

#include "address.h"

class User 
{
public:
	//C'tors
	User() = delete;
	
	//D'tor
	virtual ~User();

	//Setters
	bool setUsername(const char* username);
	bool setPassword(const char* password);
	void setAddress(const Address& address);

	//Getters
	virtual const char*		getUserName()	const = 0;
	virtual const char*		getPassword()	const = 0;
	virtual const Address&	getAddress()	const = 0;

	//Functions
	virtual void show() const = 0;
	
protected:
	char* m_username;
	char* m_password;
	Address m_address;

	//Abstract class, only inheritors can access the c'tor
	User(const char* username, const char* password, const Address& address); 

private:
	
};

#endif // !__USER_H
