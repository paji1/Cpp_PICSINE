
#include "DiamondTrap.hpp"
DiamondTrap::DiamondTrap(/* args */) : ScavTrap(), FragTrap()
{
	std::cout << "constructor of DiamondTrap call " << std::endl;
}
DiamondTrap::DiamondTrap(std::string _name) : ScavTrap(_name),
											  FragTrap(_name),
											  name(_name)
{
	ClapTrap::name = _name.append("_clap_name");
	hit = FragTrap::hit;
	energy = ScavTrap::energy;
	damage = FragTrap::damage;

	std::cout << _name
			  << " constructor of DiamondTrap call "
			  << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other),
													 ScavTrap(other),
													 FragTrap(other)
{
	*this = other;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	this->damage = other.damage;
	this->energy = other.energy;
	this->hit = other.hit;
	this->name = other.name;
	return *this;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "destructor of DiamondTrap call " << std::endl;
}
void DiamondTrap::whoAmI()
{
	std::cout << "clap trap name " << ClapTrap::name << std::endl;
	std::cout << "Diamond name " << name << std::endl;

}