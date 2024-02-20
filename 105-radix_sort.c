#include "sort.h"

/**
 * get_max - this func will ret the max int val
 *
 * @array: [int]
 *
 * @size: [size]
 *
 * Return: max int in_the []
 */

int get_max(int *array, int size)
{
	int lg, xml;

	for (lg = array[0], xml = 1; xml < size; xml++)
	{
		if (array[xml] > lg)
			lg = array[xml];
	}

	return (lg);
}

/**
 * radix_counting_sort - reorder the [] based_on radix algo
 *
 * @array: [int]
 *
 * @size: [size]
 * @piotr: Ttargeted int
 *
 * @buff: rebo for []
 *
 */

void radix_counting_sort(int *array, size_t size, int piotr, int *buff)
{
	int inc[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t xml;

	for (xml = 0; xml < size; xml++)
		inc[(array[xml] / piotr) % 10] += 1;

	for (xml = 0; xml < 10; xml++)
		inc[xml] += inc[xml - 1];

	for (xml = size - 1; (int)xml >= 0; xml--)
	{
		buff[inc[(array[xml] / piotr) % 10] - 1] = array[xml];
		inc[(array[xml] / piotr) % 10] -= 1;
	}

	for (xml = 0; xml < size; xml++)
		array[xml] = buff[xml];
}

/**
 * radix_sort - his func will re-order the [] based_on radix_s algo
 * @array: [int]
 *
 * @size: [size]
 *
 */
void radix_sort(int *array, size_t size)
{
	int lg, piotr, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	lg = get_max(array, size);
	for (piotr = 1; lg / piotr > 0; piotr *= 10)
	{
		radix_counting_sort(array, size, piotr, buff);
		print_array(array, size);
	}

	free(buff);
}
