/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/25 17:27:32 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>

class FragTrap {



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
		FragTrap(void);
		FragTrap(const FragTrap& copy);
		FragTrap(std::string _name);
		~FragTrap( void );
		FragTrap &operator=(FragTrap const &operate);
		void			meleeAttack(FragTrap& target);
		void			takeDamage(unsigned int amount);
		virtual void	vaulthunter_dot_exe(FragTrap& target);
		void			beRepaired(unsigned int amount);
		void			rangedAttack(FragTrap &target);
};

#endif
