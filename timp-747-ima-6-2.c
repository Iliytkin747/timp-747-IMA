#include <stdio.h>
#include <stdlib.h>

void Shell(int *arrey, int arrey_len)
{
	int i, j, jump;
	int tmp;
	for (jump = arrey_len / 2; jump > 0; jump /= 2)
		for (i = jump; i < arrey_len; i++)
		{
			tmp = arrey[i];
			for (j = i; j >= jump; j -= jump)
			{
				if (tmp < arrey[j - jump])
					arrey[j] = arrey[j - jump];
				else
					break;
			}
			arrey[j] = tmp;
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
	Shell(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", (array[i]));
	}
	printf("\n");
}
