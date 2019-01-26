/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/25 19:46:56 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap : protected ClapTrap
{
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
