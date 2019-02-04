#include "../inc/IMonitorModule.hpp"

IMonitorModule::IMonitorModule(void)
{
	display = true;
}

IMonitorModule::~IMonitorModule(void) {}

bool			IMonitorModule::displayModule(void)
{
	return display;
}

void			IMonitorModule::setDisplay(bool set)
{
	display = set;
}

int				IMonitorModule::getOffset(void)
{
	return offset;
}

bool			IMonitorModule::getDisplay(void)
{
	return display;
}
