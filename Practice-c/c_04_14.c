#include<stdio.h>
int main(){
    int arr[63]={0},i,j;
    arr[62]=1;
    for ( i = 0; i < 200; i++)
    {
        for ( j = 0; j < 63; j++)
        {
            arr[j]*=2;
        }
        for ( j = 62; j>=0; j--)
        {
            if (arr[j]>9)
            {
                arr[j-1]+=arr[j]/10;
                arr[j]%=10;
            }
        }
    }
    for ( j = 0; j < 63; j++)
    {
        printf("%d",arr[j]);
    }
}