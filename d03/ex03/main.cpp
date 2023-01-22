

#include "DiamondTrap.hpp"
// #include "ClapTrap.hpp"
int main(void)
{
	DiamondTrap robot = DiamondTrap("taha");

	robot.whoAmI();
	robot.attack("TAHA");
	robot.takeDamage(10);
	robot.beRepaired(122);
	return 0;
}
