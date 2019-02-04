#include "../inc/SDL.hpp"

SDL::SDL():
    IMonitorDisplay(), _window(NULL), _screenSurface(NULL),
    _host(), _cpu(), _datetime(), _network(), _os(), _ram()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "could not initialize sdl2: " << SDL_GetError() << std::endl;
    }
    _window = SDL_CreateWindow(
                    "ft_gkrellm",
                    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                    1000, 400,
                    SDL_WINDOW_ALLOW_HIGHDPI);
    if (_window == NULL) {
        std::cerr << "could not create window: " << SDL_GetError() << std::endl;
    }
    _screenSurface = SDL_GetWindowSurface(_window);
    SDL_FillRect(_screenSurface, NULL, SDL_MapRGB(_screenSurface->format, 0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(_window);
    if (TTF_Init() < 0) {
        std::cerr << "Error initializing ttf framework" << std::endl;
        exit(1);
    }
    if (!(_ttf = TTF_OpenFont("fonts/Roboto-Regular.ttf", 20))) {
        std::cerr << "Error creating ttf font" << std::endl;
        exit(1);
    }
}

SDL::~SDL(void) {
    TTF_CloseFont(_ttf);
    TTF_Quit();
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void    SDL::render(float x, float y, std::string str, bool display) {
    SDL_Surface *panel;
    SDL_Rect    rect = (SDL_Rect){x, y, 0, 0};;

    if (!display) return;
    panel = TTF_RenderText_Solid(_ttf, str.c_str(), (SDL_Color){0, 0, 0, 0});
    SDL_BlitSurface(panel, NULL, _screenSurface, &rect);
    SDL_FreeSurface(panel);
}

bool    SDL::processEvent(SDL_Event event) {
    if (SHOULD_CLOSE(event)) return true;
    else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_1)
        _datetime.setDisplay(!_datetime.getDisplay());
    else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_2)
        _os.setDisplay(!_os.getDisplay());
    else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_3)
        _host.setDisplay(!_host.getDisplay());
    else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_4)
        _cpu.setDisplay(!_cpu.getDisplay());
    else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_5)
        _ram.setDisplay(!_ram.getDisplay());
    else if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_6)
        _network.setDisplay(!_network.getDisplay());
    return false;
}

void    SDL::run(void) {
    SDL_Event   event;

    std::cout << "here: " << _network.getDisplay() << std::endl;
    _network.setDisplay(true);
    try {
        while (true) {
            while (SDL_PollEvent(&event)) {
                if (processEvent(event)) return;
                std::cout << event.key.keysym.scancode << std::endl;
            }
            SDL_FillRect(_screenSurface, NULL, 0xFFFFFF);
            render(10, 10, "(Press to hide) 1: Datetime 2: OS 3: Hostname 4: CPU 5: RAM 6: Network", true);
            render(10, 50, "Datetime: " + _datetime.data(), _datetime.getDisplay());
			render(10, 90, "Operating System: " + _os.data(), _os.getDisplay());
			render(10, 130, "Hostname: " + _host.data(), _host.getDisplay());
			render(10, 170, "CPU: " + _cpu.data(), _cpu.getDisplay());
			render(10, 210, "RAM: " + _ram.data(), _ram.getDisplay());
			render(10, 250, "Network: " + _network.data(), _network.getDisplay());
            SDL_UpdateWindowSurface(_window);
            SDL_Delay(500);
        }
    }
    catch(std::exception &exception) {}
}
