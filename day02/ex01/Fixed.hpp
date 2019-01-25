/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:40:41 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/24 22:15:29 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					_fixedVal;
		static const int	_fractionBits = 8;

	public:
		Fixed();
		Fixed(const int val);						//canononical
		Fixed(const float val);
		Fixed(Fixed &cpy);							//canononical
		~Fixed();									//canononical
		Fixed& operator=(const Fixed& instance);	//canononical

		int		getRawBits(void);
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

#endif
