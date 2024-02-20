#include "sort.h"

/**
 * merge_subarr - this func will reorder the sub[]
 *
 * @polx: the target []
 *
 * @buff: data will put
 *
 * @sti: 1st idx
 *
 * @ndi: 2nd idx
 *
 * @lstti: last idx
 *
 */

void merge_subarr(int *polx, int *buff, size_t sti, size_t ndi, size_t lstti)
{
	size_t xml, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(polx + sti, ndi - sti);
	printf("[right]: ");
	print_array(polx + ndi, lstti - ndi);

	for (xml = sti, j = ndi; xml < ndi && j < lstti; k++)
		buff[k] = (polx[xml] < polx[j]) ? polx[xml++] : polx[j++];
	for (; xml < ndi; xml++)
		buff[k++] = polx[xml];
	for (; j < lstti; j++)
		buff[k++] = polx[j];
	for (xml = sti, k = 0; xml < lstti; xml++)
		polx[xml] = buff[k++];

	printf("[Done]: ");
	print_array(polx + sti, lstti - sti);
}


/**
 * merge_sort_recursive - this func will <-> be as a linker
 *
 * @polx: [sub_arr]
 *
 * @buff: this is thr rebo
 *
 * @sti: st idx
 *
 * @lstti: last idx of []
 */

void merge_sort_recursive(int *polx, int *buff, size_t sti, size_t lstti)
{
	size_t ndi;

	if (lstti - sti > 1)
	{
		ndi = sti + (lstti - sti) / 2;
		merge_sort_recursive(polx, buff, sti, ndi);
		merge_sort_recursive(polx, buff, ndi, lstti);
		merge_subarr(polx, buff, sti, ndi, lstti);
	}
}

/**
 * merge_sort - reorder [] based_on merge_sort algo
 *
 * @array: [int]
 *
 * @size: [size]
 *
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_sort_recursive(array, buff, 0, size);

	free(buff);
}
