#include "HumanA.hpp"

void HumanA::attack()
{
	// <name> attacks with their <weapon type>
	std::cout
		<< name
		<< " attacks with their "
		<< wep.getType()
		<< std::endl;
}

HumanA::HumanA(std::string _name, Weapon &_wep) : name(_name), wep(_wep) {}

HumanA::~HumanA() { std::cout << name << " removed" << std::endl; }