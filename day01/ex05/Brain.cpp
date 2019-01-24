#include "Brain.hpp"
#include <string> 
#include <sstream>

Brain::Brain(void)
{
	std::stringstream tmpAddress;
	tmpAddress << std::hex << this;
	address = tmpAddress.str();
}

std::string		Brain::identify(void)
{
	return address;
}

