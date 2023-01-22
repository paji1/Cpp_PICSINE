#include "FragTrap.hpp"
#include "ScavTrap.hpp"
class DiamondTrap :  public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap(/* arg	s */);
	DiamondTrap(std::string);
	DiamondTrap(const DiamondTrap&);
	DiamondTrap& operator=(const DiamondTrap&);

	void whoAmI();
	
	~DiamondTrap();
};