#include <iostream>
#include "DList.h"

template <typename T>
DList<T> reverse(node<T> *head)
{
	DList<T> new_list;
	node<T> *temp = head;
	while (temp->next) temp = temp->next;
	while (temp)
	{
		new_list.insert_to_end(temp->data);
		temp = temp->prev;
	}
	return new_list;
}

int main()
{
	DList<int> list;
	list.insert_to_end(1);
	list.insert_to_end(2);
	list.insert_to_end(3);
	list.insert_to_end(4);
	list.print(); // 1 2 3 4
	
	list.iter_start();
	list = reverse(list.iter_next());
	list.print(); // 4 3 2 1

	return 0;
}
