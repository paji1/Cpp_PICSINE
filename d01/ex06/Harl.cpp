
#include "Harl.hpp"
#include <iostream>
void Harl::debug(void)
{
	std::cout
		<< "[ DEBUG ]" 
		<< std::endl
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
		<< std::endl
		<< std::endl;
}
void Harl::info(void)
{
	std::cout
		<< "[ INFO ]" 
		<< std::endl
		<< "I cannot believe adding extra bacon costs more money. You didn’t put"
		<< " enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl
		<< std::endl;
}
void Harl::warning(void)
{
	std::cout
		<< "[ WARNING ]" 
		<< std::endl
		<< "I think I deserve to have some extra bacon for free. I’ve been coming for"
		<< " years whereas you started working here since last month."
		<< std::endl
		<< std::endl;
}
void Harl::error(void)
{
	std::cout
		<< "[ ERROR ]" 
		<< std::endl
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl
		<< std::endl;
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*Harlptr[4])(void);
	Harlptr ftap = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels = "DEBUG   INFO    WARNING ERROR";
	switch ((levels.find(level))  /  8)
	{
	case 0:
		(this->*(ftap[0]))();
		(this->*(ftap[1]))();
		(this->*(ftap[2]))();
		(this->*(ftap[3]))();
		break;
	case 1:
		(this->*(ftap[1]))();
		(this->*(ftap[2]))();
		(this->*(ftap[3]))();
		break;
	case 2:
		(this->*(ftap[2]))();
		(this->*(ftap[3]))();
		break;
	case 3:
		(this->*(ftap[3]))();
		break;
	default:
		std::cout 
		<< "[ Probably complaining about insignificant problems ]"
		<< std::endl;
		break;
	}

}

Harl::Harl(/* args */)
{
}

Harl::~Harl()
{
}
