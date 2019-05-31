#include <stdio.h>
#include <math.h>

int main()
{
unsigned int n;
int a, c , sum=0;
scanf("%d", &n);
for(int i=0; i<n; i++)
{
scanf ("%d",&a);
c=(pow((-1),(i+1))*pow(a,2));
sum = sum + c;
}
printf ("%d\n",sum);
return 0;
}
