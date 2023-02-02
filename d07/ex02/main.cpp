

#include "Array.hpp"
int main(void)
{
	try 
	{
		Array <int>tab = Array<int>(-5);
		tab[1] = 1;
		Array <int>tab2 = Array<int>(5);
		tab2[1] = 12;
		tab = tab2; 	
		std::cout << tab[1] << std::endl;
		tab[1] = 12;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
