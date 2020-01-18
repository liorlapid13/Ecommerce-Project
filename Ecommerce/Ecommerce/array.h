#ifndef __ARRAY_H
#define __ARRAY_H

#include <iostream>
using namespace std;

#include "validation.h"

template<class T>
class Array
{
private:
	int m_size;
	T*	m_arr;

public:
	friend class Seller;

	//C'tors
	Array() 
	{ 
		m_size = 0; 
		m_arr = nullptr;
	}

	Array(const Array& other) 
	{
		m_size = other.m_size;

		if (m_size)
		{
			m_arr = new T[other.m_size];
			for (int i = 0; i < other.m_size; i++)
				m_arr[i] = other.m_arr[i];
		}
		else
			m_arr = nullptr;
	}

	Array(Array&& other)
	{
		m_size = other.m_size;
		m_arr = other.m_arr;
		other.m_arr = nullptr;
		other.m_size = 0;
	}

	//D'tor
	~Array()
	{
		for (int i = 0; i < m_size; i++)
			delete m_arr[i];
		delete[] m_arr;
	}

	//Operators
	friend ostream& operator<<(ostream& os, const Array& arr)
	{
		for (int i = 0; i < arr.m_size; i++)
			os << *arr.m_arr[i];
		return os;
	}

	const Array<T>& operator+=(T new_val)
	{
		T* temp = new T[m_size + 1];
		Validation::checkAllocation(temp);

		if (m_arr)
		{
			for (int i = 0; i < m_size; i++)
				temp[i] = m_arr[i];
			delete[] m_arr;
		}

		temp[m_size] = new_val;
		m_size++;
		m_arr = temp;
		temp = nullptr;

		return *this;
	}

	const Array<T>& operator=(const Array<T>& other)
	{
		if (this != &other)
		{
			for (int i = 0; i < m_size; i++)
				delete m_arr[i];
			delete[] m_arr;

			m_size = other.m_size;
			if (m_size)
			{
				m_arr = new T[other.m_size];
				for (int i = 0; i < other.m_size; i++)
					m_arr[i] = other.m_arr[i];
			}
			else
				m_arr = nullptr;
		}
		return *this;
	}

	const Array<T>& operator=(Array<T>&& other)
	{
		if (this != &other)
		{
			for (int i = 0; i < m_size; i++)
				delete m_arr[i];
			delete[] m_arr;

			m_size = other.m_size;
			m_arr = other.m_arr;
			other.m_arr = nullptr;
		}

		return *this;
	}
};

#endif // !__ARRAY_H
