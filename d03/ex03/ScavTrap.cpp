
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	energy = 50;
	std::cout << "constructor of ScavTrap call " << std::endl;
}
ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name) 
{
	energy = 50;
	std::cout << "constructors of ScavTrap "
			  << _name
			  << " call " << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	*this = other;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	this->damage = other.damage;
	this->energy = other.energy;
	this->hit = other.hit;
	this->name = other.name;
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "destructor of ScavTrap call " << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
void ScavTrap::attack(const std::string &target)
{
	if (!energy)
		return;
	std::cout << "ScavTrap "
			  << name
			  << " attacks "
			  << target
			  << ", causing "
			  << damage
			  << " points of damage!"
			  << std::endl;
	energy--;
}