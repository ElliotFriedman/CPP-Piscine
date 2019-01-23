#include <iostream>
#include <cstdlib>

void memoryLeak()
{
	std::string*        panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
	
	//c++ version of free
	//delete panthere;
	
	//or just do it like c
	std::free(panthere);
}


int main()
{
	memoryLeak();
	while (1);
}

