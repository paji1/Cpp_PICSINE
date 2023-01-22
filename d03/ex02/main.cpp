

#include "FragTrap.hpp"
// #include "ClapTrap.hpp"
int main(void)
{
	FragTrap robot = FragTrap("taha");
	robot.attack("TAHA");
	robot.takeDamage(10);
	robot.beRepaired(122);
	return 0;
}
