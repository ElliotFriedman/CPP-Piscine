/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/29 22:46:51 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat {

	int grade;
	const std::string name;
	
	public:
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat(int _grade);
	~Bureaucrat( void );
	Bureaucrat &operator=(Bureaucrat const &operate);
//	void 				operator<<(Bureaucrat const &operate);
	friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& dt);
	const std::string	getName(void) const;
	int					getGrade(void);
	void				incrementGrade(void);
	void				decrementGrade(void);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what(void) const throw();
	};

};

#endif
