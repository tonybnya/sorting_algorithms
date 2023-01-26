#include "sort.h"

/**
 * insertion_sort_list - Insertion Sort Algorithm on a Doubly Linked List
 *
 * @list: Doubly Linked List to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *head;

	if (!list)
		return;

	head = *list;
	while (head)
	{
		while (head->next && (head->n > head->next->n))
		{
			node = head->next;
			head->next = node->next;
			node->prev = head->prev;

			if (head->prev)
				head->prev->next = node;

			if (node->next)
				node->next->prev = head;

			head->prev = node;
			node->next = head;

			if (node->prev)
				head = node->prev;
			else
				*list = node;

			print_list(*list);
		}
		head = head->next;
	}
}
