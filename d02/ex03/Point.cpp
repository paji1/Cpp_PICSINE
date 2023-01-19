/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 23:27:24 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/19 01:03:11 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(/* args */) : x(0), y() {}
Point::Point(float _x, float _y) : x(_x), y(_y) {}
Point::Point(const Point &other) { *this = other; }

Point &Point::operator=(const Point &other) { return x = other.x, y = other.y, *this; }

Fixed Point::get_x() {return x;}
Fixed Point::get_y() {return y;}
Point::~Point() {}
