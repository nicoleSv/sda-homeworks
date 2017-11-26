#include <iostream>
#include "LList.h"

template <typename T>
LList<T> merge_lists(node<T> *headA, node<T> *headB)
{
	LList<T> list;
	node<T> *p = headA;
	node<T> *q = headB;
	while (p || q)
	{
		if (p && q && p->data < q->data)
		{
			list.insert_to_end(p->data);
			p = p->next;
		}
		else if(p && q && p->data > q->data)
		{
			list.insert_to_end(q->data);
			q = q->next;
		}
		else if (p && (!q))
		{
			list.insert_to_end(p->data);
			p = p->next;
		}
		else if (q && (!p))
		{
			list.insert_to_end(q->data);
			q = q->next;
		}
	}
	return list;
}

int main()
{
	LList<int> list1;
	list1.insert_to_end(1);
	list1.insert_to_end(3);
	list1.insert_to_end(5);
	list1.insert_to_end(6);
	list1.print();

	LList<int> list2;
	list2.insert_to_end(2);
	list2.insert_to_end(4);
	list2.insert_to_end(7);
	list2.print();

	list1.iter_start();
	list2.iter_start();

	list1 = merge_lists(list1.iter(), list2.iter());
	
	list1.print();

	return 0;
}