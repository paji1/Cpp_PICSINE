/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-mouh <tel-mouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:32:19 by tel-mouh          #+#    #+#             */
/*   Updated: 2023/01/05 18:54:09 by tel-mouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
Zombie* zombieHorde( int N, std::string name )
{
	Zombie *tab = new Zombie[N];
	for (int i = 0 ; i < N ; i++)
		tab[i].setName(name);
	return tab;
}