#ifndef __ADDRESS_H
#define __ADDRESS_H

#include "validation.h"

class Address
{
public:
	//C'tors
	Address() = delete;
	Address(const char* street_name,
			int	house_number,
			int	zip_code,
			const char* city,
			const char* country);
	Address(const Address& other);	//copy c'tor
	Address(Address&& other);		//move c'tor

	//D'tors
	~Address();

public:
	//Setters
	bool setStreetName(const char* street_name);
	bool setHouseNumber(const int house_number);
	bool setZipCode(const int zip_code);
	bool setCity(const char* city);
	bool setCountry(const char* country);

	//Getters
	const char*	getStreetName()		const;
    int			getHouseNumber()	const;
	int			getZipCode()		const;
    const char*	getCity()			const;
    const char*	getCountry()		const;

	//QUESTION 8&9
	void printAddress()				const;

	//Operators
	friend ostream& operator<<(ostream& os, const Address& address);
	const Address& operator=(const Address& other);

private:
	char*	m_street_name;
	int		m_house_number;
	int		m_zip_code;
	char*	m_city;
	char*	m_country;
};

#endif // !__ADDRESS_H