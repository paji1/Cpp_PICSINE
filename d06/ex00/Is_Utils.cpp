#include "Is_Utils.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
Is_Utils::Is_Utils()
{
}
Is_Utils::Is_Utils(const Is_Utils &other )
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
Is_Utils::~Is_Utils()
{
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
Is_Utils&   Is_Utils::operator=(Is_Utils const & other )
{
	(void)other; 
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/

bool	Is_Utils::isdigit(int c)
{
	return (c <= '9' && c >= '0');
}
bool	Is_Utils::isprint(int c)
{
	return (c >= 32 && c <= 126);
}


bool Is_Utils::is_double(std::string num)
{	
	if (num == "nan")
		return true;
	size_t lenth = num.length();
	if (!lenth)
		return false;
	if (num[lenth - 1] == 'f')
		num[lenth - 1] = '0';
	size_t dot_pos;
	if ((dot_pos = num.find_last_of('.')) != num.find_first_of('.'))
		return false;
	if (dot_pos != num.npos)
		num[dot_pos] = '0';
	if (num[0] == '+' || num[0] == '-')
		num[0] = '0';
	for (int i = 0; num[i]; i++)
		if (!Is_Utils::isdigit(num[i]))
			return false;
	return true;
}
bool Is_Utils::is_float(std::string num)
{
	size_t lenth = num.length();
	if (num == "nanf")
		return true;
	if (!lenth)
		return false;
	if (num[lenth - 1] != 'f')
		return false;
	size_t dot_pos;
	if ((dot_pos = num.find('.')) == num.npos || num.find_last_of('.') != num.find_first_of('.'))
		return false;
	num[dot_pos] = '0';
	num[lenth - 1] = '0';
	if (num[0] == '+' || num[0] == '-')
		num[0] = '0';
	for (int i = 0; num[i]; i++)
		if (!Is_Utils::isdigit(num[i]))
			return false;
	return true;
}
bool Is_Utils::is_int(std::string num)
{
	if (num[0] == '+' || num[0] == '-')
		num[0] = '0';
	for (int i = 0; num[i]; i++)
		if (!Is_Utils::isdigit(num[i]))
			return false;
	return true;
}
bool Is_Utils::is_char(std::string num)
{
	return (num.length() == 1 && !Is_Utils::isdigit(num[0])) ;
}
/*** --------------------------------- ACCESSOR ---------------------------------*/
