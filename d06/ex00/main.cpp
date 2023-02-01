/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 23:59:37 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/02/01 06:18:27 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include "Print_Utils.hpp"
int main(int ac, char **av)
{
	if (ac != 2)
		return std::cerr << "error"<< std::endl, 1;
	ScalarConverter::convert(av[1]);
	
}
