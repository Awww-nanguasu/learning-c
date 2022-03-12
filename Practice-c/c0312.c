#include <string.h>
#include <stdio.h>
int count;
int fib(int n){
    if (n==3)
    {
        count++;
    }
    
    if(n<=2){
        return 1;
    }
    else{
        return fib(n-1)+fib(n-2);
    }
}
int main(){
    int n,Fibonaci;
    scanf("%d",&n);
    Fibonaci=fib(n);
    printf("fib:%d count:%d \n",Fibonaci,count);
    return 0;
}