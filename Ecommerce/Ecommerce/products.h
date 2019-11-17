#ifndef __PRODUCTS_H
#define __PRODUCTS_h

#include "helper.h"


class Products
{
public:
	enum eCategory { KIDS, ELECTRICAL, CLOTHING, OFFICE };

public:

	bool setName(const char* name);
	bool setPrice(float price);
	bool setSerialNumber(int serialNumber);
	bool setCategory(eCategory category);


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


