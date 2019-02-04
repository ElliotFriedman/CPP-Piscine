#ifndef HOSTNAME_HPP
#define HOSTNAME_HPP

#include "IMonitorModule.hpp"
#include <unistd.h>
#define HOSTNAME_BUFF 20

class   HostnameInfo: public IMonitorModule {
    public:
        HostnameInfo(void);
        ~HostnameInfo(void);
        std::string         data(void);
    private:
};

#endif