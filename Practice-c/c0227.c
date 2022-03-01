//输出100-200间的素数
#include <stdio.h>
#include <string.h>
#include <math.h>
//int main()
//{
//    int i,count=0;
//    for(i=100;i<=200;i++)
//    {
//        for(count=2;count<i;count++)
//        {
//            if(i%count==0)
//           {
//                break;
//            }
//        }
//        if(count==i)
//        {
//            printf("%d为质数",i);
//        }
//    }
//    return 0;
//}
int main()
{
    int i,count;
    for(i=101;i<=200;i+=2)
    {
        for(count=2;count<sqrt(i);count++)
        {
            if(i%count==0)
            {
                break;
            }
        }
        if(count>sqrt(i))
        {
            printf("%d\n",i);
        }
    }
    return 0;
}