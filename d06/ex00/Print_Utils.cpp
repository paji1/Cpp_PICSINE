#include "Print_Utils.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
Print_Utils::Print_Utils()
{
}
Print_Utils::Print_Utils(const Print_Utils &other)
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
Print_Utils::~Print_Utils()
{
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
Print_Utils &Print_Utils::operator=(Print_Utils const &other)
{
	(void)other;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/

void Print_Utils::print_char(int num)
{
	if (!Is_Utils::isprint(num))
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		std::cout << "char: \'";
		std::cout << static_cast<char>(num) << "\'" << std::endl;
	}
	std::cout << "int: ";
	std::cout << static_cast<int>(num) << std::endl;
	std::cout << "float: ";
	std::cout << static_cast<int>(num) << ".0f" << std::endl;
	std::cout << "double: ";
	std::cout << static_cast<int>(num) << ".0" << std::endl;
}

void Print_Utils::print_int(int num)
{

	std::cout << "char: ";
	if (!Is_Utils::isprint(num))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << static_cast<char>(num) << "\'" << std::endl;
	std::cout << "int: ";
	std::cout << num << std::endl;
	std::cout << "float: ";
	std::cout << num << ".0f" << std::endl;
	std::cout << "double: ";
	std::cout << num << ".0" << std::endl;
}

void Print_Utils::print_float(float num)
{
	std::cout << "char: ";
	if ((num == num) == false)
		std::cout << "impossible" << std::endl;
	else if (!Is_Utils::isprint(num))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << static_cast<char>(num) << "\'" << std::endl;
	std::cout << "int: ";
	if ((num == num) == false)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
	std::cout << "float: ";
	std::cout << num
			  << ((static_cast<int>(num) - num) ? "f" : ".0f")
			  << std::endl;
	std::cout << "double: ";
	std::cout << static_cast<double>(num)
			  << ((static_cast<int>(num) - num) ? "" : ".0")
			  << std::endl;
}
void Print_Utils::print_double(double num)
{
	std::cout << "char: ";

	if ((num == num) == false || (std::numeric_limits<char>::max() < static_cast<double>(num)) ||
		(std::numeric_limits<char>::min() > static_cast<double>(num)))
		std::cout << "impossible" << std::endl;
	else if (!Is_Utils::isprint(num))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "\'" << static_cast<char>(num) << "\'" << std::endl;
	std::cout << "int: ";
	if ((num == num) == false || (std::numeric_limits<int>::max() < static_cast<double>(num)) ||
		(std::numeric_limits<int>::min() > static_cast<double>(num)))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
	std::cout << "float: ";
	std::cout << static_cast<float>(num)
			  << ((static_cast<int>(num) - num) ? "f" : ".0f")
			  << std::endl;
	std::cout << "double: ";
	std::cout << num
			  << ((static_cast<int>(num) - num) ? "" : ".0")
			  << std::endl;
}

/*** --------------------------------- ACCESSOR ---------------------------------*/
