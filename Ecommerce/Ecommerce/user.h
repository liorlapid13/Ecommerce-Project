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
	const char*		getUserName()	const;
	const char*		getPassword()	const;
	const Address&	getAddress()	const;

	//Methods
	virtual void show() const = 0;
	
	//Operators
	const User& operator=(const User& other);
	const User& operator=(User&& other);

protected:
	char* m_username;
	char* m_password;
	Address m_address;

	//C'tors (abstract class)
	User(const char* username, const char* password, const Address& address);
	User(const User& other);
	User(User&& other);
};

#endif // !__USER_H
