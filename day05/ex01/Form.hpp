/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:40:05 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/30 00:31:35 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {

	private:
		bool				isSigned;
		const int			minimumGrade;
		const std::string	name;

	public:
		Form(const Form& copy);
		Form(int _grade);
		Form(void);
		~Form( void );
		Form &operator=(Form const &operate);
		friend std::ostream& operator<<(std::ostream& os, const Form& dt);
		const std::string	getName(void) const;
		int					getGrade(void);
		void				incrementGrade(void);
		void				decrementGrade(void);
		void				beSigned(Bureaucrat &signer);
		void				signForm(Bureaucrat &signer);
		int					getMinimumGrade(void) const;
		bool				isFormSigned(void) const;
		
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
