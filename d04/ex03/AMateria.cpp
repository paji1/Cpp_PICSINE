#include "AMateria.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
AMateria::AMateria()
{
	std::cout << "AMateria Constructor called" << std::endl;
}
AMateria::AMateria(const AMateria &other )// : ICharacter(other)
{
	*this = other;
}
AMateria::AMateria(std::string const & _type) : type(_type) {}
/*** -------------------------------- DESTRUCTOR --------------------------------*/
AMateria::~AMateria()
{
	std::cout << "AMateria Destructor called" << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
AMateria&   AMateria::operator=(AMateria const & other )
{
	type = other.type;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/
std::string const& AMateria::getType() const
{
	return type;
}
/*** --------------------------------- ACCESSOR ---------------------------------*/
