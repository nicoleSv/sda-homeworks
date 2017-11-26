#pragma once
#include <iostream>

template <typename T>
struct node
{
	T data;
	node<T>* next;
};

template <typename T>
class LList
{
	node<T> *start;
	node<T> *current;
	node<T> *end;

	void delete_list();
	void copy_list(LList<T> const &other);

public:
	LList();
	LList(LList<T> const &other);
	LList& operator=(LList<T> const &other);
	~LList();

	void iter_start(node<T> *p = NULL);
	node<T>* iter();

	void insert_to_end(T const &x);
	void insert_after(node<T> *p, T const &x);
	void insert_before(node<T> *p, T const &x);
	void delete_after(node<T> *p, T &x);
	void delete_before(node<T> *p, T &x);
	void delete_element(node<T> *p, T &x);

	void print();
	int length();
	void concat(LList<T> const &other);
};

template <typename T>
void LList<T>::delete_list()
{
	node<T> *p;
	while (start)
	{
		p = start;
		start = start->next;
		delete p;
	}
	end = NULL;
}

template <typename T>
void LList<T>::copy_list(LList<T> const &other)
{
	start = NULL;
	end = NULL;
	if (other.start)
	{
		node<T> *p = other.start;
		while (p)
		{
			insert_to_end(p->data);
			p = p->next;
		}
	}
}

template <typename T>
LList<T>::LList() : start(NULL), end(NULL) {}

template <typename T>
LList<T>::LList(LList<T> const &other)
{
	copy_list(other);
}

template <typename T>
LList<T>& LList<T>::operator=(LList<T> const &other)
{
	if (this != &other)
	{
		delete_list();
		copy_list(other);
	}
	return *this;
}

template <typename T>
LList<T>::~LList()
{
	delete_list();
}

template <typename T>
void LList<T>::iter_start(node<T> *p)
{
	if (p) current = p;
	else current = start;
}

template <typename T>
node<T>* LList<T>::iter()
{
	node<T> *p = current;
	if (current) current = current->next;
	return p;
}

template <typename T>
void LList<T>::insert_to_end(T const &x)
{
	current = end;
	end = new node<T>;
	end->data = x;
	end->next = NULL;

	if (current) current->next = end;
	else start = end;
}

template <typename T>
void LList<T>::insert_after(node<T> *p, T const &x)
{
	node<T> *q = new node<T>;
	q->data = x;
	q->next = p->next;

	if (p == end) end = q;

	p->next = q;
}

template <typename T>
void LList<T>::insert_before(node<T> *p, T const &x)
{
	node<T> *q = new node<T>;
	*q = *p;

	if (p == end) end = q;

	p->data = x;
	p->next = q;
}

template <typename T>
void LList<T>::delete_after(node<T> *p, T &x)
{
	if (p->next) {
		node<T> *q = p->next;
		x = q->data;
		p->next = q->next;

		if (q == end) end = p;
		delete q;
	}
}

template <typename T>
void LList<T>::delete_before(node<T> *p, T &x)
{
	if (p != start)
	{
		node<T> *q = start;
		while (q->next != p) q = q->next;
		delete_element(q, x);
	}
}

template <typename T>
void LList<T>::delete_element(node<T> *p, T &x)
{
	if (p == start)
	{
		x = p->data;
		if (start == end)
		{
			start = NULL;
			end = NULL;
		}
		else start = p->next;
		delete p;
	}
	else
	{
		node<T> *q = start;
		while (q->next != p) q = q->next;
		delete_after(q, x);
	}
}

template <typename T>
void LList<T>::print()
{
	node<T> *p = start;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << "\n";
}

template <typename T>
int LList<T>::length()
{
	int counter = 0;
	node<T> *p = start;
	while (p)
	{
		counter++;
		p = p->next;
	}
	return counter;
}

template <typename T>
void LList<T>::concat(LList<T> const &other)
{
	node<T> *p = list.start;
	while (p)
	{
		insert_to_end(p->data);
		p = p->next;
	}
}
