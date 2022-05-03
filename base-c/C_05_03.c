#include<stdio.h>
int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    int Left=0,Right,tmp;
    Right=9;
    while (Left<Right)
    {
        if(arr[Left]%2==0){
            while (!(arr[Right]%2) &&Right>Left)
            {
                Right--;
            }
            tmp=arr[Left];
            arr[Left]=arr[Right];
            arr[Right]=tmp; 
        }
        Left++;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
}