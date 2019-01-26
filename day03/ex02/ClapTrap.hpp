/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/25 22:30:53 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

class ClapTrap {

	protected:
		int hitPoints;
		int maxHitPoints;
		int energyPoints;
		int maxEnergyPoints;
		int Level;
		std::string name;
		int meleeAttackDamage;
		int	rangedAttackDamage;
		int armorDamageReduction;

	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& copy);
		ClapTrap(std::string _name);
		~ClapTrap( void );
		ClapTrap &operator=(ClapTrap const &operate);
		void    takeDamage(unsigned int amount);
		void    rangedAttack(ClapTrap& target);
		void    meleeAttack(ClapTrap& target);
		void    beRepaired(unsigned int amount);

};

#endif
