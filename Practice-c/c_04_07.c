#include<math.h>
#include<stdio.h>
/*double Sinpson(double A,double B,int N,double (*f)(double)){
    double i,XL,XC,XR,Length,sum=0;
    XL=A;
    Length=(B-A)/N;
    for ( i = 0; i < N; i++)
    {
        XR=XL+Length;
        XC=(XL+XR)/2;
        sum+=f(XL)+4*f(XC)+f(XR);
        XL=XR;
    }
    sum=sum/6*Length;
    return sum;
}
int main(){
    double y;
    y=Sinpson(0,atan(1)*4,3000,sin);
    printf("%.15f",y);
    return 0;
}*/
