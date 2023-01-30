#include "Intern.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
Intern::Intern()
{
}
Intern::Intern(const Intern &other )
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
Intern::~Intern()
{
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
Intern&   Intern::operator=(Intern const & other )
{
	(void)other;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/
// MyClass* (*createMyClass)(std::string);


Form* Intern::make_PresidentialPardon(std::string target)
{
	Form *form = new PresidentialPardonForm(target);
	return form;
}
Form* Intern::make_RobotomyRequest(std::string target)
{
	Form *form = new RobotomyRequestForm(target);
	return form;
}
Form* Intern::make_ShrubberyCreation(std::string target)
{
	Form *form = new ShrubberyCreationForm(target);
	return form;
}


Form* 	Intern::makeForm(std::string name, std::string target)
{
	typedef Form* (Intern::*pForm[3])(std::string);
	Form *rform;
	pForm tab = {
		&Intern::make_PresidentialPardon,
		&Intern::make_RobotomyRequest,
		&Intern::make_ShrubberyCreation
	};
	for (int i; i < 3; i++)
	{
		if ((rform = (this->*(tab[i]))(target))->getName() == name) 
			return std::cout << "Intern creates " << rform->getName() << std::endl, rform;
		std::cout << rform->getName()<< std::endl;
		delete rform;
	}
	throw form_not_exists();
}
Intern::form_not_exists::form_not_exists() : std::runtime_error("form desen't exist")
{

}
/*** --------------------------------- ACCESSOR ---------------------------------*/
