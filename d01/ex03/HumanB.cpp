#include "HumanB.hpp"

void HumanB::attack()
{
	// <name> attacks with their <weapon type>
	std::cout
		<< name
		<< " attacks with their "
		<< wep->getType()
		<< std::endl;
}

HumanB::HumanB(std::string _name) : name(_name) {}

void HumanB::setWeapon(Weapon &_wep) { wep = &_wep; }

HumanB::~HumanB()
{
	std::cout << name << " removed" << std::endl; 
}