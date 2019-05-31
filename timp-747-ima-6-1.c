#include <stdio.h>
#include <stdlib.h>

void Comb(int *array, int array_len)
{
	if (array && array_len)
	{
		int jump = array_len, i;
		int change = 1;
		while (jump > 1 || change)
		{
			if (jump > 1)
				jump /= 1.24733;
			change = 0;
			for (i = 0; i + jump < array_len; ++i)
				if (array[i + jump] > array[i])
				{
					int tmp;
					tmp = array[i];
					array[i] = array[i + jump];
					array[i + jump] = tmp;
					change = 1;
				}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int array[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &array[i]);
	}
	Comb(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", (array[i]));
	}
	printf("\n");
}
