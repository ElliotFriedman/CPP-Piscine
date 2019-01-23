/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:43:15 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/22 21:20:34 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PONY_H
# define PONY_H

class Pony {

	public:
		bool isReal;
		bool childhoodDestroyed;

		void ponyOnTheHeap(void);
		void ponyOnTheStack(void);
		Pony(void);
		~Pony(void);
};

#endif
