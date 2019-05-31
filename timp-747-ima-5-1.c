#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <string.h>

typedef struct Node
{
	int information;
	struct Node * left;
	struct Node * right;
	struct Node * original;
}
Node;

typedef struct tree {
	struct Node * C;

	int count;
}
tree;

void init(tree* K)
{
	struct tree * next_tree = malloc(sizeof next_tree);
	next_tree->C = NULL;
	next_tree->count = 0;
	K = next_tree;
}

int find(tree* K, int aim, Node* N)
{
	struct Node * St2;
	St2 = K->C;
	if (K->C == NULL)
	{
		return 1;
	}

	while (1)
	{
		if (St2 == NULL)
		{
			return 1;
		}
		else if (St2->information == aim)
		{
			N->information = St2->information;
			N->left = St2->left;
			N->right = St2->right;
			N->original = St2->original;
			return 0;
		}
		else if (aim > St2->information)
		{
			St2 = St2->right;
		}
		else
		{
			St2 = St2->left;
		}
	}
	return 1;
}

int insert(tree* K, int aim)
{
	struct Node * N, ** St, *pr_St = NULL;
	struct Node * F;
	F = malloc(sizeof * F);
	int error_tree = find(K, aim, F);
	if (error_tree == 0)
	{
		return 1;
	}
	St = &K->C;
	N = K->C;
	while (1)
	{
		if (N == NULL)
		{
			N = *St = malloc(sizeof * N);
			if (N != NULL)
			{
				N->information = aim;
				N->left = NULL;
				N->right = NULL;
				N->original = pr_St;
				K->count++;
				return 0;
			}
			else
			{
				return 2;
			}
		}

		pr_St = N;
		if (aim > N->information)
		{
			St = &N->right;
			N = N->right;
		}
		else
		{
			St = &N->left;
			N = N->left;
		}
	}
	return 0;
}

int R(struct Node * N, int Deep)
{
	if (N == NULL)
	{
		return Deep;
	}
	int R1 = R(N->left, Deep + 1);
	int R2 = R(N->right, Deep + 1);
	return (R1 > R2) ? R1 : R2;
}

void printNode(struct Node * N, int current, int Deep, int first)
{
	if (current == Deep)
	{
		if (first > 0)
		{
			printf(" ");
		}
		if (N == NULL)
		{
			printf(" ");
		}
		else
		{
			printf("%d", N->information);
		}
	}
	else if (N != NULL)
	{
		printNode(N->left, current + 1, Deep, first);
		printNode(N->right, current + 1, Deep, first + 1);
	}
	else
	{
		printNode(N, current + 1, Deep, first);
		printNode(N, current + 1, Deep, first + 1);
	}
}

void print(struct Node * N)
{

	int Q = R(N, 0);
	for (int i = 1; i <= Q; i++)
	{
		printNode(N, 1, i, 0);
		printf("\n");
	}
}

void printTree(struct tree * K)
{
	print(K->C);
}

void print_obh1(struct Node * N)
{
	int Q = R(N, 0);
	int flag_tree = 0;
	for (int i = 1; i <= Q; i++)
	{
		if (flag_tree > 0)
		{
			printf(" ");
		}
		else
		{
			flag_tree++;
		}
		printNode(N, 1, i, 0);
	}
}

int main()
{
	struct tree * K = malloc(sizeof K);
	init(K);
	for (int i = 0; i < 7; i++)
	{
		int a;
		scanf("%d", &a);
		insert(K, a);
	}
	print_obh1(K->C);
	printf("\n");
	return 0;
}
