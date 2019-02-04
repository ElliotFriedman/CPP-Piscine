#include "../inc/IMonitorModule.hpp"

IMonitorModule::IMonitorModule( IMonitorModule &obj){}

IMonitorModule::~IMonitorModule(void){}

IMonitorModule& IMonitorModule::operator=(IMonitorModule &obj)
{
	return *this;
}


IMonitorModule::IMonitorModule(void)
{
	display = true;
}

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
