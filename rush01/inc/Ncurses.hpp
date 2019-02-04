/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurses.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmatthew <tmatthew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 22:57:06 by efriedma          #+#    #+#             */
/*   Updated: 2019/02/03 23:39:59 by tmatthew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSES_HPP
#define  NCURSES_HPP

#include <ncurses.h>

class Ncurses : public IMonitorDisplay
{

	WINDOW *create_newwin(int height, int width, int starty, int startx);
	void destroy_win(WINDOW *local_win);
	void display(HostnameInfo &host, 
			CPUInfo &cpu,
			DateTimeInfo &datetime, 
			NetworkInfo &network, 
			OSInfo &os, 
			RAMInfo &ram,
			std::vector<WINDOW *> &windows);
	void	initscreen(void);
	void	init_win(std::vector<WINDOW *> &windws);
	public:
		Ncurses( Ncurses &obj);
		Ncurses(void);
		~Ncurses(void);
		Ncurses &operator=(Ncurses &obj);
		void	run(void);
};

#endif
