#include <stdio.h>
#include <stdlib.h>

void quick_sort(int* arr, int arr_len) {
	int size = arr_len;
	int k = 0;
	int c = arr[(int)(arr_len / 2)];
	int tmp = 0;
	do {
		while (arr[k] < c) k++;
		while (arr[arr_len] > c) arr_len--;

		if (k <= arr_len) {
			tmp = arr[k];
			arr[k] = arr[arr_len];
			arr[arr_len] = tmp;
			k++;
			arr_len--;
		}
	} while (k <= arr_len);
	if (arr_len > 0) quick_sort(arr, arr_len);
	if (arr_len > 0) quick_sort(arr + k, size - k);
}
int main()
{
	int n;
	scanf("%d", &n);
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	quick_sort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", (arr[i]));
	}
	printf("\n");
}
