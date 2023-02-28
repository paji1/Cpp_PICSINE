#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <vector>

struct Not_found : public std::runtime_error
{
	Not_found();
};

Not_found::Not_found() : runtime_error("int not_found")
{

}

template <typename T>
typename T::iterator easyfind(T &a, int b)
{
	typename T::iterator it =  find(a.begin(), a.end(), b);
	if (it == a.end())
		throw Not_found();
	return it;
}

#endif /* * EASYFIND_H */