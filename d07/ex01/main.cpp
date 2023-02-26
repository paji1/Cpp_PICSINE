/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:48:34 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/02/26 21:34:34 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

template <typename T>
void print( T   &  t)
{
	std::cout << "'" << t << "'" << std::endl;
}

void print_n(int  &t)
{
	std::cout << "'" << t << "'" << std::endl;
}

int main(void)
{
	{
		char a[] = "hello world";
		iter(a, sizeof(a) - 1, print);
		std::cout << a << std::endl;
	}
	std::cout << std::endl;
	{
		int b[] = {49, 49, 49, 49};
		iter(b, 4, print);
	}
	std::cout << std::endl;
	{
		int b[] = {50, 50, 50, 50};
		iter(b, 4, print_n);
	}
	return 0;
}
