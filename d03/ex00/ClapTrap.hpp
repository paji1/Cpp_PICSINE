#include <string>
class ClapTrap
{
private:
	std::string name;
	int hit = 10;
	int energy = 10;
	int damage = 0;

public:
	ClapTrap(/* args */);
	ClapTrap(std::string);
	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	~ClapTrap();
};

ClapTrap::ClapTrap(/* args */)
{
}
ClapTrap::ClapTrap(std::string _name) : name(_name) {}
ClapTrap::~ClapTrap()
{
}
