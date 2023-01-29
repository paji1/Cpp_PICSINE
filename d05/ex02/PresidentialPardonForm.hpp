#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

# include "AForm.hpp"
# include <iostream>
# include <string>
class PresidentialPardonForm : public Form
{
private:
	std::string target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string);
	PresidentialPardonForm(PresidentialPardonForm const &);
	~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(PresidentialPardonForm const &);
	void execute(Bureaucrat const & executor) const;
};

#endif /* * PresidentialPardonForm_H */