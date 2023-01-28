/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:37:34 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/23 13:44:46 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
Animal::Animal(/* args */) : type("Animal")
{
	std::cout << "Animal Constructor called" << std::endl;
}

const std::string& Animal::getType() const
{	
	return this->type;
}
Animal::Animal(const Animal &other)
{
	*this = other;
}
Animal& Animal::operator=(const Animal &other)
{
	 this->type = other.type;
	 return *this;
}
void Animal::makeSound() const
{
	
}
Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
