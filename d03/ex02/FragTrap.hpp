#include "ClapTrap.hpp"
class FragTrap : public ClapTrap
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

