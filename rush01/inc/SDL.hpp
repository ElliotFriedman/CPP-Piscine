#ifndef SDL_HPP
#define SDL_HPP

#include "IMonitorDisplay.hpp"
#include "HostnameInfo.hpp"
#include "CPUInfo.hpp"
#include "DateTimeInfo.hpp"
#include "NetworkInfo.hpp"
#include "OSInfo.hpp"
#include "RAMInfo.hpp"
#include "../frameworks/SDL2.framework/Headers/SDL.h"
#include "../frameworks/SDL2_ttf.framework/Headers/SDL_ttf.h"
#include <iostream>

#define SHOULD_CLOSE(e) (e.window.event == SDL_WINDOWEVENT_CLOSE \
                        || (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_ESCAPE))

class   SDL: public IMonitorDisplay {
    public:
        SDL(HostnameInfo host
            , CPUInfo cpu
            , DateTimeInfo datetime
            , NetworkInfo network
            , OSInfo os
            , RAMInfo ram);
        ~SDL(void);
        void            run(void);
        void            render(float x, float y, std::string str, bool display);
        bool            processEvent(SDL_Event event);
    private:
        SDL_Window      *_window;
        SDL_Surface     *_screenSurface;
        HostnameInfo    _host;
        CPUInfo         _cpu;
        DateTimeInfo    _datetime;
        NetworkInfo     _network;
        OSInfo          _os;
        RAMInfo         _ram;
        TTF_Font        *_ttf;
};

#endif