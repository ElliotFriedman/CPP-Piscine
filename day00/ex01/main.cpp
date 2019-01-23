/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:32:59 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/22 18:34:23 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <iomanip>

#include "Contact.class.hpp"

Contact		allPeople[8];

void search(int contactIndex)
{
	std::string tmp;

	int i = 0;
	while (i < contactIndex)
	{
		std::cout << std::setw(10) << i;

		std::string first =  allPeople[i].getFirst();
		first = first.length() >= 10 ? first.substr(0,9) + "." : first;
		std::cout << "|" << std::setw(10) << first;

		std::string last =  allPeople[i].getLast();
		last = last.length() >= 10 ? last.substr(0,9) + "." : last;
		std::cout << "|" << std::setw(10) << last; 

		std::string nick = allPeople[i].getNick();
		nick = nick.length() >= 10 ? nick.substr(0,9) + "." : nick;
		std::cout << "|" << std::setw(10) << nick << std::endl; 

		i++;
	}
	std::cout << "Enter the desired contact index to display all information" << std::endl;
	int idx = -1;
	while (idx < 0 || 7 < idx)
	{
		std::cout << "Number must be between 0 and " << (contactIndex > 7 ? 7 : contactIndex - 1) << " inclusive" <<  std::endl;
		std::cin.clear();
		std::cin >> idx;
	}
	std::cout << allPeople[idx].getAll();
}

int main(void)
{
	std::string	command;
	int			contactIndex = 0;

	while (1)
	{
		std::getline(std::cin, command);
		if (std::cin.fail())
		{
			std::cout << "cin failed" << std::endl;
			break;
		}
		if (!command.compare("EXIT"))
			return 0;

		else if (!command.compare("ADD"))
		{
			if (contactIndex > 7)
				std::cout << "Error, contact book full" << std::endl;
			else
			{
				contactIndex++;
				allPeople[contactIndex - 1].addUser();
			}	
		}
		else if (!command.compare("SEARCH"))
		{
			search(contactIndex);
		}
		command = std::string();
	}

}
