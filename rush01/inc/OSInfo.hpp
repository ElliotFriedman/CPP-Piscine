#ifndef OSINFO_HPP
#define OSINFO_HPP

#include "IMonitorModule.hpp"
#include <sys/sysctl.h>

#define OS_BUFF 255
#define OS_TYPE "kern.ostype"
#define OS_RELEASE "kern.osrelease"

class   OSInfo: public IMonitorModule {
    public:
        OSInfo(void);
        ~OSInfo(void);
        std::string         data(void);
    private:
};

#endif