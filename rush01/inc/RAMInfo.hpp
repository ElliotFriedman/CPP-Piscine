#ifndef RAMINFO_HPP
#define RAMINFO_HPP

#include "IMonitorModule.hpp"
#include <unistd.h>

class   RAMInfo: public IMonitorModule {
    public:
        RAMInfo(void);
        ~RAMInfo(void);
		std::string		memUsage(void);
		std::string         data(void);
};

#endif
