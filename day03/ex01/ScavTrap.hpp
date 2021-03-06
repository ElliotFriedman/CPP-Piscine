/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/25 17:51:44 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <string>
#include "FragTrap.hpp"

class ScavTrap : public FragTrap
{
	public:
//		ScavTrap::ScavTrap(const FragTrap &copy);
		ScavTrap(const ScavTrap& copy);
		ScavTrap(std::string _name);
		~ScavTrap( void );
		ScavTrap &operator=(ScavTrap const &operate);
		void    challengeNewComer(void);
		void	vaulthunter_dot_exe(FragTrap& target); //call challenge new comer
		void	challengeNewcomer(ScavTrap& target);
};

#endif
