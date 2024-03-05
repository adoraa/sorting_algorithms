#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using Insertion sort
 * @list: pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *temp;

	for (cur = (*list)->next; cur; cur = cur->next)
	{
		temp = cur;
		while (temp->prev && temp->n < temp->prev->n)
		{
			if (temp->next)
				temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			temp->next->prev = temp;
			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;
			print_list(*list);
		}
	}
}
