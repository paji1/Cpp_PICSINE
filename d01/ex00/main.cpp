
#include<stdlib.h>
#include "Zombie.hpp"
int main(void)
{
	Zombie *one = newZombie("taha");
	delete one;
	randomChump("hello");

	return 0;
}
