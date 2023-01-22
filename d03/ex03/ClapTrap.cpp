/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:02:09 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/21 09:40:19 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
void ClapTrap::attack(const std::string &target)
{
	if (!energy)
		return;
	std::cout << "ClapTrap "
			  << name
			  << " attacks "
			  << target
			  << ", causing "
			  << damage
			  << " points of damage!"
			  << std::endl;
	energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout
		<< name
		<< " take damage amount : "
		<< amount
		<< std::endl;
	hit -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!energy)
		return;
	std::cout
		<< name
		<< " got repaired : "
		<< amount
		<< std::endl;
	hit += amount;
	energy--;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	this->damage = other.damage;
	this->hit = other.hit;
	this->energy = other.energy;
	this->name = other.name;
	return *this;
}

ClapTrap::ClapTrap(/* args */) : hit(10),
								 energy(10),
								 damage(0)
{
	std::cout << "constructor of ClapTrap call " << std::endl;
}
ClapTrap::ClapTrap(std::string _name) : name(_name),
										hit(10),
										energy(10),
										damage(0)
{
	std::cout << "constructors of ClapTrap "
			  << _name
			  << " call " << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "destructor of ClapTrap call " << std::endl;
}
