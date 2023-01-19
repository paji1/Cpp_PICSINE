/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:32:42 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/17 03:16:30 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


void print_bin(void *a, int size)
{
	int i = -1;
	;
	while (++i < size)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << (int)(((*(char *)a) >> j) & 1);
		}
		std::cout << " ";
		a = ((char *)a) + 1;
	}
	std::cout << std::endl;
}

Fixed::Fixed(/* args */) : num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int _num)
{
	num = 0;
	num = _num << frac;
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float _fnum) { 
	std::cout << "Float constructor called" << std::endl;
	
	num = roundf(_fnum * 256); 
	}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = other.num;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &other)
{
	if ((char)other.num == 0)
		os << (other.toInt());
	else
		os << other.toFloat();
	return os;
}

float Fixed::toFloat(void) const
{
	return (float)num / 256;
}

int Fixed::toInt(void) const
{
	return num >> 8;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
