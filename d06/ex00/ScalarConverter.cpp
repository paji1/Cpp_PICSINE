#include "ScalarConverter.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor called" << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other)
{
	(void)other;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/
















void ScalarConverter::convert(std::string str)
{

	double num;
	if (Is_Utils::is_char(str))
	{
		Print_Utils::print_char(static_cast<char>(str[0]));
		return ;
	}
	if (Is_Utils::is_float(str))
	{
		num = atof(str.c_str());
		if (std::numeric_limits<float>::min() > static_cast<float>(num) || \
			(std::numeric_limits<int>::max() < static_cast<double>(num)))
		{
			Print_Utils::print_double(static_cast<double>(num));
			return ;
		}
		Print_Utils::print_float(static_cast<float>(num));
		return ;
	}
	if (Is_Utils::is_int(str))
	{
		num = atof(str.c_str());
		if (std::numeric_limits<int>::max() < static_cast<double>(num) ||\
			(std::numeric_limits<int>::min() > static_cast<double>(num)))
		{
			Print_Utils::print_double(static_cast<double>(num));
			return ;
		}
		Print_Utils::print_int(static_cast<int>(num));
		return ;
	}
	if (Is_Utils::is_double(str))
	{
		num = atof(str.c_str());
		Print_Utils::print_double(static_cast<double>(num));
		return ;
	}
	std::cout << "* WRONG TYPE *" << std::endl;
}
/*** --------------------------------- ACCESSOR ---------------------------------*/
