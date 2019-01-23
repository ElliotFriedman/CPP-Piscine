/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:57:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/22 23:39:59 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void			Zombie::announce(void) const
{
	std::cout << getName() << " " << getType() << " Brainssssssssss..." << std::endl;
}

std::string		Zombie::getType(void) const
{
	return _type;
}

void			Zombie::setName(std::string name)
{
	_name = name;
}

std::string		Zombie::getName(void) const
{
	return _name;
}

std::string 	Zombie::randStr(void)
{
	int len = 6;
	int i = 0;
	
	std::srand(time(0));
	std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string newstr;
	int pos;
	
	while(i < len)
	{
		pos = ((std::rand() % (str.size() - 1)));
		newstr += str.substr(pos,1);
		i++;
	}
	return newstr;
}

Zombie			*Zombie::randomChump(void)
{
	Zombie	*ret = new Zombie("random chump");
	ret->setName(randStr());
	return ret;
}

Zombie::Zombie(std::string type)
{
	_type = type;
	_name = randStr();
}
