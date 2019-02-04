#include "../inc/RAMInfo.hpp"

RAMInfo::RAMInfo( RAMInfo &obj) {}

RAMInfo::~RAMInfo(void){}

RAMInfo& RAMInfo::operator=(RAMInfo &obj)
{
	return *this;
}

RAMInfo::RAMInfo(void): IMonitorModule() {}

RAMInfo::~RAMInfo(void) {}

static double ParseMemValue(const char * b)
{
	while((*b)&&(isdigit(*b) == false)) b++;
	return isdigit(*b) ? atof(b) : -1.0;
}

float GetSystemMemoryUsagePercentage()
{
	FILE * fpIn = popen("/usr/bin/vm_stat", "r");
	if (fpIn)
	{
		double pagesUsed = 0.0, totalPages = 0.0;
		char buf[512];
		while(fgets(buf, sizeof(buf), fpIn) != NULL)
		{
			if (strncmp(buf, "Pages", 5) == 0)
			{
				double val = ParseMemValue(buf);
				if (val >= 0.0)
				{
					if ((strncmp(buf, "Pages wired", 11) == 0)||(strncmp(buf, "Pages active", 12) == 0)) pagesUsed += val;
					totalPages += val;
				}
			}
			else if (strncmp(buf, "Mach Virtual Memory Statistics", 30) != 0)
				break;
		}
		pclose(fpIn);

		if (totalPages > 0.0) return (float) (pagesUsed/totalPages);
	}
	return -1.0f;  // indicate failure
}
std::string RAMInfo::data(void) {
	return "Total RAM Bytes: " + std::to_string(sysconf(_SC_PAGESIZE) * sysconf(_SC_PHYS_PAGES));
}

std::string RAMInfo::memUsage(void) {
	return "RAM usage " + std::to_string((GetSystemMemoryUsagePercentage() * 100)) + "%";
}
