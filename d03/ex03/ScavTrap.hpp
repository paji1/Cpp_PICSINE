#include <string>
#include "ClapTrap.hpp"
#include <iostream>
class ScavTrap :virtual public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string _name);
	ScavTrap(const ScavTrap &);
	ScavTrap &operator=(const ScavTrap &);
	void attack(const std::string &target);
	void guardGate();
	~ScavTrap();
};
