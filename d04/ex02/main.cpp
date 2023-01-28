
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#define N 4
int main()
{
	{
		const Animal *j = new Dog();
		const Animal *i = new Cat();
		
		delete j; // should not create a leak
		delete i;
	}
	Animal *meta[N];
	
	for (int i = 0; i < N / 2; i++)
		meta[i] = new Dog();
	for (int i = N / 2; i < N; i++)
		meta[i] = new Cat();

	Dog l;
	l = Dog();
	// 	destructor
	for (int i = 0; i < N; i++)
		delete meta[i];
	return 0;
}
