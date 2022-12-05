#include "Contact.hpp"
#include <string>
#include <cstring>
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
		void show();
		int  get_state();
};

