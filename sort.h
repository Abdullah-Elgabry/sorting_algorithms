#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#define DOWN 1
#define UP 0

/**
 * enum bool - val lmnb
 *
 * @false: means 0
 * @true: means 1
 *
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listing_s - doubly linked list node
 * @n: integer stored in the node.
 * @prev: pointer to the previous element of the list
 * @next: pointer to the next element of the list
 */
typedef struct listing_s
{
	const int n;
	struct listing_s *prev;
	struct listing_s *next;
} listing_t;

void print_array(const int *array, size_t size);
void print_list(const listing_t *list);

void bubble_sort(int *array, size_t size);
void insertion_sort_list(listing_t **list);
void selection_sort(int *array, size_t size);
void cocktail_sort_list(listing_t **list);
void quick_sort_hoare(int *array, size_t size);
void quick_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

#endif
