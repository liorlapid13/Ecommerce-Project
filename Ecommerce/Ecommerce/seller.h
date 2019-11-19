#ifndef __SELLER_H
#define __SELLER_H

#include "helper.h"
#include "address.h"

class Seller
{
public:
	//C'tor
	Seller() = delete;
	Seller(const char* username, const char* password, const Address& address);

	//D'tor
	~Seller();

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

#endif // !__SELLER_H