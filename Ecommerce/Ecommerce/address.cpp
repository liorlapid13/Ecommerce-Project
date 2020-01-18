#include "address.h"
//----------------------------------------------------------------------------------------//
Address::Address(const string& street_name, int	house_number,
	int zip_code, const string& city, const string& country) : m_street_name(nullptr), m_city(nullptr), m_country(nullptr)
{

	setStreetName(street_name);		//Street name
	setHouseNumber(house_number);	//House number
	setZipCode(zip_code);			//Zip code
	setCity(city);					//City
	setCountry(country);			//Country
}
//----------------------------------------------------------------------------------------//
Address::Address(const Address& other) :m_street_name(nullptr), m_city(nullptr), m_country(nullptr)	//Copy C'tor
{
	//Street name
	setStreetName(other.m_street_name);

	//House number & Zip code
	setHouseNumber(other.m_house_number);
	setZipCode(other.m_zip_code);

	//City
	setCity(other.m_city);

	//Country
	setCountry(other.m_country);
}
//----------------------------------------------------------------------------------------//
Address::Address(Address&& other)	//Move C'tor
{
	
	m_street_name = move(other.m_street_name);
	m_house_number = other.m_house_number;
	m_zip_code = other.m_zip_code;
	m_city = move(other.m_city);
	m_country = move(other.m_country);
}
//----------------------------------------------------------------------------------------//
Address::~Address()
{
	
}
//----------------------------------------------------------------------------------------//
bool Address::setStreetName(const string& street_name)
{
	if (!Validation::checkString(street_name.length(), street_name))
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
	if (!Validation::checkString(city.length(), city))
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
	if (!Validation::checkString(country.length(), country))
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
const Address& Address::operator=(const Address& other)
{
	if (this != &other)
	{
		m_zip_code = other.m_zip_code;
		m_house_number = other.m_house_number;
		m_street_name = other.m_street_name;
		m_city = other.m_street_name;
		m_country = other.m_country;
	}

	return *this;
}
//----------------------------------------------------------------------------------------//
const Address& Address::operator=(Address&& other)
{
	if (this != &other)
	{
		m_zip_code = other.m_zip_code;
		m_house_number = other.m_house_number;
		m_street_name = move(other.m_street_name);
		m_city = move(other.m_street_name);
		m_country = move(other.m_country);
	}

	return *this;
}
//----------------------------------------------------------------------------------------//