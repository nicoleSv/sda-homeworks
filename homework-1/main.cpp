#include <iostream>
#define MAX 1000

int calculated[MAX] = { 0 };
int calc[MAX] = { 0 };

long fib1(int n) //O(2^n)
{
	if (n <= 1) return 1; //if we want the sequence to start with 0, return n
	else return fib1(n - 1) + fib1(n - 2);
}

long fib_n(int n) //O(n) with dynamic programming
{
	if (n <= 1) calculated[n] = 1; //if we want the sequence to start with 0, calculated[n] = n
	else if(calculated[n] == 0) calculated[n] = fib_n(n - 1) + fib_n(n - 2);
	return calculated[n];
}

long fib_logn(int n) //O(logn) with formula for odd and even numbers
{
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (calc[n] = 1);

	int k = (n % 2) ? (n + 1) / 2 : n / 2;

	if (n % 2) calc[n] = fib_logn(k)*fib_logn(k) + fib_logn(k - 1)*fib_logn(k - 1);
	else calc[n] = (2 * fib_logn(k - 1) + fib_logn(k))*fib_logn(k);

	return calc[n];
}


int main()
{
	int n;
	std::cin >> n;
//	unsigned long fib = fib1(n);
//	std::cout << fib << std::endl;

	long test = 0;
	for (int i = 0; i <= n; i++)
	{
		test = fib_logn(i);
		std::cout << test << std::endl;
	}

	return 0;
}