/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:29:00 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/29 17:05:22 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
int main()
{
	try
	{
		Bureaucrat bure = Bureaucrat("taha", 12);
		Form form = Form(14,13, "form");
		form.beSigned(bure);
		bure.signForm(form);
		std::cout << form << std::endl;
		std::cout << bure << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what()<< std::endl;
	}
	return 0;
}
