#include<stdio.h>
#include<string.h>
void Swap(char* A,char* B,int Width){
    int i;
    for ( i = 0; i < 4; i++)
    {
        char tmp=*(A+i);
        *(A+i)=*(B+i);
        *(B+i)=tmp;

    }
}
int IntCompare(void* A,void* B){

    return *((int*)A)-*((int *)B);
}
void My_Sort(void* A,int Size,int Width,int (* Compare)(void* B,void* C)){
    int i,j;
    for ( i = 0; i < Size; i++){
        for ( j = 0; j < Size-i-1; j++)
        {
            if(Compare((char*)A+j*Width,(char*)A+(j+1)*Width)>0){
                Swap((char*)A+j*Width,(char*)A+(j+1)*Width,Width);
            }
        }
        
    }
    
}
int main(){
    int A[10]={23,213,4,542,27,41,54,2,99,120};
    float B[10]={23.2,34.21,23.0,12.4,23.34,934.12,567.89,453.87,231.54};
    My_Sort(A,10,4,IntCompare);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n",A[i]);
    }
    
}