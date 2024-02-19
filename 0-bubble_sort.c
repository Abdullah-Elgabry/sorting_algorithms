#include "sort.h"

/**
 * the_swaper - this func will swaps integers
 * @x: Pointer to the first integer
 * @y: Pointer to the second integer
 */
void the_swaper(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - this algo will rearrange the int asc.
 *
 * @array: [int].
 *
 * @size: the [] size.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	int bubbly = 0;

	if (array == NULL || size < 2)
		return;

	while (bubbly == 0)
	{
		bubbly = 1;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				the_swaper(array + i, array + i + 1);
				print_array(array, size);
				bubbly = 0;
			}
		}
		len--;
	}
}

