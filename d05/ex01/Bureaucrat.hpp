#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <string>

class Form;
# include "Form.hpp"

class Bureaucrat
{
private:
	struct GradeTooHighException : public std::runtime_error
	{
		GradeTooHighException();
	};
	struct GradeTooLowException : public std::runtime_error
	{
		GradeTooLowException();
	};
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(std::string _name, int _grade);
	Bureaucrat(Bureaucrat const &);
	~Bureaucrat();
	const std::string &getName() const;
	int getGrade() const;
	void setGrade(int);
	void incrementGrade();
	void decrementGrade();
	void signForm(Form &);
	Bureaucrat &operator=(Bureaucrat const &);
};
std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif /* * BUREAUCRAT_H */