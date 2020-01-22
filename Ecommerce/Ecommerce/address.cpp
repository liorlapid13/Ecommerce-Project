#include "address.h"
//----------------------------------------------------------------------------------------//
Address::Address(const string& street_name, int	house_number,
	int zip_code, const string& city, const string& country) 
{
	setStreetName(street_name);		//Street name
	setHouseNumber(house_number);	//House number
	setZipCode(zip_code);			//Zip code
	setCity(city);					//City
	setCountry(country);			//Country
}
//----------------------------------------------------------------------------------------//
bool Address::setStreetName(const string& street_name)
{
	if (!Validation::checkString(street_name))
	{
		cout << "Invalid street name, please try again\n";
		return false;
	}
	else
	{
		this->m_street_name = street_name;
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
bool Address::setCity(const string& city)
{
	if (!Validation::checkString(city))
	{
		cout << "City can only contain letters\n";
		return false;
	}
	else
	{
		this->m_city = city;
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Address::setCountry(const string& country)
{
	if (!Validation::checkString(country))
	{
		cout << "Country can only contain letters\n";
		return false;
	}
	else
	{
		this->m_country = country;
		return true;
	}
}
//----------------------------------------------------------------------------------------//
const string& Address::getStreetName() const
{
	return m_street_name;
}
//----------------------------------------------------------------------------------------//
 int Address::getHouseNumber() const
{
	return m_house_number;
}
//----------------------------------------------------------------------------------------//
 int Address::getZipCode() const
{
	return m_zip_code;
}
//----------------------------------------------------------------------------------------//
const string& Address::getCity() const
{
	return m_city;
}
//----------------------------------------------------------------------------------------//
const string& Address::getCountry() const
{
	return m_country;
}
//----------------------------------------------------------------------------------------//
void Address::printAddress() const
{
	cout << *this;
}
//----------------------------------------------------------------------------------------//
ostream& operator<<(ostream& os, const Address& address)
{
	os << address.m_street_name << " " << address.m_house_number << ", " << address.m_city << ", " 
		<< address.m_country << ", " << address.m_zip_code << endl;
	return os;
}
//----------------------------------------------------------------------------------------//