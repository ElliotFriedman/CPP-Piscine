/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:33:36 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/23 14:00:15 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#ifndef ZOMBIE_FACTORY_HPP
#define ZOMBIE_FACTORY_HPP

class ZombieFactory {

	Zombie	*_allZombies;
	int		_numZombies;

	public:
		ZombieFactory(int numZombies);
		~ZombieFactory();
	Zombie*		newZombie(std::string name);
	void		setZombieType(std::string type, Zombie& change);
};

#endif

