#pragma once
#include <iostream>

template <typename T>
struct node
{
	T data;
	node *next;
};

template <typename T>
class Stack
{
	node<T>* top_node;
	void copy(node<T>* to_copy);
	void copy_stack(Stack const& other);
	void erase_stack();
public:
	Stack();
	Stack(Stack const& other);
	Stack& operator=(Stack const& other);
	~Stack();

	bool empty() const;
	void push(T const& x);
	T pop();
	T top() const;

	void print() const;
};

template <typename T>
Stack<T>::Stack() : top_node(nullptr) {}

template <typename T>
bool Stack<T>::empty() const
{
	if (top_node == nullptr) return true;
	else return false;
}

template <typename T>
void Stack<T>::push(T const& x)
{
	node<T>* p = new node<T>;
	p->data = x;
	p->next = top_node;
	top_node = p;
}

template <typename T>
T Stack<T>::pop()
{
	if (empty()) return -1;
	T x = top_node->data;
	top_node = top_node->next;
	return x;
}

template <typename T>
T Stack<T>::top() const
{
	if (empty()) return -1;
	else return top_node->data;
}

template <typename T>
void Stack<T>::copy(node<T>* to_copy)
{
	if (to_copy == nullptr)
		return;
	copy(to_copy->next);
	push(to_copy->data);
}

template <typename T>
void Stack<T>::copy_stack(Stack<T> const& other)
{
	top_node = nullptr;
	copy(other.top_node);
}

template <typename T>
void Stack<T>::erase_stack()
{
	while (empty() == false) pop();
}

template <typename T>
Stack<T>::Stack(Stack const& other)
{
	copy_stack(other);
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack const& other)
{
	if (this != &other)
	{
		erase_stack();
		copy(other);
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack() {
	erase_stack();
}

template <typename T>
void Stack<T>::print() const
{
	node<T>* p = top_node;
	while (p)
	{
		std::cout << p->data << " ";
		p = p->next;
	}
	std::cout << "\n";
}