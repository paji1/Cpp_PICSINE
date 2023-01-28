#include "ICharacter.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
ICharacter::ICharacter()
{
	std::cout << "ICharacter Constructor called" << std::endl;
}
ICharacter::ICharacter(std::string _name) : name(_name) {}
ICharacter::ICharacter(const ICharacter &other) { *this = other; }

/*** -------------------------------- DESTRUCTOR --------------------------------*/
ICharacter::~ICharacter()
{
	std::cout << "ICharacter Destructor called" << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
ICharacter &ICharacter::operator=(ICharacter const &other)
{
	*this = other;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/

/*** --------------------------------- ACCESSOR ---------------------------------*/
