#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - func Swap two integers
 * @a: array
 * @b: array
 */
void swap_ints(int *a, int *b)
{
	int x;

	x = *a;
	*a = *b;
	*b = x;
}
/**
 * lomuto_partition - func to Order a subset of integers according
 *                    to the lomuto partition scheme
 *
 * @array: array of integers
 * @size: size of the array
 * @left: starting index
 * @right: ending index
 *
 * Return: final partition index.
 */

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *p, a, b;

	p = array + right;

	for (a = b = left; b < right; b++)
	{
		if (array[b] < *p)
		{
			if (a < b)
			{
				swap_ints(array + b, array + a);
				print_array(array, size);
			}
			a++;
		}
	}
	if (array[a] > *p)
	{
		swap_ints(array + a, p);
		print_array(array, size);
	}
	return (a);
}
/**
 * lomuto_sort - fnc to implement the quicksort algorithm
 *
 * @array: Array
 * @size: size of the array.
 * @left: starting index
 * @right: ending index
 */

void lomuto_sort(int *array, size_t size, int left, int right)
{
	int x;

	if (right - left > 0)
	{
		x = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, x - 1);
		lomuto_sort(array, size, x + 1, right);
	}
}

/**
 * quick_sort - Sorting an array of integers in
 *              ascending order
 *
 * @array: array
 * @size: size of the array.
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
