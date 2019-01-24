/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:50:52 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/23 23:06:23 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <sstream>

Brain			Human::getBrain(void)
{
	return _myBrain;
}

std::string		Human::identify(void)
{
	return _myBrain.identify();
}
