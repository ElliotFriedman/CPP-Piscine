/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/25 22:35:53 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <string>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(const FragTrap& copy);
		FragTrap(std::string _name);
		~FragTrap( void );
		FragTrap &operator=(FragTrap const &operate);
		int				error(std::string attack, FragTrap& target);	
		void			vaulthunter_dot_exe(FragTrap& target);
};

#endif
