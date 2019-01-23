/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:37:17 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/23 11:45:39 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

void		ZombieEvent::setZombieType(std::string type, Zombie& change)
{
	change.setType(type);
}

Zombie*		ZombieEvent::newZombie(std::string name)
{
	Zombie *ret = new Zombie("Unthinking and undead");
	ret->setName(name);
	return ret;
}



