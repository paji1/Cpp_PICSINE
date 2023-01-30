/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:29:00 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/30 18:21:08 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
int main()
{
	try
	{
		Intern someRandomIntern;
		Form *rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		Bureaucrat bure = Bureaucrat("taha", 1);
		rrf->beSigned(bure);
		bure.signForm(*rrf);
		bure.executeForm(*rrf);
		delete rrf;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
