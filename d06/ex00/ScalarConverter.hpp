#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "Is_Utils.hpp"
#include "Print_Utils.hpp"
class ScalarConverter
{
private:
	
public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &);
	~ScalarConverter();

	static void convert(std::string);
	ScalarConverter &operator=(ScalarConverter const &);
};

#endif /* * SCALARCONVERTER_H */