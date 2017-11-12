#include <iostream>
#include "Stack.h"

int main()
{
	Stack<int> Front;
	Stack<int> Back;

	int queries;
	std::cin >> queries;

	for (int i = 0; i < queries; i++)
	{
		int type_q;
		std::cin >> type_q;

		if (type_q == 1)
		{
			int x;
			std::cin >> x;
			Back.push(x);
		}
		else 
		{
			if (Front.empty())
			{
				while (!Back.empty())
				{
					Front.push(Back.top());
					Back.pop();
				}
			}
			if (!Front.empty())
			{
				(type_q == 2) && (Front.pop());
				(type_q == 3) && (std::cout << Front.top() << std::endl);
			}
		}
	}
	return 0;
}
