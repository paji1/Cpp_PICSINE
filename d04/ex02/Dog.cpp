
#include "Dog.hpp"
Dog::Dog(/* args */) : Animal()
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog Constructor called" << std::endl;
}
Dog::Dog(const Dog &other) : Animal(other)
{
	*this = other;
}
Dog& Dog::operator=(const Dog &other) 
{
	*this->brain = *other.brain;
	type = other.type;
	return *this;
}
void Dog::makeSound() const
{
	std::cout <<  type << " Bark !? " << std::endl;
}
Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}
