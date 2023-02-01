/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 08:40:57 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/02/01 09:03:53 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"
int main(void)
{
	Data data;
	uintptr_t pt;
	data.data = 42;
	std::cout << &data << std::endl;
	std::cout << (pt = Serializer::serialize(&data)) << std::endl;
	std::cout << Serializer::deserialize(pt) << std::endl;
	std::cout << Serializer::deserialize(pt)->data << std::endl;
	return 0;
}
