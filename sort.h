#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO 0

/**
 * enum bool - val lmnb
 *
 * @true: means 1
 * @false: means 0
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
void swap_ints(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t start, size_t mec, char ph);
void bitonic_seq(int *array, size_t size, size_t start, size_t mec, char ph);
void swaper(listing_t **h, listing_t **n1, listing_t *xlv);
void insertion_sort_list(listing_t **list);
void bitonic_sort(int *array, size_t size);
void swaper(listing_t **h, listing_t **n1, listing_t *xlv);
void quick_sort_hoare(int *array, size_t size);
void quick_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
int get_max(int *array, int size);
void radix_counting_sort(int *array, size_t size, int piotr, int *buff);
void radix_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
int hoare_partition(int *array, size_t size, int hoare, int rotx);
void hoare_sort(int *array, size_t size, int hoare, int rotx);
void quick_sort_hoare(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);


#endif
