/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 00:03:55 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/29 22:55:03 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :  grade(copy.grade), name(copy.name)
{
	std::cout << "Copy Constructor Called\n";
}

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
	return "Created new GradeTooHighException Object\n";
}

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
	return "Created new GradeTooLowException Object\n";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& operate)
{
    os << operate.getName() << " bureaucrat grade, " << std::to_string(operate.grade) << '\n';
    return os;
}

const std::string	Bureaucrat::getName(void) const
{
	return name;
}

int					Bureaucrat::getGrade(void)
{
	return grade;
}

void				Bureaucrat::incrementGrade(void)
{
	try
	{
		if (grade + 1 > 150)
			throw GradeTooLowException();//GradeTooHighException::error();
	}
	catch (GradeTooLowException &tooHigh)
	{
		std::cout << tooHigh.what();
	}
	grade++;
}

void				Bureaucrat::decrementGrade(void)
{
	try
	{
		if (grade  - 1 < 1)
			throw GradeTooHighException();//GradeTooHighException::error();
	}
	catch (GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what();
	}
	grade--;
}


Bureaucrat::Bureaucrat(int _grade) : name("Bureaucrat mindless drone")
{
	try
	{
		if (_grade > 150)
			throw GradeTooLowException();
		if (_grade < 1)
			throw GradeTooHighException();//GradeTooHighException::error();
	}
	catch (GradeTooHighException &tooHigh)
	{
		std::cout << tooHigh.what();
	}
	catch (GradeTooLowException &tooLow)
	{
		std::cout << tooLow.what();
	}
	grade = _grade;
	std::cout << "Constructor Called\n";
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &copy)
{
	std::cout << "Called the overriden = operator Bureaucrat\n";
	grade = copy.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor Called\n";
}


