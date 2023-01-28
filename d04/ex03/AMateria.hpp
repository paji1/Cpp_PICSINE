#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;
public:
	AMateria();
	AMateria(std::string const &);
	AMateria(AMateria const &);
	~AMateria();

	std::string const & getType() const;
	AMateria&	operator=(AMateria const &);
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};


#endif /* * AMATERIA_H */