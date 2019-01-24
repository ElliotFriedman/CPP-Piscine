/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:17:19 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/23 23:34:41 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {

	std::string _type;

	public:

	Weapon(std::string type)
	{
		_type = type;
	}

	void	setType(std::string type)
	{
		_type = type;
	}

	std::string		getType(void)
	{
		return _type;
	}

};

#endif
