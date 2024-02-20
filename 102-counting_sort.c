#include "sort.h"
#include "stdlib.h"

/**
 * counting_sort - function that sorts an array of integers in ascending
 *                 order using the Counting sort algorithm
 *
 * @array: array
 * @size: size of the array
 *
 * Return: void
 */

void counting_sort(int *array, size_t size)
{
	int i, top;
	int *con = NULL, *dubl = NULL;
	size_t j, x, total = 0;

	if (array == NULL || size < 2)
		return;
	dubl = malloc(sizeof(int) * size);
	if (dubl == NULL)
		return;
	for (j = 0, top = 0; j < size; j++)
	{
		dubl[j] = array[j];
		if (array[j] > top)
			top = array[j];
	}
	con = malloc(sizeof(int) * (top + 1));
	if (con == NULL)
	{
		free(dubl);
		return;
	}

	for (i = 0; i <= top; i++)
		con[i] = 0;
	for (j = 0; j < size; j++)
		con[array[j]] += 1;
	for (i = 0; i <= top; i++)
	{
		x = con[i];
		con[i] = total;
		total += x;
	}
	for (j = 0; j < size; j++)
	{
		array[con[dubl[j]]] = dubl[j];
		con[dubl[j]] += 1;
	}
	print_array(con, top + 1);
	free(con);
	free(dubl);
}
