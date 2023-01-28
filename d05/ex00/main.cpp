/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 15:29:00 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/28 21:34:26 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
int main()
{
	Bureaucrat l("taha");
	try
	{
		l.decrementGrade();
		l.decrementGrade();
		std::cout << l.getGrade() << std::endl;
		for (int i = 0 ; i < 155; i++)	
		{	
			l.decrementGrade();
		}
		std::cout << l.getGrade() << std::endl;
	}
	catch(std::exception& e)
	{
		std::cout << e.what()<< std::endl;
	}
	return 0;
}
