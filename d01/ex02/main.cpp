/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 21:07:52 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/05 21:14:56 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main( void )
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str; 
	std::string& stringREF = str;
	std::cout << "address of str       :" << &str << std::endl;
	std::cout << "address in stringPTR :" << stringPTR << std::endl;
	std::cout << "address in stringREF :" << &stringREF << std::endl << std::endl;
	
	std::cout << "value of str         :" << str << std::endl;
	std::cout << "value of stringPTR   :" << *stringPTR << std::endl;
	std::cout << "value of stringREF   :" << stringREF << std::endl << std::endl;
	return 0;
}
