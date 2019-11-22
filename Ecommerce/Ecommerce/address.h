#ifndef __ADDRESS_H
#define __ADDRESS_H

#include "helper.h"

class Address
{
public:
	//C'tors
	Address() = delete;
	Address(const char* street_name,
		const int	house_number,
		const int	zip_code,
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
	inline const char*	getStreetName()		const;
	inline const int	getHouseNumber()	const;
	inline const int	getZipCode()		const;
	inline const char*	getCity()			const;
	inline const char*	getCountry()		const;


private:
	char*	m_street_name;
	int		m_house_number;
	int		m_zip_code;
	char*	m_city;
	char*	m_country;
};

#endif // !__ADDRESS_H