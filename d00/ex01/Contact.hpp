#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
#include <string>
#include <iostream>
#include <cstdio>
#define nc     "\033[0m"
#define red     "\033[1;31m"
#define cayan     "\033[1;36m"
#define green      "\033[1;32m"
#define yellow       "\033[1;33m"
#define magenta        "\033[1;35m"
class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phonenumber;
		std::string darcksecret;
	public:
		// Contact();
		~Contact();
		void setContact();
		std::string printmessageGet(const char *);
};
// Contact::Contact()
// {
// 		this->firstName;
// 		this->lastName;
// 		this->nickname;
// 		this->phonenumber;
// 		this->darcksecret;
// }

void Contact::setContact()
{
	if (firstName.empty())
		firstName = printmessageGet("first name");
	if (lastName.empty())
		lastName = printmessageGet("last name");
	if (nickname.empty())
		nickname = printmessageGet("nickname");
	if (phonenumber.empty())
		phonenumber = printmessageGet("phonenuber");
	if (darcksecret.empty())
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
#endif