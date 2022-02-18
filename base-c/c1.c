#include <stdio.h>
#include <string.h>
int add(int x, int y)
{
    int z=x+y;
    return z; 
}
int main()
{
    int a =12;
    int b =23;
    int sum=0;
    sum=add(a,b);
    printf("%d\n",sum);
    return 0;
}
