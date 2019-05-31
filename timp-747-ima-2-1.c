#include <stdio.h>

int main()
{
unsigned int n;
int a, b=0;
scanf ("%d",&n);
for(int i=0; i<n; i++)
{
scanf ("%d", &a);
if (a<0) 
{
b++;
}
}
printf ("%d\n", b);
return 0;
}
