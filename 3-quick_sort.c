#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm (Lomuto partition scheme)
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - recursive helper function for quick_sort
 * @array: array to be sorted
 * @low: lower index of the current partition
 * @high: higher index of the current partition
 * @size: size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = lomuto_p(array, low, high, size);

		quick_sort_recursive(array, low, partition_index - 1, size);
		quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
 * lomuto_p - Lomuto partition scheme for quick_sort
 * @array: array to be partitioned
 * @low: lower index of the partition
 * @high: higher index of the partition
 * @size: size of the array
 * Return: partition index
 */
int lomuto_p(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * swap - Swaps two elements in an array
 * @a: pointer to the first element
 * @b: pointer to the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
