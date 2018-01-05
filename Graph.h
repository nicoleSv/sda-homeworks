#pragma once
#include <iostream>
#include"LList.h"
typedef LList<int> IntList;
typedef LList<IntList> IntGraph;

class Graph
{
//	IntList points;
	IntGraph graph;
public:
	node<int>* Point(int a);
	void AddTop(int a);
	void AddRib(int a, int b);
	void create_graph();
	void print();
};


node<int>* Graph::Point(int a)
{
	graph.iter_start();
	node<IntList>* p;
	node<int>* q;

	do
	{
		p = graph.iter();
		p->data.iter_start();
		q = p->data.iter();
	} while (q->data != a);

	return q;
}

void Graph::AddTop(int a)
{
	IntList list;
	list.insert_to_end(a);
	graph.insert_to_end(list);
}

void Graph::AddRib(int a, int b)
{
	node<int>* q = Point(a);
	node<int>* p;

	while (q->next) q = q->next;
	p = new node<int>;
	p->data = b;
	p->next = NULL;
	q->next = p;
}

void Graph::create_graph()
{
	char c;
	do
	{
		std::cout << "top of graph: ";
		int x;
		std::cin >> x;
		AddTop(x);
		std::cout << "Top y/n? ";
		std::cin >> c;
	} while (c == 'y');

	std::cout << "Ribs:\n";
	do
	{
		std::cout << "start top: ";
		int x;
		std::cin >> x;
		std::cout << "end top: ";
		int y;
		std::cin >> y;
		AddRib(x, y);
		std::cout << "next: y/n? ";
		std::cin >> c;
	} while (c == 'y');
}

void Graph::print()
{
	graph.iter_start();
	node<IntList>* p = graph.iter();
	while (p)
	{
		p->data.print();
		p = p->next;
	}
	std::cout << std::endl;
}