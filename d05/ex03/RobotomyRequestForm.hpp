#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <iostream>
#include <cstdlib>
#include <ctime>
# include <string>
class RobotomyRequestForm : public Form
{
private:
	std::string target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string);
	RobotomyRequestForm(RobotomyRequestForm const &);
	~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(RobotomyRequestForm const &);
	void execute(Bureaucrat const & executor) const;
};

#endif /* * ROBOTOMYREQUESTFORM_H */