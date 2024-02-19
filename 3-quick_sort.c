#include "sort.h"

void quick_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void lomuto_sort(int *array, size_t size, int left, int right);
int lomuto_partition(int *array, size_t size, int left, int right);

/**
 * swap_ints - this func will re-order integers
 * @a: 1st int
 * @b: 2nd int
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - this algo will reorder the [int based on logic of lp]
 *
 * @array: the [int]
 * @size: [size]
 * @left: st pnt
 * @right: nd pnt
 *
 * Return: will ret the pos
 *
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *driver, up, down;

	driver = array + right;
	for (up = down = left; down < right; down++)
	{
		if (array[down] < *driver)
		{
			if (up < down)
			{
				swap_ints(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}

	if (array[up] > *driver)
	{
		swap_ints(array + up, driver);
		print_array(array, size);
	}

	return (up);
}

/**
 * lomuto_sort - this func will ex the lop view
 *
 * @array: will re_arr [int]
 *
 * @size: [size]
 *
 * @left: st pov
 *
 * @right: nd pov
 *
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, belong - 1);
		lomuto_sort(array, size, belong + 1, right);
	}
}

/**
 * quick_sort - this func will re-order the int by quick algo
 * @array: [int]
 * @size: [size]
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
