#include <string>
#include <iostream>
#include "Brain.hpp"
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class Animal
{
protected:
	std::string type;
public:
	Animal(/* args */);
	Animal(const Animal&);
	Animal& operator=(const Animal&);
	virtual void makeSound() const;
	const std::string& getType()const ;
	virtual ~Animal();
};

#endif
