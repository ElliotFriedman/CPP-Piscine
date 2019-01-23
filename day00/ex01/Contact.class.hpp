/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 20:51:06 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/22 18:31:44 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

#include <string>
#include <iostream>

class Contact {

	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string login;
		std::string postalAddress;
		std::string emailAddress;
		std::string phoneNumber;
		std::string bDay;
		std::string favoriteMeal;
		std::string underwearColor;
		std::string darkestSecret;

	public:
		Contact(void);
		std::string		getFirst(void) const;
		std::string		getLast(void) const;
		std::string		getNick(void) const;
		std::string		getAll(void);
		void			addUser(void);
};


#endif
