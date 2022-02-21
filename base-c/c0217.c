#include <stdio.h>
#include <string.h>
int main()
//{
//    for (int i = 0; i <=10; i++)
//    {
//        printf("%d\n",i);
//    }
//    int i=0;
//    for (i = 0; i <= 10; i++)
//    {
//        if(5==i)
//        {
//            continue;
//        }
//    printf("%d\n",i);
//}     
//    printf("%d",i);
//    return 0;
//}
//{
//    int i=0;
//    while(i<10)
//    {
//        i++;
//        if (5==i)
//        {
//            continue;
//        }
//        printf("%d",i);
//    }
//    printf("%d",i);
//}
//{
//    static int count=0;
//    for(int i=0;i<10;i++)
//    {
//        for (int j = 0; j < 10; j++)
//        {
//            count +=1;
//            printf("%d %d\n",j,count);
//        }      
//    }
//}
{
    int count=0;
    int i=0;
    int j=0;
    int lunshu=0;
    for(;i<10;i++)
    {
        lunshu++;
        printf("ÕâÊÇµÚ%dÂÖ",lunshu);
        for(;j<10;j++)
        {
            count+=1;
            printf("i:%d count:%d j:%d\n",i,count,j);
        }
    }
}