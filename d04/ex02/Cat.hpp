#include <string>
#include <iostream>
#include "Animal.hpp"
class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat(/* args */);
	Cat(const Cat&);
	Cat& operator=(const Cat&);
	void makeSound() const ;
	~Cat();
};

