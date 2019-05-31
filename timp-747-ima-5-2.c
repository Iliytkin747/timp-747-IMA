#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>

typedef struct list
{
	int information;
	struct list * left;
	struct list * right;
	struct list * original;
}
list;

typedef struct Tree
{
	struct list * square;
	int count;
}
Tree;

void init(Tree * K)
{
	struct Tree * next_Tree = malloc(sizeof next_Tree);
	next_Tree->square = NULL;
	next_Tree->count = 0;
	K = next_Tree;
}

int find(Tree* K, int S, list* Z)
{
	struct list * ZZ;
	ZZ = K->square;
	if (K->square == NULL)
	{
		return 1;
	}
	while (1)
	{
		if (ZZ == NULL)
		{
			return 1;
		}
		else if (ZZ->information == S)
		{
			Z->information = ZZ->information;
			Z->left = ZZ->left;
			Z->right = ZZ->right;
			Z->original = ZZ->original;
			return 0;
		}
		else if (S > ZZ->information)
		{
			ZZ = ZZ->right;
		}
		else
		{
			ZZ = ZZ->left;
		}
	}
	return 1;
}

int insert(Tree* K, int S)
{
	struct list * Z, ** ZZ, *ZZZ = NULL;
	struct list * plus;
	plus = malloc(sizeof * plus);
	int E = find(K, S, plus);
	if (E == 0)
	{
		return 1;
	}
	ZZ = &K->square;
	Z = K->square;
	while (1) {
		if (Z == NULL)
		{
			Z = *ZZ = malloc(sizeof * Z);
			if (Z != NULL)
			{
				Z->information = S;
				Z->left = NULL;
				Z->right = NULL;
				Z->original = ZZZ;
				K->count++;
				return 0;
			}
			else
			{
				return 2;
			}
		}
		ZZZ = Z;
		if (S > Z->information)
		{
			ZZ = &Z->right;
			Z = Z->right;
		}
		else
		{
			ZZ = &Z->left;
			Z = Z->left;
		}
	}
	return 0;
}

int profound(struct list * Z, int Deep)
{
	if (Z == NULL)
	{
		return Deep;
	}
	int D1 = profound(Z->left, Deep + 1);
	int D2 = profound(Z->right, Deep + 1);
	return (D1 > D2) ? D1 : D2;
}

void printList(struct list * Z, int current, int Deep, int first)
{
	if (current == Deep)
	{
		if (first > 0)
		{
			printf(" ");
		}

		if (Z == NULL)
		{
			printf("_");
		}
		else {
			printf("%d", Z->information);
		}
	}
	else if (Z != NULL)
	{
		printList(Z->left, current + 1, Deep, first);
		printList(Z->right, current + 1, Deep, first + 1);
	}
	else
	{
		printList(Z, current + 1, Deep, first);
		printList(Z, current + 1, Deep, first + 1);
	}
}

void print(struct list * Z)
{
	int H = profound(Z, 0);
	for (int i = 1; i <= H; i++) {
		printList(Z, 1, i, 0);
		printf("\n");
	}
}

void printTree(struct Tree * K)
{
	print(K->square);
}

void print_r(struct Tree * K)
{
	list * a[15];
	int V1 = 0;
	list * write[15];
	int V2 = 0;
	list * Z = K->square;
	while (V2 < K->count)
	{
		while (Z != NULL)
		{
			V2++;
			if (Z->right != NULL)
			{
				V1++;
				a[V1] = Z->right;
			}
			write[V2] = Z;
			Z = Z->left;
		}
		Z = a[V1];
		V1 -= 1;
	}
	int derevoplus = 0;
	for (int i = 1; i <= V2; i++)
	{
		if (derevoplus > 0)
		{
			printf(" ");
		}
		else
		{
			derevoplus++;
		}
		printf("%d", write[i]->information);
	}
	printf("\n");
}

int main()
{
	struct Tree * K = malloc(sizeof K);
	init(K);
	for (int i = 0; i < 7; i++)
	{
		int a;
		scanf("%d", &a);
		insert(K, a);
	}
	print_r(K);
	return 0;
}
