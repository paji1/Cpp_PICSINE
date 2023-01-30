#include "RobotomyRequestForm.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
RobotomyRequestForm::RobotomyRequestForm() : Form(72, 45, "robotomy request")
{
}
RobotomyRequestForm::RobotomyRequestForm(std::string _target) : Form(72, 45, "robotomy request"),
																 target(_target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Form(other)
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
RobotomyRequestForm::~RobotomyRequestForm()
{
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	target = other.target;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	this->beExecute(executor);
	std::cout << "drilling noise" << std::endl;
	std::srand(std::time(0)); // use current time as seed for random generator
	int random_variable = std::rand();
	if (random_variable % 2)
		std::cout << target
				  << " has been robotomized successfully 50% of the time"
				  << std::endl;
	else
		std::cout
			<< " robotomy failed "
			<< std::endl;
}

/*** --------------------------------- ACCESSOR ---------------------------------*/
