/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:37:17 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/23 14:24:07 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieFactory.hpp"
#include "Zombie.hpp"

ZombieFactory::ZombieFactory(int numZombies)
{
	_allZombies	= new Zombie[numZombies];
	_numZombies = numZombies;
	int i = 0;
	while (i < numZombies)
	{
		_allZombies[i].announce();
		i++;
	}
	std::string print = "Created " + std::to_string(numZombies) + " zombies\n";
	std::cout << print;
}

ZombieFactory::~ZombieFactory()
{
	delete [] _allZombies;
	std::cout << "Destroyed all zombies\n";
}
