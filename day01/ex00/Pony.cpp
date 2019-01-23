/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:44:40 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/22 21:22:08 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Pony.hpp"
#include <iostream>

Pony::Pony()
{
	std::cout << "Pony has been created\n";
}

Pony::~Pony()
{
	std::cout << "Pony has been destroyed\n";
}


void	Pony::ponyOnTheHeap()
{
	Pony *n = new Pony();
	free(n);
}

void	Pony::ponyOnTheStack()
{
	Pony n;
}

