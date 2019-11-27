#ifndef __PRODUCTS_H
#define __PRODUCTS_H

#include "helper.h"
#include "seller.h"

class Products
{
public:
		enum eCategory { KIDS, ELECTRICAL, CLOTHING, OFFICE };
		static constexpr char categoryStr[] = { "Kids","Electrical","Clothing","Office" };
	static const int NUM_OF_CATEGORIES = 4;			//product categories
	static const int MAX_SERIAL_NUMBER = 999999;	//Serial number contains maximum 6 digits 

public:
	//C'tor
	Products() = delete;
	Products(const char* name, float price, Products::eCategory category,char* seller);
	Products(const Products& other); //copy c'tor

	//D'tor
	~Products();

private: //DELETED C'TORS
	Products(Products&& other);

public:
	//Setters
	bool setName(const char* name);
	bool setPrice(float price);
	bool setCategory(eCategory category);
	void setSeller(char* seller);

	//Getters
	inline const char* getName()				const;
	inline const float getPrice()				const;
	inline const int getSerialNumber()			const;
	inline const eCategory getCategory()		const;
	inline const char*  getSeller()				const;

	//QUESTION 10
	void printProduct()							const;

private:
	static int		serial_num_generator;
	int				m_serial_number;
	char*			m_name;
	float		    m_price;
	eCategory		m_category;
	char*		    m_seller;
};

#endif // !__PROFUCTS_H