#include "../inc/DateTimeInfo.hpp"

DateTimeInfo::DateTimeInfo(void): IMonitorModule() {}

DateTimeInfo::~DateTimeInfo(void) {}

DateTimeInfo::DateTimeInfo( DateTimeInfo &obj) {}

DateTimeInfo& DateTimeInfo::operator=(DateTimeInfo &obj)
{
	return *this;
}

std::string DateTimeInfo::data(void)
{	
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	std::string print;

	print = std::to_string(now->tm_year + 1900) + "-";
	print += std::to_string(now->tm_mon + 1) + "-";
	print += std::to_string(now->tm_mday) + "-";
	print += std::to_string(now->tm_hour) + "-";
	print += std::to_string(now->tm_min) + "-";
	print += std::to_string(now->tm_sec);

	return print;
}

