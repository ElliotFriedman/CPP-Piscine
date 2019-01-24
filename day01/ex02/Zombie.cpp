/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:57:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/23 17:44:43 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void			Zombie::announce(void) const
{
	std::cout << _name << " " << _type << " Brainssssssssss..." << std::endl;
}

void			Zombie::setType(std::string type)
{
	_type = type;
}

void			Zombie::setName(std::string name)
{
	_name = name;
}

std::string		randomChar(void)
{
	std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	int pos = (std::rand() + std::time(nullptr))  % 60;
	std::string ret = str.substr(pos, 1);
	return ret;
}

std::string 	Zombie::randStr(int len)
{
	int i = 0;

	std::string newstr;
	len += std::rand() % 16;
	while(i < len)
	{
		newstr += randomChar();
		i++;
	}
	return newstr;
}

Zombie			*Zombie::randomChump(void)
{
	Zombie	*ret = new Zombie("random chump");
	ret->setName(randStr(5));
	return ret;
}

Zombie::Zombie(std::string type)
{
	_type = type;
	_name = randStr(4) + randStr(3);
}
