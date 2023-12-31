#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked
 *			list of integers in ascending order using
 *			the Insertion sort algorithm
 * @list: given list to sort
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;

	if (list == NULL || (*list)->next == NULL)
		return;

	head = *list;
	/* Traverses the list forward */
	while (head)
	{
		prev = head->prev;
		while (prev && (prev->n) > (head->n))
		{
			swap_var(prev, head, list);
			print_list(*list);
			prev = head->prev;
		}
		head = head->next;
	}
}

/**
  * swap_var - function that swaps two nodes in a doubly linked list
  * @node1: first node
  * @node2: second node
  * @head: list containing the nodes
  */

void swap_var(listint_t *node1, listint_t *node2, listint_t **head)
{
	listint_t *temp1, *temp2;

	if (!node1 || !node2)
		return;

	temp1 = node1->prev;
	temp2 = node2->next;

	if (temp1)
		temp1->next = node2;
	if (temp2)
		temp2->prev = node1;
	node1->next = temp2;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = temp1;
	if (!temp1)
		*head = node2;
}
