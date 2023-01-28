#include "sort.h"

void swap(listint_t *node1, listint_t *node2);

/**
 * cocktail_sort_list - Cocktail Shaker Sort Algorithm on a DLL
 *
 * @list: Doubly Linked List (DLL) to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
        listint_t *node;
        int swapped;

        if (list == NULL || *list == NULL)
                return;

        node = *list;

        do
        {
                swapped = 0;
                while (node->next != NULL)
                {
                        if (node->n >node->next->n)
                        {
                                swap(node, node->next);
                                print_list(*list);
                                swapped = 1;
                        }
                        node = node->next;
                }
                if (!swapped)
                        break;

                swapped = 0;
                node = node->prev;
                while (node->prev != NULL)
                {
                        if (node->n < node->prev->n)
                        {
                                swap(node->prev, node);
                                swapped = 1;
                        }
                        node = node->prev;
                }
        }
        while (swapped);
}

void swap(listint_t *node1, listint_t *node2)
{
        listint_t *prev1, *next1, *prev2, *next2;

        prev1 = node1->prev;
        next1 = node1->next;
        prev2 = node2->prev;
        next2 = node2->next;

        if (prev1 != NULL)
                prev1->next = node2;
        if (next1 != NULL)
                next1->prev = node2;
        if (prev2 != NULL)
                prev2->next = node1;
        if (next2 != NULL)
                next2->prev = node1;

        node1->prev = prev2;
        node1->next = next2;
        node2->prev = prev1;
        node2->next = next1;
}
