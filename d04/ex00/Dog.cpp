
#include "Dog.hpp"
Dog::Dog(/* args */) : Animal()
{
	type = "Dog";
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	*this = other;
}
Dog& Dog::operator=(const Dog &other) 
{
	type = other.type;
	return *this;
}
void Dog::makeSound() const
{
	std::cout <<  type << " Bark Bark!?" << std::endl;
}
Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
