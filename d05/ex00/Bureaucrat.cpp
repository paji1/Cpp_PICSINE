#include "Bureaucrat.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(1)
{
	std::cout << "Bureaucrat Constructor called" << std::endl;
}
Bureaucrat::Bureaucrat(std::string _name, int _grade) : name(_name)
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
	return os << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl, os;
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

/*** --------------------------------- ACCESSOR ---------------------------------*/
const std::string& Bureaucrat::getName() const
{
	return name;
}
int Bureaucrat::getGrade() const
{
	return grade;
}

Bureaucrat::GradeTooHighException::GradeTooHighException() : std::runtime_error("grade to high")
{
}
Bureaucrat::GradeTooLowException::GradeTooLowException() : std::runtime_error("grade to low")
{
}