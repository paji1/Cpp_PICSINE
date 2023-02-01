#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>
template <typename T> 
void iter(T *p, size_t len, void (*fun)(T const &))
{
	for (size_t i = 0; i < len ; i++)
		fun(*(p  + i));
}

template <typename T> 
void iter(T *p, size_t len, void (*fun)(T&))
{
	for (size_t i = 0; i < len ; i++)
		fun(*(p  + i));
}


#endif /* * WHATEVER_H */