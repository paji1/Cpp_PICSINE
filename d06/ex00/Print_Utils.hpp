#ifndef PRINT_UTILS_HPP
# define PRINT_UTILS_HPP

# include <iostream>
# include <string>
# include "Is_Utils.hpp"
class Print_Utils
{
private:
public:
	Print_Utils();
	Print_Utils(Print_Utils const &);
	~Print_Utils();
	
	static void print_char(int);
	static void print_int(int);
	static void print_float(float);
	static void print_double(double);
	Print_Utils&	operator=(Print_Utils const &);
};

#endif /* * PRINT_UTILS_H */