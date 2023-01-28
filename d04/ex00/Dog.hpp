#include <string>
#include <iostream>
#include "Animal.hpp"
class Dog : public Animal
{
public:
	Dog(/* args */);
	Dog(const Dog&);
	Dog& operator=(const Dog&);
	void makeSound() const ;
	~Dog();
};

