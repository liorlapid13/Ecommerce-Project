#include "address.h"
//----------------------------------------------------------------------------------------//
Address::Address(const char* street_name, int	house_number,
	int zip_code, const char* city, const char* country) : m_street_name(nullptr), m_city(nullptr), m_country(nullptr)
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
	//Street name
	m_street_name = other.m_street_name;
	other.m_street_name = nullptr;

	//House number & Zip code
	m_house_number = other.m_house_number;
	m_zip_code = other.m_zip_code;

	//City
	m_city = other.m_city;
	other.m_city = nullptr;

	//Country
	m_country = other.m_country;
	other.m_country = nullptr;
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
	if (!Validation::checkString(strlen(street_name), street_name))
	{
		cout << "Invalid street name, please try again\n";
		return false;
	}
	else
	{
		delete[] m_street_name;
		m_street_name = new char[strlen(street_name) + 1];
		Validation::checkAllocation(m_street_name);
		strcpy(m_street_name, street_name);
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
	if (!Validation::checkString(strlen(city), city))
	{
		cout << "City can only contain letters\n";
		return false;
	}
	else
	{
		delete[] m_city;
		m_city = new char[strlen(city) + 1];
		Validation::checkAllocation(m_city);
		strcpy(m_city, city);
		return true;
	}
}
//----------------------------------------------------------------------------------------//
bool Address::setCountry(const char* country)
{
	if (!Validation::checkString(strlen(country), country))
	{
		cout << "Country can only contain letters\n";
		return false;
	}
	else
	{
		delete[] m_country;
		m_country = new char[strlen(country) + 1];
		Validation::checkAllocation(m_country);
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

		delete[] m_street_name;
		m_street_name = strdup(other.m_street_name);

		delete[] m_city;
		m_city = strdup(other.m_street_name);

		delete[] m_country;
		m_country = strdup(other.m_country);
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

		delete[] m_street_name;
		m_street_name = other.m_street_name;
		other.m_street_name = nullptr;

		delete[] m_city;
		m_city = other.m_street_name;
		other.m_city = nullptr;

		delete[] m_country;
		m_country = other.m_country;
		other.m_country = nullptr;
	}

	return *this;
}
//----------------------------------------------------------------------------------------//