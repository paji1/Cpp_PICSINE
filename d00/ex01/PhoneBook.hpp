#include "Contact.hpp"
#include <string>
#include <iostream>
#define ADD 3
#define SEARCH 4 
#define EXIT 5 
class PhoneBook
{
	private:
		int count;
		int state;
		Contact phonebook[8];
	public:
		PhoneBook();
		~PhoneBook();

		void start();
		int  get_state();
};

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
		start();
	}
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

// void  PhoneBook::show()
// {
	
// }

// void  PhoneBook::add(std::string newStr)
// {
// 	Contact newContact;

// 	newContact.setContact(newStr);
// 	this->phonebook[count % 8] = newContact;
// 	count++;
// }
