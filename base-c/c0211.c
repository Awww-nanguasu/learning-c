#include <stdio.h>
#include <string.h>
//int main()
//{
//    int day=0;
//    scanf("%d",&day);
//    switch (day)
 //   {
    //case 1:
   //     printf("asd");
      //  break;
   // case 2:
   //     break;
   // default:
   //     break;
   // }
//}
int main()
{
    int a=0;
    while(a<=10)
    {
        a++;
        if(5==a)
        {
            continue;
        }
        printf("%d",a);
    }
}