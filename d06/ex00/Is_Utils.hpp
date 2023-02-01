#ifndef IS_UTILS_HPP
# define IS_UTILS_HPP

# include <iostream>
# include <string>
# include <limits>
class Is_Utils
{
private:
public:
	Is_Utils();
	Is_Utils(Is_Utils const &);
	~Is_Utils();

	static bool	isdigit(int c);
	static bool	isprint(int c);
	static bool is_float(std::string);
	static bool is_double(std::string);
	static bool is_int(std::string);
	static bool is_char(std::string);
	Is_Utils&	operator=(Is_Utils const &);
};

#endif /* * IS_UTILS_H */