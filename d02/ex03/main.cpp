/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:32:21 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/19 06:04:58 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>
int main(void)
{
	Point a = Point(4.0f,4.0f); 
	Point b = Point(1.0f,4.0f); 
	Point c = Point(4.0f,2.0f); 
	Point point = Point(3.0f,3.0f); 
	Point point2 = Point(4.0f,4.0f);

	std::cout << bsp(a, b , c, point) << std::endl;
	std::cout << bsp(a, b , c, point2) << std::endl;
	return 0;
}
