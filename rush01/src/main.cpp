#include "../inc/ft_gkrellm.hpp"

void    display_help(void) {
    std::cout << "Usage: ./ft_gkrellm [-h|--help][-g|--gui][-t|-term]" << std::endl;
    std::cout << "-h | --help: display this help message" << std::endl;
    std::cout << "-g | --gui: launch program in graphical mode" << std::endl;
    std::cout << "-t | --term: launch program in terminal (default)" << std::endl;
}

int     main(int argc, char *argv[]) {
    std::string     arg;
    HostnameInfo    host;
    CPUInfo         cpu;
    DateTimeInfo    datetime;
    NetworkInfo     network;
    OSInfo          os;
    RAMInfo         ram;

    if (argc > 1) {
        arg.assign(argv[1]);
        if (arg == "-h" || arg == "--help") display_help();
        else if (arg == "-g" || arg == "--gui") {
            SDL sdl(host, cpu, datetime, network, os, ram);
            sdl.run();
        }
    }
	else {
        Ncurses curses;

		curses.run();
    }

    return 0;
}
