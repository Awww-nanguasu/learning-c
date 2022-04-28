#include<stdio.h>
#include<string.h>
/*bool isValid(char * s){
    int a[100]={0};
    int count,sum=0;
    for( count=0;s[count]!=0;count++){
        if(s[count]==125 || s[count]==93){
            a[count]=s[count]-1;
        }    
        else{
            a[count]=s[count];
        }
    }
    if((count)%2!=0){
        return false;
    }
    for(int i=0;i<count-1;i+=2){
        sum+=a[i]-a[i+1];
    }
    if(sum!=-(count)/2){
        return false;
    }
    else
        return true;
}*/