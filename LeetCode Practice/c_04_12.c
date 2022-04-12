#include<stdio.h>
int main(){
    int a[19]={1,1,2,2,3,3,4,5,5,6,6,7,7,8,8,9,9,10,10};
    int i,ret=0;
    for(i=0;i<19;i++)
    {
        ret=i>0?ret^a[i]:a[i];
    }
    printf("%d\n",ret);
    return 0;
}