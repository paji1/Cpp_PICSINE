/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:40:49 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/12/06 14:20:05 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->count = 0;
}

void  PhoneBook::start()
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
			show(), std::cout << Get_index() << std::endl;
		}
		if (state == EXIT)
			return ;
	}
	else
	{
		std::cout << red 
		<<"WRONG CHOICE  TRY AGAIN"
		<<nc
		<<std::endl;
	}
	start();
}

int  PhoneBook::get_state()
{
	std::string buff;
	while (buff.empty() || buff.find_first_not_of (' ') == buff.npos)
	{
		std::cout << magenta << 
		"Welcome to Phone book \n"<<
		cayan<<
		"choose ADD or SEARCH or EXIT:" << 
		nc <<
		std::endl;
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
	
	std::cout << "|";
	phonebook[count].print_element("index");
	phonebook[count].print_element("first name");
	phonebook[count].print_element("last name");
	phonebook[count].print_element("nickname");
	std::cout << std::endl;
	for (int i = 0; i < NTAB ; i++)
		phonebook[i].showContact();	
}

int PhoneBook::Get_index()
{
	std::string buff;
	int index = -1;

	while (index < 0 || index >= 8)
	{
		std::cout << yellow << "Enter index of contact :" << nc <<std::endl;
		getline(std::cin, buff);
		std::stringstream geek(buff);
		geek >> index;
		if (buff != "0" && !index)
			index = -1;
		std::cin.clear();
		std::clearerr(stdin);
	}
	return index;
}
PhoneBook::~PhoneBook()
{
}