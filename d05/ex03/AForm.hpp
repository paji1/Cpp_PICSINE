#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include <string>

class Bureaucrat;
# include "Bureaucrat.hpp"

class Form
{
private:
	const std::string name;
	bool signe;
	const int grade;
	int grade_exec;
	struct GradeTooHighException : public std::runtime_error
	{
		GradeTooHighException();
	};
	struct GradeTooLowException : public std::runtime_error
	{
		GradeTooLowException();
	};
	struct NotSigne : public std::runtime_error
	{
		NotSigne();
	};

public:
	Form();
	Form(int ,int ,  std::string name);
	Form(Form const &);
	virtual ~Form();

	void beSigned(Bureaucrat &);
	

	Form &operator=(Form const &);
	bool operator==(Form &);
	bool beExecute(Bureaucrat const &) const ;
	bool getSigne() const;
	int getGrade() const;
	int getGrade_exec() const;
	const std::string &getName() const;
	virtual void execute(Bureaucrat const & executor) const = 0;
};
std::ostream &operator<<(std::ostream &, const Form &);

#endif /* * FORM_H */