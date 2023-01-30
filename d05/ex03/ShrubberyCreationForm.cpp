#include "ShrubberyCreationForm.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
ShrubberyCreationForm::ShrubberyCreationForm() : Form(145, 137, "shrubbery creation")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : Form(145, 137, "shrubbery creation"),
																	target(_target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other)
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	target = other.target;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->beExecute(executor);
	std::fstream output(std::string(target).append("_shrubbery").c_str(), std::fstream::out | std::fstream::trunc);
	if (access(std::string(target).append("_shrubbery").c_str(), F_OK) == -1)
		return std::cerr << "faild to open" << std::endl, (void)0;
	if (!output.is_open())
		return std::cerr << "permession" << std::endl, (void)0;
	output << "          &&& &&  & &&" << std::endl
		   << "      && &\\/&\\|& ()|/ @, &&" << std::endl
		   << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl
		   << "   &() &\\/&|()|/&\\/ \'%\" & ()" << std::endl
		   << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl
		   << "&&   && & &| &| /& & % ()& /&&" << std::endl
		   << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl
		   << "     &&     \\|||" << std::endl
		   << "             |||" << std::endl
		   << "             |||" << std::endl
		   << "             |||" << std::endl
		   << "       , -=-~  .-^- _" << std::endl
		   << std::endl;
}
/*** --------------------------------- ACCESSOR ---------------------------------*/
