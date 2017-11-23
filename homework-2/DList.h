#pragma once
#include <iostream>

template <typename T>
struct node
{
	T data;
	node<T> *prev;
	node<T> *next;
};

template <typename T>
class DList
{
	node<T> *start;
	node<T> *end;
	node<T> *current_s;
	node<T> *current_e;

	void delete_list();
	void copy_list(DList<T> const& other);
public:
	DList();
	DList(DList<T> const& other);
	DList& operator=(DList<T> const& other);
	~DList();

	void iter_start(node<T> *p = NULL);
	void iter_end(node<T> *p = NULL);

	node<T>* iter_next();
	node<T>* iter_prev();

	void insert_to_end(T const& x);
	void insert_before(node<T> *p, T const& x);
	void insert_after(node<T> *p, T const& x);
	void delete_element(node<T> *p, T  &x);
	void delete_before(node<T> *p, T &x);
	void delete_after(node<T> *p, T &x);

	void print();
	void print_reverse();
	int length();
};

template <typename T>
DList<T>::DList() : start(NULL), end(NULL) {}

template <typename T>
DList<T>::DList(DList<T> const& other)
{
	copy_list(other);
}

template <typename T>
DList<T>& DList<T>::operator=(DList<T> const& other)
{
	if (this != &other)
	{
		delete_list();
		copy_list(other);
	}
	return *this;
}

template <typename T>
DList<T>::~DList()
{
	delete_list();
}

template <typename T>
void DList<T>::delete_list()
{
	node<T> *p;
	while (start)
	{
		p = start;
		start = start->next;
		delete p;
	}
	start = NULL;
	end = NULL;
}

template <typename T>
void DList<T>::copy_list(DList<T> const& other)
{
	start = NULL;
	end = NULL;

	if (other.start)
	{
		node<T> *p = list.start;
		while (p)
		{
			insert_to_end(p->data);
			p = p->next;
		}
	}
}

template <typename T>
void DList<T>::iter_start(node<T> *p = NULL)
{
	if (p) current_s = p;
	else current_s = start;
}

template <typename T>
void DList<T>::iter_end(node<T> *p = NULL)
{
	if (p)  current_e = p;
	else current_e = end;
}

template <typename T>
node<T>* DList<T>::iter_next()
{
	node<T> *p = current_s;
	if(current_s) current_s = current_s->next;
	return p;
}

template <typename T>
node<T>* DList<T>::iter_prev()
{
	node<T> *p = current_e;
	if (current_e) current_e = current_e->prev;
	return p;
}

template <typename T>
void DList<T>::insert_to_end(T const& x)
{
	node<T> *p = end;
	end = new node<T>;
	end->data = x;
	end->next = NULL;

	if (p) p->next = end;
	else start = end;

	end->prev = p;
}

template <typename T>
void DList<T>::insert_after(node<T> *p, T const& x)
{
	node<T> *q = new node<T>;
	q->data = x;
	q->next = p->next;
	q->prev = p;

	if (p == end) end = q;

	p->next = q;
	q->next->prev = q;
}

template <typename T>
void DList<T>::insert_before(node<T> *p, T const& x)
{
	node<T> *q = new node<T>;
	*q = *p;

	if (p == end) end = q;
	
	p->data = x;
	p->next = q;
	q->prev = p;
}

template <typename T>
void DList<T>::delete_element(node<T> *p, T &x)
{
	x = p->data;
	if (p == start)
	{
		if (start == end)
		{
			start = NULL;
			end = NULL;
		}
		else
		{
			start = start->next;
			start->prev = NULL;
		}
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
void DList<T>::delete_after(node<T> *p, T &x)
{
	if (p->next)
	{
		node<T> *q = p->next;
		x = q->data;
		p->next = q->next;
		if (q == end) end = p;
		else q->next->prev = p;
		delete q;
	}
}

template <typename T>
void DList<T>::delete_before(node<T> *p, T &x)
{
	if (p != start)
	{
		node<T> *q = start;
		while (q->next != p) q = q->next;
		delete_element(q, x);
	}
}

template <typename T>
void DList<T>::print()
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
void DList<T>::print_reverse()
{
	node<T> *p = end;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->prev;
	}
	std::cout << "\n";
}

template <typename T>
int DList<T>::length()
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