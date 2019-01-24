/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:17:19 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/23 23:39:39 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanB {

	std::string _name;
	Weapon	&_userWeapon;

	public:

	HumanB(std::string name, Weapon& userWeapon) : _userWeapon(userWeapon)
	{
		_name = name;
	}


	void		attack(void)
	{
		std::cout << _name + " attacks with his " + _userWeapon.getType() + "\n";
	}

};

#endif
