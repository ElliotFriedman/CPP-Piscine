#include "../inc/ft_gkrellm.hpp"
#include "../inc/Ncurses.hpp"
#include <ncurses.h>
#include <vector>

Ncurses::Ncurses( Ncurses &obj){}

Ncurses::Ncurses(void){}

Ncurses::~Ncurses(void){}

Ncurses &Ncurses::operator=(Ncurses &obj)
{
	return this;
}



WINDOW *Ncurses::create_newwin(int height, int width, int starty, int startx)
{
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);
	wrefresh(local_win);
	return local_win;
}

void Ncurses::destroy_win(WINDOW *local_win)
{	
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}

void Ncurses::display(HostnameInfo &host, 
		CPUInfo &cpu,
		DateTimeInfo &datetime, 
		NetworkInfo &network, 
		OSInfo &os, 
		RAMInfo &ram,
		std::vector<WINDOW *> &windows)
{
	refresh();
	for (int i = 0; i < 6; i++)
	{
		wborder(windows[i], ' ', ' ', ' ',' ',' ',' ',' ',' ');
		wrefresh(windows[i]);
	}

	int start = 10;
	if (host.getDisplay())
	{
		destroy_win(windows[0]);
		windows[0] = create_newwin(5, 45, start, 10);
		start += 2;
		mvaddstr(start, 13, const_cast<char *>(host.data().c_str()));
		start += 5;
	}
	if (cpu.getDisplay())
	{
		destroy_win(windows[1]);
		windows[1] = create_newwin(6, 45, start, 10);
		start += 2;
		mvaddstr(start++, 13, const_cast<char *>(cpu.data().c_str()));
		mvaddstr(start, 13, const_cast<char *>(cpu.data1().c_str()));
		start += 5;
	}	
	if (datetime.getDisplay())
	{
		destroy_win(windows[2]);
		windows[2] = create_newwin(5, 45, start, 10);
		start += 2;
		mvaddstr(start, 13, const_cast<char *>(datetime.data().c_str()));
		start += 5;
	}
	if (network.getDisplay())
	{
		destroy_win(windows[3]);
		windows[3] = create_newwin(8, 45, start, 10);
		network.data();
		start += 2;
		mvaddstr(start++, 13, const_cast<char *>(("Total bytes receieved " + std::to_string(network.getInBytes())).c_str()));
		mvaddstr( start++, 13, const_cast<char *>(("Total bytes sent " + std::to_string(network.getOutBytes())).c_str()));
		mvaddstr(start++, 13, const_cast<char *>(("Total packets receieved " + std::to_string(network.getInPackets())).c_str()));
		mvaddstr(start, 13, const_cast<char *>(("Total packets sent " + std::to_string(network.getOutPackets())).c_str()));
		start += 5;
	}
	if (ram.getDisplay())
	{
		destroy_win(windows[4]);
		windows[4] = create_newwin(6, 45, start, 10);
		start += 2;
		mvaddstr(start++, 13, const_cast<char *>(ram.data().c_str()));
		mvaddstr(start, 13, const_cast<char *>(ram.memUsage().c_str()));
		start += 5;
	}
	if (os.getDisplay())
	{
		destroy_win(windows[5]);
		windows[5] = create_newwin(6, 45, start, 10);
		start += 2;
		mvaddstr(start, 13, const_cast<char *>(os.data().c_str()));
	}
}

void	Ncurses::initscreen(void)
{
	initscr();
	cbreak();
	keypad(stdscr, TRUE);
	noecho();
	refresh();
	halfdelay(5);
	curs_set(0);
}

void	Ncurses::init_win(std::vector<WINDOW *> &windws)
{
	int width;

	width = 45;
	windws[0] = create_newwin(6, width, 9, 10);
	windws[1] = create_newwin(6, width, 15, 10);
	windws[2] = create_newwin(5, width, 21, 10);
	windws[3] = create_newwin(8, width, 26, 10);
	windws[4] = create_newwin(6, width, 34, 10);
	windws[5] = create_newwin(4, width, 37, 10);
}

void	Ncurses::run(void)
{
	HostnameInfo    host;
	CPUInfo         cpu;
	DateTimeInfo    datetime;
	NetworkInfo     network;
	OSInfo          os;
	RAMInfo         ram;
	std::vector<WINDOW *> windws;
	int ch;

	windws.reserve(6);
	init_win(windws);
	initscreen();

	printw("Press F1 to exit\n\n\t\t\tToggle Diplay\n\t\t\t1. Host\n\t\t\t2. CPU\n\t\t\t3. Date and Time\n\t\t\t4. Network Info\n\t\t\t5. RAM\n\t\t\t6. Operating System\n");
	display(host, cpu, datetime, network, os, ram, windws);
	while ((ch = getch()) != KEY_F(1))
	{
		display(host, cpu, datetime, network, os, ram, windws);
		switch(ch)
		{
			case 49:
				host.setDisplay(!host.getDisplay());
				break;
			case 50:
				cpu.setDisplay(!cpu.getDisplay());
				break;
			case 51:
				datetime.setDisplay(!datetime.getDisplay());
				break;
			case 52:
				network.setDisplay(!network.getDisplay());
				break;	
			case 53:
				ram.setDisplay(!ram.getDisplay());
				break;
			case 54:
				os.setDisplay(!os.getDisplay());
				break;
			default:
				break;
		}
	}
	for (int i = 0; i < 6; i++)
		delwin(windws[i]);
	endwin();
}
