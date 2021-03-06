/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:41:34 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/27 21:13:06 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Game.hpp"
#include <curses.h>
#include <iostream>

# define COLS 40
# define LINES 40

int		main(void) {
	Game	game(COLS, LINES);
	
	game.testLitterMap();
		game.dumpMap();
	
	game.updateObjects();

	std::cout << "\n";
		game.dumpMap();
	//game.run();
}
