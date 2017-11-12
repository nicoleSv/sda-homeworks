#pragma once
#include <iostream>

template <typename T>
struct node
{
	T data;
	node* next;
};

template <typename T>
class Queue
{
	node<T>* front;
	node<T>* back;
	void copy(Queue const& other);
	void erase_queue();
public:
	Queue();
	Queue(Queue const& other);
	Queue& operator=(Queue const& other);
	~Queue();

	bool empty() const;
	void push(T const& x);
	T pop();
	T head() const;

	void print();
};

template <typename T>
Queue<T>::Queue() : front(nullptr), back(nullptr) {}

template <typename T>
bool Queue<T>::empty() const
{
	if (front == nullptr && back == nullptr) return 1;
	else return 0;
}

template <typename T>
void Queue<T>::push(T const& x)
{
	node<T>* p = new node<T>;
	p->data = x;
	p->next = NULL;
	if (empty()) front = p;
	else back->next = p;
	back = p;
}

template <typename T>
T Queue<T>::pop()
{
	if (empty()) return -1;
	node<T>* p = front;
	T x = p->data;
	if (p == back)
	{
		front = NULL;
		back = NULL;
	}
	else front = p->next;
	delete p;
	return x;
}

template <typename T>
T Queue<T>::head() const
{
	if (empty())
	{
		std::cerr << "Empty queue!\n";
		return -1;
	}
	return front->data;
}

template <typename T>
void Queue<T>::copy(Queue<T> const& other)
{
	back = NULL;
	if (!other.empty())
	{
		node<T>* p = other.front;
		while (p)
		{
			push(p->data);
			p = p->next;
		}
	}
}

template <typename T>
void Queue<T>::erase_queue()
{
	while (!empty()) pop();
}

template <typename T>
Queue<T>::Queue(Queue<T> const& other)
{
	front = nullptr;
	back = nullptr;
	copy(other);
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T> const& other)
{
	if (this != &other)
	{
		erase_queue();
		copy(other);
	}
	return *this;
}

template <typename T>
Queue<T>::~Queue()
{
	erase_queue();
}

template <typename T>
void Queue<T>::print()
{
	node<T>* p = front;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << "\n";
}