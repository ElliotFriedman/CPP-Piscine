#include "Ncurses.hpp"
#include <ncurses.h>

//const int NewCurses::width = 50;
//const int NewCurses::height = 50;


NewCurses::NewCurses(void)
{
	my_win = initscr();

	this->window_height = 20;
	this->window_width = 20;
	this->width = 150;
	this->height = 50;
	this->start_width = 20;
	this->start_height = 20;
	cbreak();
	keypad(stdscr, TRUE);
	std::cout << "\e[8;" << this->height <<";" << this->width << "t";
}

NewCurses::~NewCurses() {}

NewCurses::NewCurses(const NewCurses &source)
{
	*this = source;
}

NewCurses&NewCurses::operator=(const NewCurses &source)
{
	if (this != &source)
	{
		this->my_win = source.my_win;
	}
	return (*this);
}

WINDOW  *NewCurses::get_win(void)
{
	return (this->my_win);
}

int NewCurses::get_height(void)
{
	return (this->height);
}

int NewCurses::get_width(void)
{
	return (this->width);
}

void NewCurses::clear_window(void)
{
	refresh();
}

void NewCurses::put_text(std::string text)
{
	printw(text.c_str());
}

int NewCurses::command(void)
{
	this->ch = getch();
	return (this->ch);
}

int NewCurses::get_command(void)
{
	return (this->ch);
}

void NewCurses::destroy_win(void)
{
	wborder(this->my_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(this->my_win);
	delwin(this->my_win);
}

void NewCurses::create_window(void)
{
	this->my_win = newwin(this->height, this->width, this->start_height, this->start_height);
	box(this->my_win, 0 , 0);
	wrefresh(this->my_win);
}

void NewCurses::end_window(void)
{
	endwin();
}


void NewCurses::start_up(void)
{
	this->start_height -= 1;
}


void NewCurses::start_down(void)
{
	this->start_height += 1;
}

void NewCurses::start_left(void)
{
	this->start_width += 1;
}

void NewCurses::start_right(void)
{
	this->start_width -= 1;
}
