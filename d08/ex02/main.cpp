/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:36:11 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/03/01 00:05:39 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
# include <vector>
int main(void)
{
	
	MutantStack<int> l(12);

	l.push(1);

	MutantStack<int>::iterator la = l.begin();

	std::cout << *(la++) << std::endl;
	std::cout << *(--la) << std::endl;
	return 0;
}
