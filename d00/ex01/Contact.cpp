/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:39:27 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/12/05 12:23:58 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void print_info(std::string str)
{
	
	if (str.length() <= 10)
		return std::cout << str, void(0);
	std::cout << str.substr(0 , 9) << ".";
}

void Contact::print_element(std::string str)
{
	std::cout
        << std::right
        << std::setw(10);
        print_info(str);
	std::cout << '|';
}

void Contact::showContact()
{
	std::ostringstream nb;
	std::cout << "|";
	nb << count;
	print_element(nb.str());
	print_element(firstName);
	print_element(lastName);
	print_element(nickname);
	std::cout << std::endl;
}

void Contact::setContact()
{
	firstName = printmessageGet("first name");
	lastName = printmessageGet("last name");
	nickname = printmessageGet("nickname");
	phonenumber = printmessageGet("phonenuber");
	darcksecret = printmessageGet("your dark secret (you can trust me)");
}

std::string Contact::printmessageGet(const char *str)
{
	std::string buff;

	while (buff.empty())
	{
		std::cout << magenta << "Enter " << str << " :" << nc <<std::endl;
		getline(std::cin, buff);
		std::cin.clear();
		std::clearerr(stdin);
	}
	return buff;

}

Contact::~Contact()
{
}