#include <iostream>
#include <fstream>
#include"Graph.h"

using namespace std;

int main()
{
	IntGraph graph;
	ifstream file;
	file.open("input.txt");
	int a, b;

	while (file)
	{
		file >> a;
		file >> b;
		if (!isTop(a, graph)) AddTop(a, graph);
		if (!isTop(b, graph)) AddTop(b, graph);
		AddRib(a, b, graph);
	}

	if (IsTree(graph)) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
