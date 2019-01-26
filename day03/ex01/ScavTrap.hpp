/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/25 16:13:56 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "FragTrap.hpp"

class ScavTrap : public FragTrap
{

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
		ScavTrap(const ScavTrap& copy);
		ScavTrap(std::string _name);
		~ScavTrap( void );
		ScavTrap &operator=(ScavTrap const &operate);
/*		void			meleeAttack(ScavTrap& target);
		void			takeDamage(unsigned int amount);
		void	vaulthunter_dot_exe(ScavTrap& target);
		void			beRepaired(unsigned int amount);
		void			rangedAttack(ScavTrap &target);
*/
		void    challengeNewComer(void);
		void	vaulthunter_dot_exe(FragTrap& target); //call challenge new comer
		void	challengeNewcomer(ScavTrap& target);
};

#endif
