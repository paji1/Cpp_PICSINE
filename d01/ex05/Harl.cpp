
#include "Harl.hpp"
#include <iostream>
void Harl::debug(void)
{
	std::cout
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl;
}
void Harl::info(void)
{
	std::cout
		<< "I cannot believe adding extra bacon costs more money. You didn’t put"
		<< " enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}
void Harl::warning(void)
{
	std::cout
		<< "I think I deserve to have some extra bacon for free. I’ve been coming for"
		<< " years whereas you started working here since last month."
		<< std::endl;
}
void Harl::error(void)
{
	std::cout
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}


void Harl::complain(std::string level)
{
	size_t pos = level.npos;
	typedef void (Harl::*Harlptr[4])(void);
	Harlptr ftap = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels = "DEBUG   INFO    WARNING ERROR";
	if ((pos  = levels.find(level)) != levels.npos)
		(this->*(ftap[pos/ 8]))();
}

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}
