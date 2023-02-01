#include "Serializer.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
Serializer::Serializer()
{
	std::cout << "Serializer Constructor called" << std::endl;
}
Serializer::Serializer(const Serializer &other )
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
Serializer::~Serializer()
{
	std::cout << "Serializer Destructor called" << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
Serializer&   Serializer::operator=(Serializer const & other )
{
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw);
}
/*** --------------------------------- METHODS ----------------------------------*/

/*** --------------------------------- ACCESSOR ---------------------------------*/
