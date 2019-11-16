#include "address.h"
//----------------------------------------------------------------------------------------//
Address::Address(const char* street_name, const int	house_number, 
			   	 const int zip_code, const char* city, const char* country)
{
	setStreetName(street_name);
	setHouseNumber(house_number);
	setZipCode(zip_code);
	setCity(city);
	setCountry(country);
}
//----------------------------------------------------------------------------------------//
Address::~Address()
{
	delete[] m_street_name;
	delete[] m_city;
	delete[] m_country;	
}
//----------------------------------------------------------------------------------------//
bool Address::setStreetName(const char* street_name)
{
	if (!checkOnlyLetters(strlen(street_name), street_name))
	{
		cout << "Street name can only contain letters\n";
		return false;
	}
	else
	{
		m_street_name = new char[strlen(street_name) + 1];
		strcpy(m_street_name,street_name);
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Address::setHouseNumber(const int house_number)
{
	if (house_number < 1 || house_number > 999)
	{
		cout << "House number must be between 1-3 digits\n";
		return false;
	}
	else
	{
		m_house_number = house_number;
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Address::setZipCode(const int zip_code)
{
	//check if zip code length is valid
	if (zip_code < 1000000 || zip_code > 9999999)
	{
		cout << "Zip code must be 7 digits\n";
		return false;
	}
	else
	{
		m_zip_code = zip_code;
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Address::setCity(const char* city)
{
	if (!checkOnlyLetters(strlen(city), city))
	{
		cout << "City can only contain letters\n";
		return false;
	}
	else
	{
		m_city = new char[strlen(city) + 1];
		strcpy(m_city, city);
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Address::setCountry(const char* country)
{
	if (!checkOnlyLetters(strlen(country), country))
	{
		cout << "Country can only contain letters\n";
		return false;
	}
	else
	{
		m_country = new char[strlen(country) + 1];
		strcpy(m_country, country);
		return true;
	}
}
//----------------------------------------------------------------------------------------//
const char* Address::getStreetName() const
{
	return m_street_name;
}
//----------------------------------------------------------------------------------------//
const int Address::getHouseNumber() const
{
	return m_house_number;
}
//----------------------------------------------------------------------------------------//
const int Address::getZipCode() const
{
	return m_zip_code;
}
//----------------------------------------------------------------------------------------//
const char* Address::getCity() const
{
	return m_city;
}
//----------------------------------------------------------------------------------------//
const char* Address::getCountry() const
{
	return m_country;
}
//----------------------------------------------------------------------------------------//
