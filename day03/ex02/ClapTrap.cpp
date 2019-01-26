/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/25 22:33:46 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "Created a clap trap\n";
}

ClapTrap::ClapTrap(const ClapTrap& copy)
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
	std::cout << "Copy Constructor Called in ClapTrap, Name: " + name + "\n";	
}

ClapTrap::ClapTrap(std::string _name)
{
	name = _name;
	std::cout << "Created a clap trap\n";
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destroyed a clap trap\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap const &copy)
{
	name = copy.name;
	hitPoints = copy.hitPoints;
	maxHitPoints = copy.maxHitPoints;
	energyPoints = 	copy.energyPoints;
	maxEnergyPoints = 	copy.maxEnergyPoints ;
	Level = copy.Level;
	meleeAttackDamage = copy.meleeAttackDamage; 
	rangedAttackDamage = copy.rangedAttackDamage;
	armorDamageReduction = copy.armorDamageReduction;
	std::cout << "Equal overloaded Called in ClapTrap\n";
	return *this;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::string print = name +  " took " + std::to_string(amount) + " damage";
	hitPoints -= amount;
	print += (hitPoints > 0 ? " \33[92mand survived\33[0m\n" : "\33[91m and died\33[0m\n");
	std::cout << print;
}

void	ClapTrap::rangedAttack(ClapTrap& target)
{
	if (target.hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot attack the dead\33[0m\n";
		return ;
	}
	if (hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot attack when you are dead and have a health of " + std::to_string(hitPoints) + "\33[0m\n";
		return ;
	}
	if (energyPoints - 25 < 0)
	{
		std::cout << "\33[91mNot enough energy points to mount a ranged attack\n\33[0m";
		return ;
	}
	target.armorDamageReduction = target.armorDamageReduction < 0 ? 0 : target.armorDamageReduction;
	target.takeDamage(rangedAttackDamage - target.armorDamageReduction);
	std::cout << name + " does a range attack on " + target.name + " and inflicts " + std::to_string(rangedAttackDamage) + " points of damage\n";
}

//pdf got this wrong, it isn't a string, its another fragtrap
void	ClapTrap::meleeAttack(ClapTrap& target) 
{
	if (target.hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot attack the dead\33[0m\n";
		return ;
	}
	if (hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot attack when you are dead and have a health of " + std::to_string(hitPoints) + "\33[0m\n";
		return ;
	}
	if (energyPoints - 25 < 0)
	{
		std::cout << "\33[91mNot enough energy points to mount a melee attack\n\33[0m";
		return ;
	}
	target.armorDamageReduction = target.armorDamageReduction < 0 ? 0 : target.armorDamageReduction;
	target.takeDamage(meleeAttackDamage - target.armorDamageReduction);
	std::cout << name + " melees " + target.name + " and inflicts " + std::to_string(meleeAttackDamage) + " points of damage\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot bring back the dead\33[0m\n";
		return ;
	}
	hitPoints += amount;
	hitPoints = hitPoints > 100 ? 100 : hitPoints;
	std::cout << name + " just got repaired for " + std::to_string(amount) + " points and now has a total health of " + std::to_string(hitPoints) + "\n";
}

