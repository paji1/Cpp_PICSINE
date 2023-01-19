/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:32:42 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/19 06:05:28 by tel-mouh         ###   ########.fr       */
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

Fixed::Fixed(/* args */) : num(0) {}
Fixed::Fixed(const int _num) { num = 0, num = _num << frac; }
Fixed::Fixed(const float _fnum) { num = roundf(_fnum * 256); }
Fixed::Fixed(const Fixed &other) { *this = other; }

Fixed &Fixed::operator=(const Fixed &other) { return this->num = other.num, *this; }
std::ostream &operator<<(std::ostream &os, const Fixed &other) { return ((char)other.num == 0) ? os << (other.toInt()) : os << other.toFloat(), os; }

int Fixed::getRawBits(void) const { return num; }
float Fixed::toFloat(void) const { return (float)num / 256; }

int Fixed::toInt(void) const { return num >> 8; }

bool Fixed::operator<(const Fixed &other) { return this->num < other.num; }
bool Fixed::operator>(const Fixed &other) { return this->num > other.num; }
bool Fixed::operator>=(const Fixed &other) { return this->num >= other.num; }
bool Fixed::operator<=(const Fixed &other) { return this->num <= other.num; }
bool Fixed::operator==(const Fixed &other) { return this->num == other.num; }
bool Fixed::operator!=(const Fixed &other) { return this->num != other.num; }

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed a;
	a.num = num + other.num;
	return a;
}
Fixed Fixed::operator-(const Fixed &other)
{
	Fixed a;
	a.num = num - other.num;
	return a;
}
Fixed Fixed::operator++() { return ++num, *this; }
Fixed Fixed::operator++(int)
{
	Fixed t;
	t.num = num;
	num++;
	return t;
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed t;
	t.num = (((long long)num * (long long)other.num) >> 8);
	return t;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) { return a < b ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return a > b ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (Fixed(a) < Fixed(b)) ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (Fixed(a) > Fixed(b)) ? a : b; }
Fixed::~Fixed() {}
