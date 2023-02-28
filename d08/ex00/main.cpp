#include "Easyfind.hpp"
#include <vector>


int main(void)
{
	try
	{
		std::vector<int> tab(12, 0);
		
		tab[7] = 12;
		for (size_t i = 0; i < tab.size(); i++)
			std::cout << tab[i] << std::endl;
		std::vector<int>::iterator it = easyfind(tab, 12);
		std::cout << "number founded "<< *it << std::endl;
		*it = 13;
		for (size_t i = 0; i < tab.size(); i++)
			std::cout << tab[i] << std::endl;
		it = easyfind(tab, 12);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
