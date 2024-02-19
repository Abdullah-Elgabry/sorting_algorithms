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
 * shell_sort - based_on this algo order asc.
 * 
 * @array: [int]
 *
 * @size: [size]
 *
 */

void shell_sort(int *array, size_t size)
{
	size_t the_hl, bl, cl;
	
	if (array == NULL || size < 2)
		return;


    for (the_hl = 1; the_hl < (size / 3);)
        the_hl = the_hl * 3 + 1;
    for (; the_hl >= 1; the_hl /= 3)
    {
        for (bl = the_hl; bl < size; bl++)
        {
            cl = bl;
            while (cl >= the_hl && array[cl - the_hl] > array[cl])
            {
                swap_ints(array + cl, array + (cl - the_hl));
                cl -= the_hl;
            }
        }
        print_array(array, size);
    }
}
