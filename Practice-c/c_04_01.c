#include<stdio.h>
#include<math.h>
#include<time.h>
//�ҹ���ʽ����
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
//�ж��Ƿ�Ϊ����������
void IsCloseNumber(int x,int y){
    if (SumCommonFactor(x)==y && SumCommonFactor(y)==x)
        printf("%d,%d��������\n",x,y);
    else
        //printf("%d,%d����������\n",x,y);
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
        //��1��10000��key��Ӧ��value�ŵ�tmp��
        tmp=record[i];
        //������Ӻͳ���19999�������������������������Ӧ��
        if (tmp>=19999)
        {
            continue;
        }
        //��tmp-1��Ϊkey������Ӧ��value�Ƿ�Ϊ
        //ע���tmp������Ӧrecord[tmp-1]  
        if (record[tmp-1]==i+1 && tmp!=i+1 )
        {
            printf("%d��%dΪ������\n",tmp,i+1);
        }        
    }
}
int main(){
    int record[20000]={0};
    int i,j,sum,count=0;
    //�涨�����һ���͵ڶ���Ϊ0�������������Ӽ���
    record[0]=0;
    record[1]=0;
    sum=sum%1;
    for ( i = 3; i <=20000; i++)
    {
    //ÿ��i�任��sum��ҪΪ0
        for (  sum=0 ,j = 1; j < i; j++)
        {
            //���iΪ���ӣ�i�ͼӵ�sum��
            if (i%j==0)
            {
                sum+=j;
            }
        }
        //�ö�Ӧ�������¼�¶�Ӧ�������Ӻ�
        record[i-1]=sum;
    }
    IsCloseNum(record);
    return 0;
}