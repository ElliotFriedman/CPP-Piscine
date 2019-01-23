/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:17:14 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/22 18:31:57 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <limits>

Contact::Contact()
{
	this->firstName = "";
	this->lastName = "";
	this->nickname = "";
	this->login = "";
	this->postalAddress = "";
	this->emailAddress = "";
	this->phoneNumber = "";
	this->bDay = "";
	this->favoriteMeal = "";
	this->underwearColor = "";
	this->darkestSecret = "";
}

std::string		Contact::getFirst() const
{
	return this->firstName;
}


std::string		Contact::getLast() const
{
	return this->lastName;
}


std::string		Contact::getNick() const
{
	return this->nickname;
}

std::string		Contact::getAll()
{
	std::string	ret;

	ret = getFirst() + "\n";
	ret = ret + getLast() + "\n";
	ret = ret + getNick()+ "\n";
	ret = ret + this->login + "\n";
	ret = ret + this->postalAddress + "\n";
	ret = ret + this->emailAddress + "\n";
	ret = ret + this->phoneNumber + "\n";
	ret = ret + this->bDay + "\n";
	ret = ret + this->favoriteMeal + "\n";
	ret = ret + this->underwearColor + "\n";
	ret = ret + this->darkestSecret + "\n";
	return ret;
}

void			Contact::addUser()
{
	std::cout << "Enter your first name\n";
	std::getline(std::cin, this->firstName);
	std::cin.clear();
	std::cout << "Enter your last name\n";
	std::getline(std::cin,  this->lastName);
	std::cin.clear();
	std::cout << "Enter your nick name\n";
	std::cin.clear();
	std::getline(std::cin,  this->nickname);
	std::cin.clear();
	std::cout << "Enter your login\n";
	std::getline(std::cin,  this->login);
	std::cin.clear();
	std::cout << "Enter your first postal address\n";
	std::getline(std::cin,  this->postalAddress);
	std::cin.clear();
	std::cout << "Enter your email address\n";
	std::getline(std::cin,  this->emailAddress);
	std::cin.clear();
	std::cout << "Enter your phone number\n";
	std::getline(std::cin,  this->phoneNumber);
	std::cin.clear();
	std::cout << "Enter your birthday\n";
	std::getline(std::cin,  this->bDay);
	std::cin.clear();
	std::cout << "Enter your favorite meal\n";
	std::getline(std::cin,  this->favoriteMeal);
	std::cin.clear();
	std::cout << "Enter your underwear color\n";
	std::getline(std::cin,  this->underwearColor);
	std::cin.clear();
	std::cout << "Enter your darkest secret\n";
	std::getline(std::cin,  this->darkestSecret);
	std::cin.clear();
	std::cout << "Successfully created a person!" << std::endl;
}

