#include "AForm.hpp"
/*** ------------------------------- CONSTRUCTOR --------------------------------*/

/**
 * @brief
 * @param grade
 * @param grade_exec
 * @param name
*/
Form::Form() : name("Form"), signe(false), grade(150), grade_exec(150)
{
	std::cout << "Form Constructor called" << std::endl;
}

Form::Form(int _grade, int _grade_exec, std::string _name) : name(_name),
															 signe(false),
															 grade(_grade),
															 grade_exec(_grade_exec)
{
	if (_grade < 1 || _grade_exec < 1)
		throw GradeTooHighException();
	if (_grade > 150 || _grade_exec > 150)
		throw GradeTooLowException();
	std::cout << "Form Constructor called" << std::endl;
}

Form::Form(Form const &other) : grade(other.grade)
{
	grade_exec = other.grade_exec;
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
Form &Form::operator=(Form const &other)
{
	grade_exec = other.grade_exec;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &other)
{
	os << "----------form-----------\n"
		<< "name : "
	   << other.name
	   << ", grade to sign : "
	   << other.grade
	   << ", grade to execute : "
	   << other.grade_exec
	   << "\n"
	   << "signed status : "
	   << other.signe
	   << "\n----------------------" ;
	return os;
}
/*** --------------------------------- METHODS ----------------------------------*/
void Form::beSigned(Bureaucrat &other)
{
	if (other.getGrade() <= grade)
		return this->signe = true, (void)0;
	throw GradeTooLowException();
}
bool Form::beExecute(Bureaucrat const &other) const
{
	if (this->signe == false)
		throw NotSigne();
	if (other.getGrade() <= grade_exec)
		return true;
	throw GradeTooLowException();
}
Form::GradeTooHighException::GradeTooHighException() : std::runtime_error("grade to high")
{
}
Form::GradeTooLowException::GradeTooLowException() : std::runtime_error("grade to low")
{
}
Form::NotSigne::NotSigne() : std::runtime_error("NotSigne")
{
}
/*** --------------------------------- ACCESSOR ---------------------------------*/

const std::string &Form::getName() const
{
	return this->name;
}
bool Form::getSigne() const
{
	return this->signe;
}
int Form::getGrade() const
{
	return this->grade;
}
int Form::getGrade_exec() const
{
	return this->grade_exec;
}