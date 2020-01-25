#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <fstream>

#include "validation.h"

class Address
{
public:
	//C'tors
	Address() = delete;
	Address(const string& street_name,
			int	house_number,
			int	zip_code,
			const string& city,
			const string& country);

	//Setters
	bool setStreetName(const string& street_name);
	bool setHouseNumber(const int house_number);
	bool setZipCode(const int zip_code);
	bool setCity(const string& city);
	bool setCountry(const string& country);

	//Getters
	const string&	getStreetName()		const;
    int				getHouseNumber()	const;
	int				getZipCode()		const;
    const string&	getCity()			const;
    const string&	getCountry()		const;

	//QUESTION 8&9
	void printAddress()					const;

	//Operators
	friend ostream& operator<<(ostream& os, const Address& address);

	//Files
	void writeAddress(ofstream& out_file) const;

private:
	int		m_house_number;
	int		m_zip_code;
	string	m_street_name;
	string	m_city;
	string	m_country;
};

#endif // !__ADDRESS_H