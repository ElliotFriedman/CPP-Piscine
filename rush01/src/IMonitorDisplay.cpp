#include "../inc/IMonitorDisplay.hpp"

IMonitorDisplay::IMonitorDisplay( IMonitorDisplay &obj) :  _previousIdleTicks(0), _previousTotalTicks(0) {}

IMonitorDisplay::IMonitorDisplay(void){}

IMonitorDisplay::~IMonitorDisplay(void){}

IMonitorDisplay& IMonitorDisplay::operator=(IMonitorDisplay &obj)
{
	return *this;
}

IMonitorDisplay::IMonitorDisplay(void)
{

IMonitorDisplay::~IMonitorDisplay(void) {}
