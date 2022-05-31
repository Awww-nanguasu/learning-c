
//{
//    char name;
//    int age;
//};
//int main(){
    //struct stu as={'a',12};
    //printf("%c %d",as->name,as.age);
//}
/*int main(){
    int i,j,k;
    for (int i = 1; i < 10; i++)
    {
        for ( j = 1; j < 10; j++)
        {
            for ( k = i>j?i:j; k <= 10; k++)
            {
                if (i*i+j*j==k*k)
                {
                    printf("%d %d %d\n",i,j,k);
                }
                
            }
            
        }
        
    }
    
}*/
#include<stdio.h>
/*struct stu
{
    char name;
    int age;
};  
int main(){
    struct stu s={'a',12};
    struct stu* s1=&s;
    printf("%c %d",s1->name,s.age);
}*/
void Move(int n,char source,char dest){
    printf("把第%d个元素:%c->%c\n",n,source,dest);
}
void hanota(int n,char A,char B,char C)
{
    if (n<=0)
    {
        printf("error");
    }
    if (n==1)
    {
        Move(1,A,C);
    }
    else{
        hanota(n-1,A,C,B);
        Move(n,A,C);
        hanota(n-1,B,A,C);
    }   
}
void main(){
    hanota(3,'A','B','C');
}