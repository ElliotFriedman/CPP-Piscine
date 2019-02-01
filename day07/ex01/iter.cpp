/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:41:59 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/31 20:55:18 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T>
void 		iter(T *x, int & y, void (*f)(T &operate)
{
	for (int i = 0; i < y; i++)
	{
		operate(x[i]);
	}
}

template< typename T>
void	print(T &x)
{
	std::cout << x << std::endl;
}

int main( void )
{
	int a[2] = { 2, 3};
	int b = 2;

	::iter( a, b , print);
	::iter( a, b , print);


	::iter( a, b , print);
	::iter( a, b , print);
	
	char arr[3] = {'a', 'b', 'c'};
	b = 3;

	::iter( arr, b , print);	
	::iter( arr, b , print);
	::iter( arr, b , print);

	return 0;
}
