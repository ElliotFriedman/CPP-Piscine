#include <stdio.h>

void	printbits(int num)
{
	int i = 31;

	while (-1 < i)
	{
		printf("%s ", (num >> i) & 1 ? "1" : "0");
		i--;
	}

	printf("\n");
}

int		twoRaisedN(int n)
{
	int i = 1;
	while (n)
	{
		i *= 2;
		n--;
	}
	return i;
}

int main()
{
	printbits(1);
	printbits(7);
	printbits(100);
	printbits(1000100101);

	printbits(1);
	printbits(3);
	printbits(7);
	printbits(15);
	printbits(31);
	printbits(63);
	printbits(127);
	
	int ctr = 0;
	int sum = 0;
	while (ctr < 32)
	{
		sum += twoRaisedN(ctr);
		printbits(sum);

		ctr++;
	}
}
