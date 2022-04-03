#include<stdio.h>
/*int* text(){
    int a=10;
    return &a;
}
int main(){
    int* p=text();
    printf("%d\n",*p);
}*/
//int main(){
//    int* p;
//    *p=20;
//    printf("%d\n",*p);
//}
int My_strlen(char* arr){
    char* start=arr;
    while (*arr!='\0')
    {
        arr++;
    }
    char* end=arr;
    return end-start;
}
int main(){
    char arr[]="HelloWorld";
    int size=My_strlen(arr);
    printf("%d\n",size);
}