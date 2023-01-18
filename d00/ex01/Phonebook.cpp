/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:40:49 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/18 06:10:05 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <stdlib.h>

PhoneBook::PhoneBook()
{
	std::cout << magenta << "Welcome to Phone book" << std::endl;
	this->count = 0;
}

void PhoneBook::start()
{
	state = get_state();
	if (state > 0)
	{
		if (state == ADD)
		{
			phonebook[count % NTAB].setContact();
			phonebook[count % NTAB].id = this->count % NTAB;
			count++;
		}
		else if (state == SEARCH)
		{
			show(), phonebook[Get_index()].showContactall();
		}
		if (state == EXIT)
			return;
	}
	else
	{
		std::cout << red
				  << "WRONG CHOICE  TRY AGAIN"
				  << nc
				  << std::endl;
	}
	start();
}

int PhoneBook::get_state()
{
	std::string buff;
	while (buff.empty() || buff.find_first_not_of(" \t") == buff.npos)
	{
		std::cout << cayan << "choose ADD or SEARCH or EXIT:" << nc << std::endl;
		getline(std::cin, buff);
		std::cin.clear();
		std::clearerr(stdin);
	}
	if (buff == "ADD")
		return ADD;
	else if (buff == "SEARCH")
		return SEARCH;
	else if (buff == "EXIT")
		return EXIT;
	return -1;
}

void PhoneBook::show()
{

	std::cout
		<< " -------------------------------------------"
		<< std::endl
		<< "|";
	phonebook[count].print_element("index");
	phonebook[count].print_element("first name");
	phonebook[count].print_element("last name");
	phonebook[count].print_element("nickname");
	std::cout << std::endl;
	for (int i = 0; i < NTAB; i++)
		phonebook[i].showContact();
	std::cout
		<< " -------------------------------------------"
		<< std::endl;
}

int PhoneBook::Get_index()
{
	std::string buff;
	int index = -1;

	if (count == 0)
		return std::cout << "phoneBook is empty" << std::endl, 0;
	while (index < 0 || index >= 8)
	{
		std::cout << yellow << "Enter index of contact (between 0 and 7):" << nc << std::endl;
		if (!getline(std::cin, buff))
			exit(1);
		std::stringstream geek(buff);
		geek >> index;
		if ((buff != "0" && !index) || buff.length() != 1)
			index = -1;
		std::cin.clear();
		std::clearerr(stdin);
	}
	if (phonebook[index].id == -1)
		std::cout << "NOT FOUND" << std::endl;
	return index;
}
PhoneBook::~PhoneBook()
{
}