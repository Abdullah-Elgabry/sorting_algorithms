#include "sort.h"


/**
 * get_max - this func will return the max int val
 *
 * @array: [int]
 *
 * @size: [size]
 *
 * Return: max int
 *
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
 * counting_sort - re-order the int based_on counting algo
 *
 * @array: [int]
 *
 * @size: [size]
 *
 */

void counting_sort(int *array, size_t size)
{
    int *inc, *rearr, lg, xml;


    if (array == NULL || size < 2)
        return;


    rearr = malloc(sizeof(int) * size);
    if (rearr == NULL)
        return;
    lg = get_max(array, size);
    inc = malloc(sizeof(int) * (lg + 1));
    if (inc == NULL)
    {
        free(rearr);
        return;
    }


    for (xml = 0; xml < (lg + 1); xml++)
        inc[xml] = 0;
    for (xml = 0; xml < (int)size; xml++)
        inc[array[xml]] += 1;
    for (xml = 0; xml < (lg + 1); xml++)
        inc[xml] += inc[xml - 1];
    print_array(inc, lg + 1);


    for (xml = 0; xml < (int)size; xml++)
    {
        rearr[inc[array[xml]] - 1] = array[xml];
        inc[array[xml]] -= 1;
    }


    for (xml = 0; xml < (int)size; xml++)
        array[xml] = rearr[xml];


    free(rearr);
    free(inc);
}
