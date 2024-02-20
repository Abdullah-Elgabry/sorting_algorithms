#include "sort.h"

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
 * bitonic_merge - this func will re_order the [] based_on bitonic algo
 *
 * @array: [int]
 *
 * @size: [size]
 *
 * @start: point of srt
 *
 * @mec: [siz]
 *
 * @ph: the ph will be taken
 *
 */

void bitonic_merge(int *array, size_t size, size_t start, size_t mec, char ph)
{
	size_t xml, tke = mec / 2;

	if (mec > 1)
	{
		for (xml = start; xml < start + tke; xml++)
		{
			if ((ph == NO && array[xml] > array[xml + tke]) ||
			    (ph == YES && array[xml] < array[xml + tke]))
				swap_ints(array + xml, array + xml + tke);
		}
		bitonic_merge(array, size, start, tke, ph);
		bitonic_merge(array, size, start + tke, tke, ph);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: [int]
 * @size: [size]
 * @start: The starting index of a block of the building bitonic sequence.
 * @mec: The size of a block of the building bitonic sequence.
 * @ph: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t mec, char ph)
{
	size_t cut = mec / 2;
	char *str = (ph == NO) ? "NO" : "YES";

	if (mec > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", mec, size, str);
		print_array(array + start, mec);

		bitonic_seq(array, size, start, cut, NO);
		bitonic_seq(array, size, start + cut, cut, YES);
		bitonic_merge(array, size, start, mec, ph);

		printf("Result [%lu/%lu] (%s):\n", mec, size, str);
		print_array(array + start, mec);
	}
}

/**
 * bitonic_sort - re_order the [] based_on bitonic algo
 *
 * @array: [int]
 *
 * @size: [size]
 *
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, NO);
}
