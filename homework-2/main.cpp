#include <iostream>
#include "LList.h"

template <typename T>
node<T>* remove_duplicates(node<T>* head)
{
	if (!(head || head->next)) return head;

	node<T> *p = head;
	node<T> *q = head->next;
	while (q)
	{
		if (p->data == q->data)
		{
			node<T> *temp = q;
			p->next = q->next;
			p = p->next;
			q = p->next;
			delete temp;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
	return head;
}

int main()
{
	LList<int> list;
	list.insert_to_end(1);
	list.insert_to_end(1);
	list.insert_to_end(3);
	list.insert_to_end(3);
	list.insert_to_end(5);
	list.insert_to_end(6);
	list.print();

	list.iter_start();
	node<int> *new_start = remove_duplicates(list.iter());
	list.print();

	return 0;
}