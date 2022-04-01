#include<stdio.h>
#include<math.h>
#include<time.h>
//找公因式函数
/*int SumCommonFactor(int x){
    int i,sum=0;
    for ( i = 1; i < x; i++)
    {
        if (x%i==0)
        {
            sum+=i;
        }
    }
    return sum;
}
//判断是否为亲密数函数
void IsCloseNumber(int x,int y){
    if (SumCommonFactor(x)==y && SumCommonFactor(y)==x)
        printf("%d,%d是亲密数\n",x,y);
    else
        //printf("%d,%d不是亲密数\n",x,y);
        ;
}
int main(){
    int a,b;
    for ( a = 1; a <=10000 ; a++)
    {
        for ( b =a+ 1; b <= 10000; b++)
        {
            IsCloseNumber(a,b);
        }
    }
    return 0;
}*/
void IsCloseNum(int record[20000]){
    int i,j,tmp;
    for ( i = 0; i < 20000; i++)
    {
        //让1到10000的key对应的value放到tmp中
        tmp=record[i];
        //如果因子和超过19999，就舍弃，不会有数组跟它对应的
        if (tmp>=19999)
        {
            continue;
        }
        //让tmp-1作为key，看对应的value是否为
        //注意第tmp个数对应record[tmp-1]  
        if (record[tmp-1]==i+1 && tmp!=i+1 )
        {
            printf("%d和%d为亲密数\n",tmp,i+1);
        }        
    }
}
int main(){
    int record[20000]={0};
    int i,j,sum,count=0;
    //规定数组第一个和第二个为0，不参与求因子计算
    record[0]=0;
    record[1]=0;
    sum=sum%1;
    for ( i = 3; i <=20000; i++)
    {
    //每次i变换，sum都要为0
        for (  sum=0 ,j = 1; j < i; j++)
        {
            //如果i为因子，i就加到sum中
            if (i%j==0)
            {
                sum+=j;
            }
        }
        //让对应的数组记录下对应数的因子和
        record[i-1]=sum;
    }
    IsCloseNum(record);
    return 0;
}