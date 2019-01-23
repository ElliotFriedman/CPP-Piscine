/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 23:30:40 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/23 11:55:05 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"
#include "Zombie.hpp"

int main()
{
	Zombie *a = new Zombie("Heap Zombie");
	ZombieEvent factory;
	Zombie d("Stack Zombie");

	Zombie *b = factory.newZombie("No Brains and No Spine!");	

	//this function takes d by reference
	factory.setZombieType("Factory modified zombie", d);

	Zombie *c = b->randomChump();
	std::cout << "Announcing A" << std::endl;	
	a->announce();
	std::cout << "Announcing B" << std::endl;
	b->announce();
	std::cout << "Announcing C" << std::endl;	
	c->announce();
	std::cout << "Announcing D" << std::endl;
	d.announce();
}
