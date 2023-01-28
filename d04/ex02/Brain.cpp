#include "Brain.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
Brain::Brain()
{
	ideas = new std::string[100];
	std::cout << "Brain Constructor called" << std::endl;
}
Brain::Brain(const Brain &other )
{
	ideas = new std::string[100];
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
Brain::~Brain()
{
	delete []ideas;
	std::cout << "Brain Destructor called" << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
Brain&   Brain::operator=(Brain const & other)
{
	for (int i = 0 ; i < 100 ; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/

/*** --------------------------------- ACCESSOR ---------------------------------*/
