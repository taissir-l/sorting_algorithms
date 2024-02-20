#include "sort.h"

/**
 * _swap - function to swap two numbers
 *
 * @a: integer
 * @b: integer
 **/

void _swap(int *a, int *b)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
}

/**
 * selection_sort - function to sort array using selection sort
 *
 * @array: array
 * @size: size
 **/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, minm;

	if (array == NULL || size < 2)
		return;


	for (i = 0; i < size; i++)
	{
		minm = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[minm] > array[j])
				minm = j;
		}

		if (minm != i)
		{
			_swap(&array[i], &array[minm]);
			print_array(array, size);
		}
	}

}
