#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>
#include <string.h>

typedef struct St
{
	int information;
	struct St * left;
	struct St * right;
	struct St * original;
}
St;

typedef struct Tree
{
	struct St * Q;
	int count;
}
Tree;

void init(Tree* K)
{
	struct Tree * next_Tree = malloc(sizeof next_Tree);
	next_Tree->Q = NULL;
	next_Tree->count = 0;
	K = next_Tree;
}

int find(Tree* K, int aim, St* P)
{
	struct St * ST2;
	ST2 = K->Q;
	if (K->Q == NULL)
	{
		return 1;
	}
	while (1)
	{
		if (ST2 == NULL)
		{
			return 1;
		}
		else if (ST2->information == aim)
		{
			P->information = ST2->information;
			P->left = ST2->left;
			P->right = ST2->right;
			P->original = ST2->original;
			return 0;
		}
		else if (aim > ST2->information)
		{
			ST2 = ST2->right;
		}
		else
		{
			ST2 = ST2->left;
		}
	}
	return 1;
}

int insert(Tree* K, int aim)
{
	struct St * P, ** ST2, *last_St = NULL;
	struct St * cc;
	cc = malloc(sizeof * cc);

	int error = find(K, aim, cc);
	if (error == 0)
	{
		return 1;
	}
	ST2 = &K->Q;
	P = K->Q;
	while (1)
	{
		if (P == NULL)
		{
			P = *ST2 = malloc(sizeof * P);
			if (P != NULL)
			{
				P->information = aim;
				P->left = NULL;
				P->right = NULL;
				P->original = last_St;
				K->count++;
				return 0;
			}
			else
			{
				return 2;
			}
		}
		last_St = P;
		if (aim > P->information)
		{
			ST2 = &P->right;
			P = P->right;
		}
		else
		{
			ST2 = &P->left;
			P = P->left;
		}
	}
	return 0;
}

int profound(struct St * P, int Deep)
{
	if (P == NULL)
	{
		return Deep;
	}

	int D1 = profound(P->left, Deep + 1);
	int D2 = profound(P->right, Deep + 1);
	return (D1 > D2) ? D1 : D2;
}

void printSt(struct St * P, int current, int Deep, int first)
{
	if (current == Deep)
	{
		if (first > 0)
		{
			printf(" ");
		}
		if (P == NULL)
		{
			printf("_");
		}
		else
		{
			printf("%d", P->information);
		}
	}
	else if (P != NULL)
	{
		printSt(P->left, current + 1, Deep, first);
		printSt(P->right, current + 1, Deep, first + 1);
	}
	else
	{
		printSt(P, current + 1, Deep, first);
		printSt(P, current + 1, Deep, first + 1);
	}
}

void print(struct St * P)
{
	int m = profound(P, 0);
	for (int i = 1; i <= m; i++)
	{
		printSt(P, 1, i, 0);
		printf("\n");
	}
}

void printTree(struct Tree * K)
{
	print(K->Q);
}

void print_r1(struct St * P)
{
	int m = profound(P, 0);
	int flag_Tree = 0;
	for (int i = 1; i <= m; i++)
	{
		if (flag_Tree > 0)
		{
			printf(" ");
		}
		else
		{
			flag_Tree++;
		}
		printSt(P, 1, i, 0);
	}
}

void print_r2(struct Tree * K)
{
	St* X[15];
	int Xb = 0;
	St* write[15];
	int QW = 0;
	St* P = K->Q;
	while (QW < K->count)
	{
		while (P != NULL)
		{
			QW++;
			if (P->right != NULL)
			{
				Xb++;
				X[Xb] = P->right;
			}
			write[QW] = P;
			P = P->left;
		}
		P = X[Xb];
		Xb -= 1;
	}
	int flag_Tree = 0;

	for (int i = 1; i <= QW; i++)
	{
		if (flag_Tree > 0)
		{
			printf(" ");
		}
		else {
			flag_Tree++;
		}
		printf("%d", write[i]->information);
	}
	printf("\n");
}

void print_r3(struct St * P, int flag_Tree)
{
	if (P->left != NULL)
	{
		print_r3(P->left, flag_Tree + 1);
	}
	if (P->right != NULL)
	{
		print_r3(P->right, flag_Tree + 1);
	}
	printf("%d", P->information);
	if (flag_Tree > 0)
	{
		printf(" ");
	}
}

int main()
{
	struct Tree * K = malloc(sizeof K);
	init(K);
	for (int i = 0; i < 7; i++)
	{
		int X;
		scanf("%d", &X);
		insert(K, X);
	}
	print_r3(K->Q, 0);
	printf("\n");
	return 0;
}
