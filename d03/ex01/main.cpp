
#include "ScavTrap.hpp"
// #include "ClapTrap.hpp"
int main(void)
{
	ScavTrap robot = ScavTrap("taha");
	robot.attack("TAHA");
	robot.takeDamage(10);
	robot.beRepaired(122);
	return 0;
}
