#include "../inc/IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay( IMonitorDisplay &obj) {}

IMonitorDisplay::IMonitorDisplay(void){}

IMonitorDisplay::~IMonitorDisplay(void){}

IMonitorDisplay& IMonitorDisplay::operator=(IMonitorDisplay &obj)
{
	return *this;
}
