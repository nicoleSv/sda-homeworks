#include <iostream>
#include"Graph.h"

using namespace std;

int number_of_vertices(IntGraph &g)
{
	g.iter_start();
	node<IntList>* p = g.iter();
	int vertices = 0;
	while (p)
	{
		vertices++;
		p = g.iter();
	}
	return vertices;
}

int main()
{
	int test_cases;
	cin >> test_cases;

	for (int i = 0; i < test_cases; i++)
	{
		IntGraph graph;

		int roads_number;
		cin >> roads_number;

		for (int j = 0; j < roads_number; j++)
		{
			int city_x, city_y;
			cin >> city_x >> city_y;

			if (!isTop(city_x, graph)) AddTop(city_x, graph);
			if (!isTop(city_y, graph)) AddTop(city_y, graph);
			AddRib(city_x, city_y, graph);
		}
		cout << number_of_vertices(graph) << endl;
	}

	return 0;
}
