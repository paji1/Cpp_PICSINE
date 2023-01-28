#ifndef ICE_HPP
# define ICE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"
class Ice : public AMateria
{
private:
public:
	Ice();
	Ice(Ice const &);
	~Ice();

	Ice&	operator=(Ice const &);
	AMateria* clone() const;
};

#endif /* * ICE_H */