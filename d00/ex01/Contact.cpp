/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:39:27 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/18 06:12:23 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->id = -1;
}

void Contact::print_info(std::string str)
{

	if (str.length() <= 10)
		return std::cout << str, void(0);
	std::cout << str.substr(0, 9).append(".");
}

void Contact::print_element(std::string str)
{
	std::cout
		<< std::right
		<< std::setw(10)
		<< std::setfill(' ');
	print_info(str);
	std::cout << '|';
}

void Contact::showContact()
{
	if (id == -1)
		return;
	std::ostringstream nb;
	std::cout << "|";
	nb << id;
	print_element(nb.str());
	print_element(firstName);
	print_element(lastName);
	print_element(nickname);
	std::cout << std::endl;
}
void Contact::showContactall()
{
	if (id == -1)
		return;
	std::cout << "firstName :" << firstName << std::endl;
	std::cout << "lastName :" << lastName << std::endl;
	std::cout << "nickname :" << nickname << std::endl;
	std::cout << "phonenumber :" << phonenumber << std::endl;
	std::cout << "darcksecret :" << darcksecret << std::endl;
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

	while (buff.empty() || buff.find_first_not_of(" \t") == buff.npos)
	{
		std::cout << magenta << "Enter " << str << " :" << nc << std::endl;
		getline(std::cin, buff);
		std::cin.clear();
		std::clearerr(stdin);
	}
	return buff;
}

Contact::~Contact()
{
}
