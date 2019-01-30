/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 00:03:55 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/30 00:50:47 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"
#include <cstdlib>
#include <iostream>

Form::Form(const Form &copy) :  isSigned(copy.isSigned), minimumGrade(copy.minimumGrade),  name(copy.name)
{
	std::cout << "Copy Constructor Called\n";
}

Form::Form(void) : isSigned(false), minimumGrade(50),  name("Default Form Name")
{
	std::cout << "Default Constructor Called\n";
}

Form::Form(int _threshHold): minimumGrade(_threshHold), name("Boring and generic form")
{
	if (_threshHold > 150)
		throw GradeTooLowException();
	if (_threshHold < 1)
		throw GradeTooHighException();
	isSigned = false;
	std::cout << "Form Constructor Called\n";
}

Form	&Form::operator=(Form const &copy)
{
	std::cout << "Called the overriden = operator on Form with name: " + copy.getName() + "\n";
	return *this;
}

Form::~Form()
{
	std::cout << "Destructor Called\n";
}

const char *Form::GradeTooHighException::what() const throw ()
{
	return "Created new GradeTooHighException Object\n";
}

const char *Form::GradeTooLowException::what() const throw ()
{
	return "Created new GradeTooLowException Object\n";
}

bool			Form::isFormSigned(void) const
{
	return isSigned;
}

std::ostream& operator<<(std::ostream& os, const Form& operate)
{
	std::string	print = "";
	if (operate.isFormSigned())
		print = " not";
	os << "Form is currently" << print << " signed\n";
	return os;
}

void		Form::signForm(Bureaucrat &signer)
{
	if (signer.getGrade() <= minimumGrade)
	{
		std::cout << signer.getName() + " signs " + name +  "\n";
		isSigned = true;
	}
	else if (signer.getGrade() > minimumGrade)
	{
		std::cout << signer.getName() + " was not able to sign " + name +  "  because his grade was too low\n";
	}
	else
	{
		std::cout << signer.getName() + " was not able to sign " + name +  "  because the form was already signed\n";
	}
}

const std::string	Form::getName(void) const
{
	return name;
}

int					Form::getMinimumGrade(void) const
{
	return minimumGrade;
}

void		Form::beSigned(Bureaucrat &signer)
{
	if (signer.getGrade() > minimumGrade)
		throw GradeTooLowException();
	else if (signer.getGrade() < 1)
		throw GradeTooHighException();
	else
		isSigned = true;
}



