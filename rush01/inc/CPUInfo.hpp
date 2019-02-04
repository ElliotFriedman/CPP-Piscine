#ifndef CPUINFO_HPP
#define CPUINFO_HPP

#include "IMonitorModule.hpp"
#include <sstream>
#include <sys/types.h>
#include <mach/mach.h>
#include <sys/sysctl.h>
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>

#define CPU_BUFF 255
#define CPU_BRAND "machdep.cpu.brand_string"
#define CPU_CORES "machdep.cpu.core_count"
class   CPUInfo: public IMonitorModule {
    public:
        CPUInfo(void);
        ~CPUInfo(void);
        std::string                 cpuBrand(void);
        std::string                 cpuCores(void);
        std::string                 data(void);
        std::string                 data1(void);
		static float                calculateCPULoad(unsigned long long idleTicks
                                                    , unsigned long long totalTicks);
        static float                getCPULoad(void);
        static std::string          cpuLoad(void);
    private:
        static unsigned long long   _previousIdleTicks;
        static unsigned long long   _previousTotalTicks;

};

#endif
