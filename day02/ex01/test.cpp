#include <iostream>

int		getPow(int n)
{
	int i = 1;
	while (n)
	{
		i *= 2;
		n--;
	}
	return i;
}

float	getNegExp(int n)
{
	float i = 1;
	return i / getPow(n * -1);
}

int main()
{
	std::cout << getNegExp(-1) << "\n";
	std::cout << getNegExp(-2) << "\n";
	std::cout << getNegExp(-3) << "\n";
	std::cout << getNegExp(-4) << "\n";
}
