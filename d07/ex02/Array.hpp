#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>

template <class T>
class Array
{
private:
	T *array;
	size_t size_a;

	class Outofbund : public std::runtime_error
	{
	public:
		Outofbund() : std::runtime_error("OutOfbound")
		{
			;
		}
	};

public:
	Array() : array(NULL), size_a(0)
	{
	}

	Array(unsigned int n)
	try : size_a(n)
	{
		array = new T[n];
		for (size_t i = 0; i < n * sizeof(T); i++)
			reinterpret_cast<char *>(array)[i] = 0;
	}
	catch (std::bad_alloc &e)
	{
		std::cout << e.what() << std::endl;
	}

	Array(Array const &other)
	try
	{
		*this = other;
	}
	catch (std::bad_alloc &e)
	{
		std::cout << e.what() << std::endl;
	}

	~Array()
	{
		delete[] array;
	}

	size_t size()
	{
		return size;
	}

	Array &operator=(const Array &other)
	{
		size_a = other.size_a;
		T *temp = new T[size_a];
		for (size_t i = 0; i < size_a * sizeof(T); i++)
			reinterpret_cast<char *>(temp)[i] = reinterpret_cast<char *>(other.array)[i];
		delete[] array;
		array = temp;
		return *this;
	}
	T &operator[](unsigned int i)
	{

		if (i >= size_a)
			throw Outofbund();
		return *(array + i);
	}
};

#endif /* * ARRAY_H */