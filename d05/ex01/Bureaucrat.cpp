#include "Bureaucrat.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
/**
 * @param name
 * @param _grade
*/
Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(1)
{
	std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string _name ,int _grade) : name(_name) , grade(_grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	grade = _grade;
	std::cout << "Bureaucrat Constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	grade = other.grade;
	return *this;
}
std::ostream &operator<<(std::ostream &os, const Bureaucrat &other)
{
	return os << other.name << ", bureaucrat grade " << other.grade << ".", os;
}

/*** --------------------------------- METHODS ----------------------------------*/
void Bureaucrat::incrementGrade()
{
	grade--;
	if (grade < 1)
	{
		grade = 1, throw Bureaucrat::GradeTooHighException();
	}
}
void Bureaucrat::decrementGrade()
{
	grade++;
	if (grade > 150)
	{
		grade = 150, throw Bureaucrat::GradeTooLowException();
	}
}
Bureaucrat::GradeTooHighException::GradeTooHighException() : std::runtime_error("grade to high")
{
}
Bureaucrat::GradeTooLowException::GradeTooLowException() : std::runtime_error("grade to low")
{
}

void Bureaucrat::signForm(Form& form)
{
	if (form.getSigne() == true)
	{
		std::cout << name
		<< " signed "
		<< form.getName()
		<<std::endl;
		return ;
	}
	std::cout << name
	<< " couldn't sign "
	<< form.getName()
	<< " because "
	<< "grade to low " 
	<<std::endl;
}
/*** --------------------------------- ACCESSOR ---------------------------------*/
const std::string& Bureaucrat::getName() const
{
	return name;
}
int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::setGrade(int _grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
	grade = _grade;
}