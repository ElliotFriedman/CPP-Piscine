/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 23:30:40 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/23 14:25:35 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieFactory.hpp"
#include "Zombie.hpp"

int main()
{
	ZombieFactory *factory = new ZombieFactory(10);//("Factory");

	delete factory;

	//test for leaks
	//while (1);
}
