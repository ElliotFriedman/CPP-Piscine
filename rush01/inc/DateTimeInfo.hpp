#ifndef DATETIME_HPP
#define DATETIME_HPP

#include "IMonitorModule.hpp"

#include <ctime>
#include <iostream>
#include <string>

class   DateTimeInfo: public IMonitorModule {
    public:
        DateTimeInfo(void);
        ~DateTimeInfo(void);
        std::string         data(void);
    private:
};

#endif
