#include <iostream>

int main()
{
	int vertices;
	std::cin >> vertices;

	int degree, sum = 0;
	for (int i = 0; i < vertices; i++)
	{
		std::cin >> degree;
		sum += degree;
	}

	if (sum == 2*(vertices - 1)) std::cout << "Yes\n";
	else std::cout << "No\n";

	return 0;
}