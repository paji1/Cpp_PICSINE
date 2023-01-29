/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:29:00 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/30 00:50:10 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
int main()
{
	try
	{
		Bureaucrat bure = Bureaucrat("taha", 1);
		ShrubberyCreationForm treeform = ShrubberyCreationForm("Shrubbery.Creation");
		PresidentialPardonForm presidentialPardon = PresidentialPardonForm("Presidential Pardon");
		RobotomyRequestForm robotomyRequestForm = RobotomyRequestForm("Robotomy Request");
		treeform.beSigned(bure);
		bure.signForm(treeform);
		bure.executeForm(treeform);
		std::cout << std::endl;
		robotomyRequestForm.beSigned(bure);
		bure.signForm(robotomyRequestForm);
		std::cout << std::endl;
		bure.executeForm(robotomyRequestForm);
		std::cout << std::endl;
		std::cout << std::endl;
		bure.executeForm(robotomyRequestForm);
		std::cout << std::endl;
		presidentialPardon.beSigned(bure);
		bure.signForm(presidentialPardon);
		bure.executeForm(presidentialPardon);
		std::cout << bure << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what()<< std::endl;
	}
	return 0;
}
