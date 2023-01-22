#include "ClapTrap.hpp"
class FragTrap :virtual public ClapTrap
{
private:
public:
	FragTrap(/* args */);
	FragTrap(std::string);
	FragTrap(const FragTrap&);
	FragTrap& operator=(const FragTrap&);
	void highFivesGuys(void);
	~FragTrap();
};
