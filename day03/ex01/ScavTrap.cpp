/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/25 17:51:53 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cstdlib>
#include <iostream>

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::srand(std::time(nullptr));
	name = copy.name;
	hitPoints = copy.hitPoints;
	maxHitPoints = copy.maxHitPoints;
	energyPoints = 	copy.energyPoints;
	maxEnergyPoints = 	copy.maxEnergyPoints ;
	Level = copy.Level;
	meleeAttackDamage = copy.meleeAttackDamage; 
	rangedAttackDamage = copy.rangedAttackDamage;
	armorDamageReduction = copy.armorDamageReduction;
	std::cout << "Copy Constructor Called in ScavTrap, Name: " + name + "\n";
}

ScavTrap::ScavTrap(std::string _name)
{
	std::srand(std::time(nullptr));
	name = _name;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 50;
	maxEnergyPoints = 50;
	Level = 1;
	meleeAttackDamage = 25;
	rangedAttackDamage = 15;
	armorDamageReduction = 3;

	std::cout << "Constructor Called in ScavTrap, Name: " + _name + "\n";
	std::cout << "Hitpoints: " + std::to_string(hitPoints) + "\n";
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << "Called the overriden = operator in fragtrap\n";
	ScavTrap*	ret = new ScavTrap(copy);
	return *ret;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor Called\n";
}

void	ScavTrap::challengeNewComer(void)
{	
	if (hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot challenge when you are dead and have a health of " + std::to_string(hitPoints)  + "\33[0m\n";
		return ;
	}
	//5 randomly chosen challenges
	int challenge = rand() % 9;
	std::string print = name;
	print += " challenges you to fight ";
	if (challenge >= 8)
		print += "a big bad baboon";
	else if (challenge >= 6)
		print += "a psycopath with no clothes";
	else if (challenge >= 4)
		print += "a crab with big arms";
	else if (challenge >= 2)
		print += "all of bocal";
	else
		print += "Xavier Niel Special";
	print += "\n";
	std::cout << print;
}

void	ScavTrap::vaulthunter_dot_exe(FragTrap& target)
{
	std::cout << "\33[91mError, you cannot access vaulthunter_dot_exe in ScavTrap.Goodbye\33[0m\n";
	target = target;		
	return ;
}
