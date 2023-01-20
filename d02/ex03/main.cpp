/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:32:21 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/20 06:52:31 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>
int main(void)
{
	Point a = Point(-3.15f,5.41f); 
	Point b = Point(-2.31f,2.81f); 
	Point c = Point(-5.77f,3.29f); 
	Point point = Point(-3, 3); 
	Point point2 = Point(4.0f,4.0f);

	std::cout << bsp(a, b , c, point) << std::endl;
	std::cout << bsp(a, b , c, point2) << std::endl;
	return 0;
}
