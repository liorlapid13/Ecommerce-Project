#ifndef __PRODUCTS_H
#define __PRODUCTS_H

#include "helper.h"
#include "seller.h"

class Products
{
public:
	enum eCategory { KIDS, ELECTRICAL, CLOTHING, OFFICE };
	static const int NUM_OF_CATEGORIES = 4;			//product categories
	static const int MAX_SERIAL_NUMBER = 999999;	//Serial number contains maximum 6 digits 

public:
	//C'tor
	Products() = delete;
	Products(const char* name, float price, unsigned int serialNumber, Products::eCategory category,Seller& seller);
	Products(const Products& other); //copy c'tor

	//D'tor
	~Products();

private: //DELETED C'TORS
	Products(Products&& other);

public:
	//Setters
	bool setName(const char* name);
	bool setPrice(float price);
	bool setSerialNumber(unsigned int serialNumber);
	bool setCategory(eCategory category);

	//Getters
	inline const char* getName()				const;
	inline const float getPrice()				const;
	inline const unsigned int getSerialNumber()	const;
	inline const eCategory getCategory()		const;
	inline const Seller* const getSeller()		const;

private:
	char*			m_name;
	float		    m_price;
	unsigned int	m_serialNumber;
	eCategory		m_category;
	Seller*         m_seller;
};

#endif // !__PROFUCTS_H