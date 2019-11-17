#ifndef __PRODUCTS_H
#define __PRODUCTS_h

#include "helper.h"


class Products
{
public:
	enum eCategory { KIDS, ELECTRICAL, CLOTHING, OFFICE };

public:
	//C'tor
	Products(const char* name, float price, int serialNumber, Products::eCategory category);
	//D'tor
	~Products();

	//Setters
	bool setName(const char* name);
	void setPrice(float price);
	void setSerialNumber(int serialNumber);
	bool setCategory(eCategory category);

	//Getters
	inline const char* getName()     const;
	inline float getPrice()          const;
	inline int getSerialNumber()       const;
	inline eCategory getCategory()     const;

private:

	char * m_name;
	float m_price;
	int m_serialNumber;
	eCategory m_category;
};

#endif // !__PROFUCTS_H