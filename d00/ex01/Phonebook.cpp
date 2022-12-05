/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 11:40:49 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/12/05 11:44:15 by tel-mouh         ###   ########.fr       */
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
			phonebook[count % 8].setContact();
		else if (state == SEARCH)
			std::cout  << "search" << std::endl;
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
	while (buff.empty())
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




PhoneBook::~PhoneBook()
{
}