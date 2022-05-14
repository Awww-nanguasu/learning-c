#include<stdio.h>
#include<string.h>
//在杨氏矩阵和中查找某个数
int FindNumber(int* xp,int* yp,int Hang,int Lie,int arr[3][3],int target){
    while (*xp<3 && *yp>=0)
    {
        if (arr[*xp][*yp]>target)
        {
            *yp-=1;
        }
        else if (arr[*xp][*yp]<target)
        {
            *xp+=1;
        }
        else{
            return 1;
        }
    }
    return 0;
}
int main(){
    int arr[3][3]={{1,2,3},{2,3,4},{3,4,5}},ret=0,x=0,y=2,*xp,*yp,target;
    xp=&x;
    yp=&y;
    printf("请输入你想查找的数:");
    scanf("%d",&target);
    ret=FindNumber(xp,yp,3,3,arr,target);
    if (ret==1)
    {
        printf("第%d行第%d列元素为所求\n",x+1,y+1);
    }
    else
    {
        printf("没找到\n");
    }
    return 0;
}