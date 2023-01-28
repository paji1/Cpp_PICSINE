
#include "Cat.hpp"
Cat::Cat(/* args */) : Animal() 
{
	type = "Cat";
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
}
Cat& Cat::operator=(const Cat &other) 
{
	type = other.type;
	return *this;
}
void Cat::makeSound() const
{
	std::cout <<  type << " Meow Meow!" << std::endl;
}
Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
