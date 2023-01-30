#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	struct form_not_exists : public std::runtime_error
	{
		form_not_exists();
	};
public:
	Intern();
	Intern(Intern const &);
	~Intern();
	Form* makeForm(std::string, std::string);
	Form* make_PresidentialPardon(std::string);
	Form* make_RobotomyRequest(std::string);
	Form* make_ShrubberyCreation(std::string);
	Intern&	operator=(Intern const &);
};


#endif /* * INTERN_H */