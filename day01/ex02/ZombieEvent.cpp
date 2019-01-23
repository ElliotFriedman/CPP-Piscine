/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:37:17 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/22 23:44:06 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

void		ZombieEvent::setZombieType(std::string type, Zombie& change)
{
	change.setName(type);
}

Zombie*		ZombieEvent::newZombie(std::string name)
{
	Zombie *ret = new Zombie("Zombie Event");
	ret->setName(name);
	this->setZombieType("Zombie Event", ret);
	return ret;
}



