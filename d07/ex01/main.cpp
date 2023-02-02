/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 21:48:34 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/02/02 00:16:45 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

void to_char_zero(char &t)
{
	t = '0';
}
void to_int_zero(int &t)
{
	t = 0;
}

int main(void)
{
	char a[6] = "1111";
	iter(a, 4, to_char_zero);
	std::cout << a << std::endl;
	int b[6] = {49, 49, 49, 49};
	iter(b, 4, to_int_zero);
	std::cout << b[0] << " " << b[1] << " You got the idea" << std::endl;
	return 0;
}
