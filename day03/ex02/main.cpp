/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 13:15:24 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/25 22:39:44 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	FragTrap a("Xavier");
	FragTrap b("Kwame");

	b.vaulthunter_dot_exe(a);	
	b.vaulthunter_dot_exe(a);	
	b.beRepaired(1000);
	a.beRepaired(1000);

	a.vaulthunter_dot_exe(b);	
	a.vaulthunter_dot_exe(b);	

	a.meleeAttack(b);
	a.rangedAttack(a);	
	b.rangedAttack(a);	
	a.meleeAttack(b);
	a.meleeAttack(b);
	b.beRepaired(1000);
	a.beRepaired(1000);
	b = a;
	a.meleeAttack(b);
	a.meleeAttack(b);
	a.meleeAttack(b);
	a.meleeAttack(b);
	b = a;
	a.meleeAttack(b);
	a.meleeAttack(b);
	a.meleeAttack(b);
	b = a;
	a.meleeAttack(b);

	b.beRepaired(1000);
	a.beRepaired(1000);
	a.meleeAttack(b);
	a.meleeAttack(b);
	a.meleeAttack(b);
	b.vaulthunter_dot_exe(a);	
	b.vaulthunter_dot_exe(a);	
	b.vaulthunter_dot_exe(a);	
	b.vaulthunter_dot_exe(a);	
	b.rangedAttack(a);	

	std::cout << "Creating a Scavtrap\n";
	ScavTrap c("Scavvy");
	c.rangedAttack(a);
	c.rangedAttack(b);
	c.rangedAttack(c);
	c.challengeNewComer();
	FragTrap d("hello");
	FragTrap e("b:");
	d.meleeAttack(e);
}
