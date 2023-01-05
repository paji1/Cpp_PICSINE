#include "Zombie.hpp"
#include <iostream>

void Zombie::setName(std::string name)
{
	this->name = name;
}
Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie created" << std::endl;
}
Zombie::Zombie(void)
{
	;
}

Zombie::~Zombie()
{
	std::cout << this->name << " deleted" << std::endl;
}

void Zombie::announce(void)
{

	std::cout
		<< (char)toupper(this->name[0])
		<< &this->name[1]
		<< ": BraiiiiiiinnnzzzZ..."
		<< std::endl;
}
