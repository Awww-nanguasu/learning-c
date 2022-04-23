#include<stdio.h>
#include<math.h>
/*int Solution(float x1,float x){
    return x1*x1-x;
}
float  integal(float x1,float x){
    x1=(x1*x1+x)/(2*x1);
    return x1;
}
int mySqrt(int x){
    if(x==1){
        return 1;
    }

    float x1;
    for (x1=(float)x/2;Solution(x1,x)<0;x1++){
        ;
    }
    while (Solution(x1,x)>1.0E-12)
    {
        ;
        x1=integal(x1,x);
    }
    return (int)x1;
}/*