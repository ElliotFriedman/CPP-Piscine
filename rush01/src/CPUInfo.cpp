#include "../inc/CPUInfo.hpp"

unsigned long long  CPUInfo::_previousIdleTicks = 0;
unsigned long long  CPUInfo::_previousTotalTicks = 0;

CPUInfo::CPUInfo(void): IMonitorModule() {}

CPUInfo::~CPUInfo(void) {}

/*
** https://stackoverflow.com/questions/8736713/retrieve-system-information-on-macos-x
*/

/*
** Returns 1.0f for "CPU fully pinned", 0.0f for "CPU idle", or somewhere in between
** You'll need to call this at regular intervals, since it measures the load between
** the previous call and the current one.
*/

float       CPUInfo::calculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
  unsigned long long totalTicksSinceLastTime = totalTicks - _previousTotalTicks;
  unsigned long long idleTicksSinceLastTime  = idleTicks - _previousIdleTicks;
  float ret = 1.0f-((totalTicksSinceLastTime > 0) ? ((float)idleTicksSinceLastTime)/totalTicksSinceLastTime : 0);
  _previousTotalTicks = totalTicks;
  _previousIdleTicks  = idleTicks;
  return ret;
}

float       CPUInfo::getCPULoad(void)
{
   unsigned long long           totalTicks = 0;
   host_cpu_load_info_data_t    cpuinfo;
   mach_msg_type_number_t       count = HOST_CPU_LOAD_INFO_COUNT;
   kern_return_t                stats;

    stats = host_statistics(mach_host_self()
                        , HOST_CPU_LOAD_INFO
                        , (host_info_t)&cpuinfo, &count);
    if (stats != KERN_SUCCESS)
        return -1.0f;
    for(int i = 0; i < CPU_STATE_MAX; i++)
        totalTicks += cpuinfo.cpu_ticks[i];
    return CPUInfo::calculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks) * 100;
}

std::string CPUInfo::cpuBrand(void) {
    char                buf[CPU_BUFF] = {0};
    size_t              len = CPU_BUFF;

    sysctlbyname(CPU_BRAND, buf, &len, NULL, 0);
    return std::string(buf);
}

std::string CPUInfo::cpuCores(void) {
    int                 cores;
    size_t              len = CPU_BUFF;

    sysctlbyname(CPU_CORES, &cores, &len, NULL, 0);
    return std::to_string(cores);
}

std::string CPUInfo::cpuLoad(void) {
    std::ostringstream  load;

    load << CPUInfo::getCPULoad();
    return load.str();
}

std::string CPUInfo::data(void) {
    return std::string(CPUInfo::cpuBrand());
}


std::string CPUInfo::data1(void) {
	return (CPUInfo::cpuCores()
                        + " cores, "
						+ "load = "
                        + CPUInfo::cpuLoad()
						+ "%");
}

