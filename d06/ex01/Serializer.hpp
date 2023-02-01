#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
#include "Data.hpp"
# include <stdint.h>

class Serializer
{
private:
public:
	Serializer();
	Serializer(Serializer const &);		
	~Serializer();

	Serializer&	operator=(Serializer const &);
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

};

#endif /* * SERIALIZER_H */