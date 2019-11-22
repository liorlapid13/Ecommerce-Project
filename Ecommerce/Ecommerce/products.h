#ifndef __PRODUCTS_H
#define __PRODUCTS_h

#include "helper.h"

class Products
{
public:
	enum eCategory { KIDS, ELECTRICAL, CLOTHING, OFFICE };

public:
	//C'tor
	Products() = delete;
	Products(const char* name, float price, int serialNumber, Products::eCategory category);
	Products(const Products& other);
	Products(Products&& other);

	//D'tor
	~Products();

public:
	//Setters
	bool setName(const char* name);
	bool setPrice(float price);
	bool setSerialNumber(unsigned int serialNumber);
	bool setCategory(eCategory category);

	//Getters
	inline const char* getName()     const;
	inline float getPrice()          const;
	inline int getSerialNumber()     const;
	inline eCategory getCategory()   const;

	bool isValidProducts(const char* name, float price, Products::eCategory category);

private:

	char*			m_name;
	float		    m_price;
	unsigned int	m_serialNumber;
	eCategory		m_category;
};

#endif // !__PROFUCTS_H