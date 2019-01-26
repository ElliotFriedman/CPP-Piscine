/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/25 22:38:16 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(const ScavTrap& copy);
		ScavTrap(std::string _name);
		~ScavTrap( void );
		ScavTrap &operator=(ScavTrap const &operate);
		void		    challengeNewComer(void);
		void			challengeNewcomer(ScavTrap& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		void    		meleeAttack(ScavTrap& target);
};

#endif
