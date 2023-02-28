/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:30:18 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/02/28 00:11:18 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
Span sp = Span(100);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(9);
sp.addNumber(11);
sp.addNumber(17);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
sp.iota(1, 50);

return 0;
}

// int main(void)
// {
		
	// Span a(1);


	// try
	// {
	// 	a.shortestSpan();
	// 	a.addNumber(12);
	// 	a.addNumber(2);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
// 	return 0;
// }


