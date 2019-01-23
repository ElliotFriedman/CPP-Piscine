/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:14:24 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/21 20:28:46 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <fstream>
#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	int i = 1;
	while (i < argc)
	{
		int j = 0;
		while (argv[i][j])
		{
			argv[i][j] = toupper(argv[i][j]);
			j++;
		}
		std::cout << argv[i];
		i++;
	}

	std::cout << std::endl;

}
