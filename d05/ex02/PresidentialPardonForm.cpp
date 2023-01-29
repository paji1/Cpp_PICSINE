#include "PresidentialPardonForm.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
PresidentialPardonForm::PresidentialPardonForm() : Form(25, 5, "PresidentialPardonForm")
{
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(std::string _target) : Form(25, 5, "PresidentialPardonForm"),
																 target(_target)
{
	std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form(other)
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	target = other.target;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/
void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->beExecute(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}


/*** --------------------------------- ACCESSOR ---------------------------------*/
