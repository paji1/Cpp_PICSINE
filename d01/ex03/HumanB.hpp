
#include "Weapon.hpp"
class HumanB
{
private:
	std::string name;
	Weapon* wep;
public:

	HumanB(std::string name);
	void setWeapon(Weapon &_wep);
	~HumanB();	
	void attack();
};


