#include "Contact.hpp"
#include <string>
#include <cstring>
#include <iostream>

#define ADD 3
#define SEARCH 4 
#define EXIT 5 
#define NTAB 8
class PhoneBook
{
	private:
		int count;
		int state;
		Contact phonebook[NTAB];
	public:
		PhoneBook();
		~PhoneBook();

		void start();
		void show();
		int  get_state();
		int  Get_index();
};

