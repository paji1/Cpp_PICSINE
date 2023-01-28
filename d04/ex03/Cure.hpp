#ifndef CURE_HPP
# define CURE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const &);
	~Cure();

	Cure&	operator=(Cure const &);
	AMateria* clone() const;
	void use(ICharacter& target);
};

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " 
	<< this->getName()  
	<< "’s wounds *"
	<< std::endl; 
}
#endif /* * CURE_H */