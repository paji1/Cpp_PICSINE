/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 04:25:22 by tel-mouh          #+#    #+#             */
/*   Updated: 2022/12/03 15:09:32 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "headers.hpp"
# include <stdio.h>
#include <string>
class Rectangle {
    int width, height;
  public:
    void set_values (int, int);
    int area (void);
};

void Rectangle::set_values(int width, int height)
{
	this->width = width;
	this->height = height;
}
int Rectangle::area (void)
{
	return this->width * this->height;
}

int main(void)
{
	Rectangle rect;

	rect.set_values(12, 2);
	std::cout <<  rect.area();
}