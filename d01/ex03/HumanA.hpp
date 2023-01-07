
#include "Weapon.hpp"
class HumanA
{
private:
	std::string name;
	Weapon& wep;
public:

	HumanA(std::string name, Weapon& _wep );
	~HumanA();	
	void attack();
};


