
#include "ClapTrap.hpp"
int main(void)
{
	ClapTrap robot = ClapTrap("taha");
	robot.attack("TAHA");
	robot.takeDamage(10);
	robot.beRepaired(10);
	return 0;
}
