#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a(1);
	std::cout << a;
	a.incrementGrade();
	std::cout << a;

	for (int i = 0; i < 120; i++)
	{
		a.incrementGrade();
		std::cout << a;
	}

	Bureaucrat c(12);

	Bureaucrat d(120);

	std::cout << "Time for some errors\n";
	Bureaucrat b(-1);
	Bureaucrat e(1200);
	Bureaucrat f(-1777);

	f.incrementGrade();
	f.decrementGrade();
	std::cout << f;
}
