#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "validation.h"



class Product
{
public:
	enum eCategory { KIDS, ELECTRICAL, CLOTHING, OFFICE };
	static const char* categoryStr[];
	static const int NUM_OF_CATEGORIES = 4;			//product categories
	static const int MAX_SERIAL_NUMBER = 999999;	//Serial number contains maximum 6 digits 

public:
	//C'tor
	Product() = delete;
	Product(const char* name, float price, Product::eCategory category, const char* seller_name);
	Product(const Product& other);	//copy c'tor
	Product(Product&& other);		//move c'tor

	//D'tor
	~Product();

	//Setters
	bool setName(const char* name);
	bool setPrice(float price);
	bool setCategory(eCategory category);
	void setSellerName(const char* seller_name);

	//Getters
	const char* getName()				const;
	const float getPrice()				const;
	const int getSerialNumber()			const;
	const eCategory getCategory()		const;
	const char*  getSeller()			const;

	//QUESTION 10
	void printProduct()					const;

private:
	static int		serial_num_generator;
	int				m_serial_number;
	char*			m_name;
	float		    m_price;
	eCategory		m_category;
	char*		    m_seller;
};

#endif // !__PROFUCT_H