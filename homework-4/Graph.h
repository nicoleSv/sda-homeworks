#pragma once
#include <iostream>
#include"LList.h"

typedef LList<int> IntList;
typedef LList<IntList> IntGraph;

node<int>* Point(int a, IntGraph &g)
{
	g.iter_start();
	node<IntList>* p;
	node<int>* q;
	do
	{
		p = g.iter();
		p->data.iter_start();
		q = p->data.iter();
	} while (q->data != a);
	return q;
}

void AddTop(int a, IntGraph &g)
{
	IntList l;
	l.insert_to_end(a);
	g.insert_to_end(l);
}

void AddRib(int a, int b, IntGraph &g)
{
	node<int>* q = Point(a, g);
	node<int>* p;

	while (q->next) q = q->next;
	p = new node<int>;
	p->data = b;
	p->next = nullptr;
	q->next = p;
}

void CreateGraph(IntGraph &g)
{
	char c;
	do
	{
		std::cout << "top of graph: ";
		int x;
		std::cin >> x;
		AddTop(x, g);
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
		AddRib(x, y, g);
		std::cout << "next: y/n? ";
		std::cin >> c;
	} while (c == 'y');
}

void LList<IntList>::print()
{
	iter_start();
	node<IntList> *p = iter();
	while (p)
	{
		p->data.print();
		p = p->next;
	}
	std::cout << std::endl;
}

void DeleteLast(IntList &l)
{
	l.iter_start();
	int x;
	node<int> *p = l.iter();
	while (p->next) p = l.iter();
	l.delete_element(p, x);
}

void dfs(IntGraph &g, int i, IntList &visited)
{
	visited.insert_to_end(i);
	std::cout << i << ' ';
	
	node<int>* q = Point(i, g);
	q = q->next;
	while (q)
	{
		if (!visited.member(q->data)) dfs(g, q->data, visited);
		q = q->next;
	}
	DeleteLast(visited);
}

bool IsTree(IntGraph &g)
{
	int sum = 0, vertices = 0;
	g.iter_start();
	node<IntList>* p = g.iter();
	node<int>* q;
	do
	{
		p->data.iter_start();
		q = new node<int>;
		q = p->data.iter();
		sum += q->data;
		p = g.iter();
		vertices++;
	} while (p);
	if (vertices == sum - 1) return true;
	return false;
}

bool isTop(int a, IntGraph &g)
{
	g.iter_start();
	node<IntList>* p = g.iter();
	node<int>* q;
	while (p)
	{
		p->data.iter_start();
		q = new node<int>;
		q = p->data.iter();
		if (q->data == a) return true;
		p = g.iter();
	}
	return false;
}