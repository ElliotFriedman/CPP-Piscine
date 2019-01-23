#include <string>
#include <iostream>

int main()
{
	std::string *pstr = new std::string("HI THIS IS BRAIN");
	std::string& ref = *pstr;
	std::cout << *pstr << std::endl;
	std::cout << ref << std::endl;
}
