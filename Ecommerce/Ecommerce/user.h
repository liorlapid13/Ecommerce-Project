#ifndef __USER_H
#define __USER_H

#include "address.h"

class User 
{
public:
	//C'tor
	User() = delete;

	//D'tor
	virtual ~User();

	//Setters
	bool setUsername(const string& username);
	bool setPassword(const string& password);
	void setAddress(const Address& address);

	//Getters
	const string&		getUserName()	const;
	const string&		getPassword()	const;
	const Address&		getAddress()	const;

	//Methods
	virtual void show() const = 0;
	
	//Operators
	const User& operator=(const User& other);
	const User& operator=(User&& other);

	//Files
	void writeUser(ofstream& out_file) const;

protected:
	string m_username;
	string m_password;
	Address m_address;

	//C'tors (abstract class)
	User(const string& username, const string& password, const Address& address);
	User(const User& other);
	User(User&& other);
};

#endif // !__USER_H
