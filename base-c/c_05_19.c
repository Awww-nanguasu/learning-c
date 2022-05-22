#include<stdio.h>
#include<string.h>
void My_memmove(void* dest,void* source,int num){
    if (source<dest)
    {
        for (;num>0; num--)
        {
            *((char*)dest+num-1)=*((char*)source+num-1);
        }
    }
    else{
        for (int i=0;i<num; i++)
        {
            *((char*)dest+i)=*((char*)source+i);
        }
    }
}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    int b[5]={3,4,5,6,7};
    //memmove(a,a+1,20);
    My_memmove(a+1,a,20);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
}