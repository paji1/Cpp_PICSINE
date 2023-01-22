#include <string>
#include <iostream>
class ClapTrap
{
protected:
	std::string name;
	int hit;
	int energy;
	int damage;

public:
	ClapTrap(/* args */);
	ClapTrap(std::string);
	ClapTrap(const ClapTrap&);
	ClapTrap& operator=(const ClapTrap&);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};
