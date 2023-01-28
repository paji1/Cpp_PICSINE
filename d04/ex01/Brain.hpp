#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
class Brain
{
private:
	std::string *ideas;
public:
	Brain();
	Brain(Brain const &);
	~Brain();

	Brain&	operator=(Brain const &);
};

#endif /* * BRAIN_H */