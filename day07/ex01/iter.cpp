/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efriedma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 11:41:59 by efriedma          #+#    #+#             */
/*   Updated: 2019/01/31 13:12:34 by efriedma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template< typename T, typename FX>
void 		iter(T *x, int & y, FX operate )
{
	for (int i = 0; i < y; i++)
	{
		operate(x[i]);
	}
}

void	addInt(int &x)
{
	x++;
}

void	addChar(char &x)
{
	x++;
}

void	charPrint(char toPrint)
{
	std::cout << toPrint << std::endl;
}

void	print(int toPrint)
{
	std::cout << toPrint << std::endl;
}

int main( void )
{
	int a[2] = { 2, 3};
	int b = 2;

	::iter( a, b , addInt);
	::iter( a, b , print);


	::iter( a, b , addInt);
	::iter( a, b , print);
	
	char arr[3] = {'a', 'b', 'c'};
	b = 3;

	::iter( arr, b , charPrint);	
	::iter( arr, b , addChar);
	::iter( arr, b , charPrint);
	


	/*
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
*/
	return 0;
}
