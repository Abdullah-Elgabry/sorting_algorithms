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
	size_t xl, siz = size;
	int chx = 0;

	if (array == NULL || size < 2)
		return;

	while (chx == 0)
	{
		chx = 1;
		for (xl = 0; xl < siz - 1; xl++)
		{
			if (array[xl] > array[xl + 1])
			{
				the_swaper(array + xl, array + xl + 1);
				print_array(array, size);
				chx = 0;
			}
		}
		siz--;
	}
}

