#include <stdio.h>
#include <stdlib.h>

struct Node 
 {
  int value;
  struct Node *next;
  struct Node *prev;
 } Node;

struct List 
 {
  struct Node* begin;
  struct Node* end;
 } List;

int isEmpty(struct List* SP)
 {
  return SP->begin == NULL && SP->end == NULL;
 }

struct Node* find(struct List* SP, int k)
 {
  struct Node *tmp = SP->begin;
  while (tmp->value != k) 
   {
    if (tmp->next != NULL) 
     {
      tmp = tmp->next;
     }
    else 
     {
      return 0;
     }
   }
  return tmp;
 }

struct Node* find_invers(struct List* SP, int k)
 {
  struct Node *tmp = SP->end;
  while (tmp->value != k) 
   {
    if (tmp->prev != NULL) 
     {
      tmp = tmp->prev;
     }
    else 
     {
      return 0;
     }
   }
  return tmp;
 }

void init(struct List* SP, int value)
 {
  struct Node* tmp;
  tmp = (struct Node*)malloc(sizeof(struct Node));
  tmp->value = value;
  tmp->next = NULL;
  tmp->prev = NULL;
  SP->begin = tmp;
  SP->end = tmp;
 }

int push_back(struct List* SP, int x)
 {
  if (isEmpty(SP) == 1)
  init(SP, x);
  else
   {
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->value = x;
    tmp->prev = SP->end;
    tmp->next = NULL;
    SP->end = tmp;
    tmp->prev->next = tmp;
   }
  return 0;
 }

int push_front(struct List* SP, int x)
 {
  if (isEmpty(SP) == 1)
  init(SP, x);
  else
   {
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->value = x;
    tmp->prev = NULL;
    tmp->next = SP->begin;
    SP->begin = tmp;
    tmp->next->prev = tmp;
   }
  return 0;
 }

int clear(struct List* SP)
 {
  if (isEmpty(SP) == 1)
   {
    struct Node *tmp = SP->begin;
    struct Node *temp = NULL;
    while (tmp != NULL)
     {
      temp = tmp->next;
      free(tmp);
      tmp = temp;
     }
    SP->begin = NULL;
    SP->end = NULL;
   }
 }

void _remove(struct List* SP, struct Node *tmp) 
 {
  if (tmp != NULL) 
   {
    if (tmp == SP->begin && tmp == SP->end) 
     {
      clear(SP);
      return;
     }
    if (tmp == SP->begin)
     {
      SP->begin = tmp->next;
      tmp->next->prev = NULL;
     }
    else if (tmp == SP->end)
     {
      SP->end = tmp->prev;
      tmp->prev->next = NULL;
     }
    else if (tmp != SP->begin && tmp != SP->end)
     {
      tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
     }
    free(tmp);
   }
 }

int removeLast(struct List* SP, int x)
 {
  struct Node* EL = find_invers(SP, x);
  if (EL != NULL) 
   {
    _remove(SP, EL);
    return 0;
   }
  return -1;
 }

int removeFirst(struct List* SP, int x)
 {
  struct Node* EL = find(SP, x);
  if (EL != NULL) 
   {
    _remove(SP, EL);
    return 0;
   }
  return -1;
 }

int insertAfter(struct List* SP, int num, int data)
 {
  struct Node* tmp = SP->begin;
  for (int i = 1; i<num; i++)
   {
    tmp = tmp->next;
    if (tmp == NULL)
    return -1;
   }
  struct Node *temp = malloc(sizeof(Node));
  temp->value = data;
  temp->next = tmp->next;
  temp->prev = tmp;
  tmp->next->prev = temp;
  tmp->next = temp;
  return 0;
 }

int insertBefore(struct List* SP, int num, int data)
 {
  struct Node* tmp = SP->begin;
  for (int i = 1; i < num; i++)
   {
    tmp = tmp->next;
    if (tmp == NULL)
    return -1; 
   }
  struct Node *temp = malloc(sizeof(Node));
  temp->value = data;
  temp->prev = tmp->prev;
  temp->next = tmp;
  tmp->prev = temp;
  temp->prev->next = temp;
  return 0;
 }

void print(struct List* SP)
 {
  struct Node* tmp = SP->begin;
  while (tmp->next != NULL)
   {
    printf("%d ", tmp->value);
    tmp = tmp->next;
   }
  printf("%d\n", tmp->value);
 }

void print_invers(struct List* SP)
 {
  struct Node* tmp = SP->end;
  while (tmp->prev != NULL)
   {
    printf("%d ", tmp->value);
    tmp = tmp->prev;
   }
  printf("%d\n", tmp->value);
 }

int main()
 {
  int n, a;
  struct List* func = (struct List*)malloc(sizeof(struct List));
  scanf("%d", &n);
  for (int i = 0; i<n; i++)
   {
    scanf("%d", &a);
    push_back(func, a);
   }
  print(func);

  int k[3];
  scanf("%d%d%d", &k[0], &k[1], &k[2]);
  for (int i = 0; i<3; i++) 
   {
    if (find(func, k[i]) != NULL)
    printf("1 ");
    else
    printf("0 ");
   }
  printf("\n");

  int m;
  scanf("%d", &m);
  push_back(func, m);
  print_invers(func);
  int t;
  scanf("%d", &t);
  push_front(func, t);
  print(func);

  int j, x;
  scanf("%d%d", &j, &x);
  insertAfter(func, j, x);
  print_invers(func);

  int u, y;
  scanf("%d%d", &u, &y);
  insertBefore(func, u, y);
  print(func);
  int z;
  scanf("%d", &z);
  removeFirst(func, z);
  print_invers(func);
  int r;
  scanf("%d", &r);
  removeLast(func, r);
  print(func);

  clear(func);
  return 0;
}
