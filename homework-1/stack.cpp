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
	T max();
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
	std::cout << std::endl;
}

template <typename T>
T Stack<T>::max()
{
	node<T>* p = top_node;
	T max_el = 0;
	while (p)
	{
		if (p->data > max_el) max_el = p->data;
		p = p->next;
	}
	return max_el;
}

//game of two stacks
template <typename T>
int game(Stack<T> A, Stack<T> B, int x)
{
	int sum = 0, score = 0;
	while (sum <= x)
	{
		if (!A.empty() && !B.empty())
			(A.top() <= B.top()) ? sum += A.pop() : sum += B.pop();
		else
		{
			if (A.empty()) sum += B.pop();
			if (B.empty()) sum += A.pop();
		}
		score++;
	}
	return score - 1;
}


int main()
{
/*	 //MAXIMUM ELEMENT
	Stack<int> numbers;

	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		int query;
		std::cin >> query;

		if (query == 1)
		{
			int x;
			std::cin >> x;
			numbers.push(x);
		}

		if (query == 2) numbers.pop();

		if (query == 3) std::cout << "\n" << numbers.max() << std::endl;	
	} */

	//GAME OF TWO STACKS
	int g;
	std::cin >> g;
	for (int a0 = 0; a0 < g; a0++) {
		int n, m, x;
		
		std::cin >> n >> m >> x;
		int* array_a = new int[n];
		int* array_b = new int[m];
		
		for (int i = 0; i < n; i++) {
			std::cin >> array_a[i];
		}
		
		for (int i = 0; i < m; i++) {
			std::cin >> array_b[i];
		}
		Stack<int> A;
		Stack<int> B;
		for (int i = n-1; i >= 0; i--) {
			A.push(array_a[i]);
		}

		for (int i = m; i >= 0; i--) {
			B.push(array_b[i]);
		}

		std::cout << game(A, B, x) << std::endl;
	}

	return 0;
}
