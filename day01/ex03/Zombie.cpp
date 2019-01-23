/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 21:57:20 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/23 14:18:33 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void			Zombie::announce(void) const
{
	std::cout << this << " " << _type << " Brainssssssssss..." << std::endl;
}

void			Zombie::setType(std::string type)
{
	_type = type;
}

void			Zombie::setName(std::string name)
{
	_name = name;
}

std::string 	Zombie::randStr(int len)
{
	int i = 0;
	
	std::srand(time(0));
	std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	std::string newstr;
	int pos;
	len += std::rand() % 16;
	while(i < len)
	{
		pos = ((std::rand() % (str.size() - 1)));
		newstr += str.substr(pos,1);
		i++;
	}
	return newstr.substr(std::rand() % 3, std::rand() % str.size() - 1);
}

Zombie			*Zombie::randomChump(void)
{
	Zombie	*ret = new Zombie();
	ret->setName(randStr(5));
	return ret;
}

Zombie::Zombie()
{
	_type = "Factory Created";
	_name = randStr(4) + randStr(3);
}
