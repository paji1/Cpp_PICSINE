/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 09:13:48 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/02/01 09:53:24 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(0));
	static int i;

	i = rand() % 5 + i ; 
	switch (((rand() + i ) % 3) )
	{
	case 0:
		return new A();
		break;
	case 1:
		return new B();
		break;
	default:
		return new C();
		break;
	}
};
void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}
void identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
}
int main(void)
{
	identify(generate());
	identify(*generate());
	for (int i = 0; i < 200 ; i++)
	identify(*generate());
	return 0;
}
