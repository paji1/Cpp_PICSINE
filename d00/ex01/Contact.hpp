#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP
#include <string>
#include <iostream>
#include <iomanip>
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
		int count;
		~Contact();

		void setContact();
		void showContact();
		std::string printmessageGet(const char *);
		void print_element(std::string str);
};
#endif