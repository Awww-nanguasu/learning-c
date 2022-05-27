//sinx的麦克劳里级数
#include<stdio.h>
#include<math.h>
long factorial(int n){
    if (n==1)
    {
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
    
}
double mysin(double x){
    long jiechen;
    double sum=0,k=1,a=0;
    for (int n = 0; n < 8; n++)
    {
        //printf("d:%lf pow:%lf factorial:%lld ",k,pow(x,2*n+1),factorial(2*n+1));
        a=k*pow(x,2*n+1)/factorial(2*n+1);
        //printf("%lf\n",a);
        sum+=a;
        k*=-1;
    }
    return sum;
    
}
int main(){
    double exact,calc,x;
    scanf("%lf",&x);
    exact=sin(x);
    calc=mysin(x);
    //printf("%lld\n",factorial(17));
    printf("%lf %lf",exact,calc);
}