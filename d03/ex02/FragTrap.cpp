
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	hit = 100;
	energy = 100;
	damage = 30;
	std::cout << "constructor of FragTrap call " << std::endl;
}
FragTrap::FragTrap(std::string _name) : ClapTrap(_name) 
{
	hit = 100;
	energy = 100;
	damage = 30;
	std::cout << "constructors of FragTrap "
			  << _name
			  << " call " << std::endl;
}
FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	*this = other;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	this->damage = other.damage;
	this->energy = other.energy;
	this->hit = other.hit;
	this->name = other.name;
	return *this;
}
FragTrap::~FragTrap()
{
	std::cout << "destructor of FragTrap call " << std::endl;
}


void FragTrap::highFivesGuys(void)
{
	std::cout << "Hi pal am FragTrap highFives 🙋" << std::endl;
}
