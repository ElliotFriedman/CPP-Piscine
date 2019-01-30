#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	try {
		Bureaucrat b(-1);
	}	
	catch (Bureaucrat::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what();
	}
	catch (Bureaucrat::GradeTooLowException &tooLow)
	{
		std::cout << tooLow.what();
	}


	try {
		Bureaucrat e(1200);
	}
	catch (Bureaucrat::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what();
	}
	catch (Bureaucrat::GradeTooLowException &tooLow)
	{
		std::cout << tooLow.what();
	}
	try {
		Bureaucrat f(-1777);
	}
	catch (Bureaucrat::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what();
	}
	catch (Bureaucrat::GradeTooLowException &tooLow)
	{
		std::cout << tooLow.what();
	}

	std::cout << "\n\nHere\n\n\n";


	Form generic(120);
	try {
		generic.signForm(d);	
	}
	catch (Form::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what();
	}
	catch (Form::GradeTooLowException &tooLow)
	{
		std::cout << tooLow.what();
	}
	std::cout << "\n\nGeneric\n\n\n";


std::cout << generic;

	try {
		generic.beSigned(c);
	}
	catch (Form::GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what();
	}
	catch (Form::GradeTooLowException &tooLow)
	{
		std::cout << tooLow.what();
	}


}
