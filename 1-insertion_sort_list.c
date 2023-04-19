#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm.
 *
 * @list: The list to be sorted
*/
void insertion_sort_list(listint_t **list)
{
	int swapped;
	listint_t *head;

	if (!list)
		return;

	head = *list;

	if (!head || !head->next)
		return;

	head = head->next;

	while (head)
	{
		swapped = 1;

		while (swapped && head->prev)
		{
			swapped = 0;

			if (head->n < head->prev->n)
			{
				swap(head, list);
				print_list(*list);
				swapped = 1;
			}
		}

		head = head->next;
	}
}

/**
 * swap - swap the current node with the prvious node.
 *
 * @head: current node to swap
 * @list: pointer to the head of the linked list
*/
void swap(listint_t *head, listint_t **list)
{
	listint_t *next, *prev, *tmp;

	tmp = head->prev;
	prev = tmp->prev;
	next = head->next;

	head->prev = prev;
	tmp->next = next;
	head->next = tmp;
	tmp->prev = head;

	if (prev)
		prev->next = head;
	else
		*list = head;

	if (next)
		next->prev = tmp;
}
