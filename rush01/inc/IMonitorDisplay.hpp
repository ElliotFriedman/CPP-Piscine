#ifndef IMONITORDISPLAY_HPP
#define IMONITORDISPLAY_HPP

#include "IMonitorModule.hpp"

class   IMonitorDisplay {
    public:
        IMonitorDisplay(void);
        ~IMonitorDisplay(void);
        IMonitorDisplay( IMonitorDisplay &obj);
        IMonitorDisplay& operator=(IMonitorDisplay &obj);
    private:
};

#endif