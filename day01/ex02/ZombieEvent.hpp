/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 22:33:36 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/22 23:43:10 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#ifndef ZOMBIE_EVENT_HPP
#define ZOMBIE_EVENT_HPP

class ZombieEvent {

	std::string	_type;

	public:
	void		setZombieType(std::string type);
	Zombie*		newZombie(std::string name);
	void		setZombieType(std::string type, Zombie& change);
};

#endif

