#include "../inc/OSInfo.hpp"

OSInfo::OSInfo(void): IMonitorModule() {}

OSInfo::OSInfo( OSInfo &obj) {}

OSInfo::~OSInfo(void){}

OSInfo& OSInfo::operator=(OSInfo &obj)
{
	return *this;
}

OSInfo::~OSInfo(void) {}

std::string OSInfo::data(void) {
    std::string os_data;
    char        buf[OS_BUFF];
    size_t      len = OS_BUFF;

    sysctlbyname(OS_TYPE, &buf, &len, NULL, 0);
    os_data.assign(buf);
    os_data.append(" ");
    sysctlbyname(OS_RELEASE, &buf, &len, NULL, 0);
    os_data.append(buf);
    return os_data;
}
