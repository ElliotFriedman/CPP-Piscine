/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:17:19 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/23 23:40:29 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"
#include <iostream>

class HumanA {

	std::string _name;
	Weapon	&_userWeapon;

	public:

	HumanA(std::string name, Weapon& userWeapon) : _userWeapon(userWeapon)
	{
		_name = name;
	}


	void		attack(void)
	{
		std::cout << _name + " attacks with his " + _userWeapon.getType() + "\n";
	}

};

#endif
