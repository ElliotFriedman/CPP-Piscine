#include "../inc/HostnameInfo.hpp"

HostnameInfo::HostnameInfo(void): IMonitorModule() {}

HostnameInfo::~HostnameInfo(void) {}

std::string HostnameInfo::data(void) {
    char    name[HOSTNAME_BUFF] = {0};

    gethostname(name, HOSTNAME_BUFF);
    return std::string(name);
}
