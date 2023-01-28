/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:58:48 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/26 18:31:10 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/*** ------------------------------- CONSTRUCTOR --------------------------------*/
Ice::Ice()
{
	type = "ice";
	std::cout << "Ice Constructor called" << std::endl;
}
Ice::Ice(const Ice &other ) : AMateria(other)
{
	*this = other;
}

/*** -------------------------------- DESTRUCTOR --------------------------------*/
Ice::~Ice()
{
	std::cout << "Ice Destructor called" << std::endl;
}

/*** --------------------------------- OVERLOAD ---------------------------------*/
Ice&   Ice::operator=(Ice const & other )
{
	type = other.type;
	return *this;
}

/*** --------------------------------- METHODS ----------------------------------*/

AMateria* Ice::clone() const
{
	return new Ice();
}


/*** --------------------------------- ACCESSOR ---------------------------------*/
