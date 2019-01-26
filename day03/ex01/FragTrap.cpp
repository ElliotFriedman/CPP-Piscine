/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/25 16:15:43 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <cstdlib>
#include <iostream>

FragTrap::FragTrap(void)
{
	std::cout << "Initialized FragTrap without a constructor value\n";
}

FragTrap::FragTrap(const FragTrap &copy)
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
	std::cout << "Copy Constructor Called, Name: " + name + "\n";
}

FragTrap::FragTrap(std::string _name)
{
	std::srand(std::time(nullptr));
	name = _name;
	hitPoints = 100;
	maxHitPoints = 100;
	energyPoints = 100;
	maxEnergyPoints = 100;
	Level = 1;
	meleeAttackDamage = 30;
	rangedAttackDamage = 20;
	armorDamageReduction = 5;
	std::cout << "Constructor Called, Name: " + _name + "\n";
}

FragTrap	&FragTrap::operator=(FragTrap const &copy)
{
	std::cout << "Called the overriden = operator in fragtrap\n";
	FragTrap*	ret = new FragTrap(copy);
	return *ret;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor Called\n";
}

void	FragTrap::takeDamage(unsigned int amount)
{
	//	std::cout << "Health before taking damage: " + std::to_string(hitPoints) + "\n";
	std::string print = name +  " took " + std::to_string(amount) + " damage";
	hitPoints -= amount;
	print += (hitPoints > 0 ? " \33[92mand survived\33[0m\n" : "\33[91m and died\33[0m\n");
	std::cout << print;
	//	std::cout << "Health after taking damage: " + std::to_string(hitPoints) + "\n";
}

void	FragTrap::rangedAttack(FragTrap& target)
{
	if (target.hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot attack the dead\33[0m\n";
		return ;
	}
	if (hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot attack when you are dead\33[0m\n";
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
void	FragTrap::meleeAttack(FragTrap& target) 
{
	if (target.hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot attack the dead\33[0m\n";
		return ;
	}if (hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot attack when you are dead\n\33[0m";
		return ;
	}
	if (energyPoints - 25 < 0)
	{
		std::cout <<  "\33[91mNot enough energy points to mount a vaulthunter_dot_exe attack\n\33[0m";
		return ;
	}
	target.armorDamageReduction = target.armorDamageReduction < 0 ? 0 : target.armorDamageReduction;
	target.takeDamage(meleeAttackDamage - target.armorDamageReduction);
	std::cout << name + " melees " + target.name + " and inflicts " + std::to_string(meleeAttackDamage) + " points of damage\n";
}

void	FragTrap::beRepaired(unsigned int amount)
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

void	FragTrap::vaulthunter_dot_exe(FragTrap& target)
{
	if (target.hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot attack the dead\33[0m\n";
		return ;
	}if (hitPoints <= 0)
	{
		std::cout << "\33[91mError, you cannot attack when you are dead\33[0m\n";
		return ;
	}
	if (energyPoints - 25 < 0)
	{
		std::cout << "\33[91mNot enough energy points to mount a vaulthunter_dot_exe attack\n\33[0m";
		return ;
	}
	energyPoints -= 25;
	//5 randomly chosen attacks
	int attack = rand() % 9;
	std::string print = name;
	print += " launches a ";
	int	damage = 0;
	if (attack >= 8)
	{
		damage = 20;
		print += "bazooka";
	}
	else if (attack >= 6)
	{
		damage = 24;
		print += "triple stomp";
	}
	else if (attack >= 4)
	{
		damage = 1;
		print += "california sidewinder";
	}
	else if (attack >= 2)
	{
		damage = 21;
		print += "42 special";
	}
	else
	{
		damage = 42;
		print += "Xavier Niel Special";
	}
	damage -= target.armorDamageReduction--;
	damage = damage < 0 ? 0 : damage;
	print += " and deals " + std::to_string(damage) + " damage to " + target.name;
	print += "\n";
	std::cout << print;
	target.takeDamage(damage);
}
