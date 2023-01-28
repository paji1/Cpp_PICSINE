
#include "Cat.hpp"
Cat::Cat(/* args */) : Animal() 
{
	brain = new Brain();
	type = "Cat";
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	*this = other;
}
Cat& Cat::operator=(const Cat &other) 
{
	this->brain = other.brain;
	type = other.type;
	return *this;
}
void Cat::makeSound() const
{
	std::cout <<  type << " Meow Meow ! " << std::endl;
}
Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}
