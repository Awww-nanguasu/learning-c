//判断数据是大端储存还是小端储存
#include<stdio.h>
//int main(){
//    int a=1;
//    char* p=(char* )&a;
//    if (*p==1)
//    {
//        printf("小端\n");
//    }
//    else
//        printf("大端");
//}
int main(){
    unsigned char a=128;
    printf("%u\n",a);
}