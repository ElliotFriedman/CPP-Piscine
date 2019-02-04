#include "../inc/HostnameInfo.hpp"

HostnameInfo::HostnameInfo(void): IMonitorModule() {}

HostnameInfo::~HostnameInfo(void) {}
HostnameInfo::HostnameInfo( HostnameInfo &obj) {}

HostnameInfo::HostnameInfo(void){}

HostnameInfo::~HostnameInfo(void){}

HostnameInfo& HostnameInfo::operator=(HostnameInfo &obj)
{
	return *this;
}

std::string HostnameInfo::data(void) {
    char    name[HOSTNAME_BUFF] = {0};

    gethostname(name, HOSTNAME_BUFF);
    return std::string(name);
}
