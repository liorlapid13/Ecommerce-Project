#ifndef __PRODUCT_H
#define __PRODUCT_H

#include "validation.h"


class Product
{
public:
	//Constants
	enum eCategory { KIDS, ELECTRICAL, CLOTHING, OFFICE };
	static const string categoryStr[];
	static const int NUM_OF_CATEGORIES = 4;			//product categories
	static const int MAX_SERIAL_NUMBER = 999999;	//Serial number contains maximum 6 digits 
	static const int MAX_PRODUCT_NAME = 60;

	//C'tors
	Product() = delete;
	Product(const string& name, float price, Product::eCategory category, const string& seller_name);

	//Setters
	bool setName(const string& name);
	bool setPrice(float price);
	bool setCategory(eCategory category);
	void setSellerName(const string& seller_name);

	//Getters
	const string&	getName()			const;
	float			getPrice()			const;
	int				getSerialNumber()	const;
	eCategory		getCategory()		const;
	const string&	getSeller()			const;

	//QUESTION 10
	void printProduct()				const;

	//Operators
	friend ostream& operator<<(ostream& os, const Product& product);

private:
	static int		serial_num_generator;

	int				m_serial_number;
	string			m_name;
	float		    m_price;
	eCategory		m_category;
	string		    m_seller;
};

#endif // !__PROFUCT_H