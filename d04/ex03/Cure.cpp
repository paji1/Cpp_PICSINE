#include "Cure.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
Cure::Cure()
{
	type = "cure";
	std::cout << "Cure Constructor called" << std::endl;
}
Cure::Cure(const Cure &other ) : AMateria(other)
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
Cure::~Cure()
{
	std::cout << "Cure Destructor called" << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
Cure&   Cure::operator=(Cure const & other )
{
	type = other.type;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/
AMateria* Cure::clone() const
{
	return new Cure();
}

/*** --------------------------------- ACCESSOR ---------------------------------*/
