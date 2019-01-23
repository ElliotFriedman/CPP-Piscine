/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:52:37 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/22 23:37:31 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {

	std::string _type;
	std::string _name;

	public:
	std::string		randStr(void);
	void			setName(std::string name) ;
	std::string		getName(void) const;
	std::string		getType(void) const;
	Zombie			*randomChump(void);
	Zombie(std::string type);
	void			announce(void) const;
};

#endif
