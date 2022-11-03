//设计一个计算机类
//为什么加一个 虚基类参数加个&就能改变输出结果
#include<iostream>
using namespace std;
class Calculate{
    public:
        double num_a,num_b;
        double result(){return 0;}
};
class Add:public Calculate{
    public:
    double result(){return num_a+num_b;}
};
class Sub:public Calculate{
    public:
    double result(){return num_a-num_b;}
};
class Div:public Calculate{
    public:
    double result(){if(num_b!=0)return num_a+num_b;else return 0;}
};
class Mul:public Calculate{
    public:
    double result(){return num_a*num_b;}
};
int main(){
    Add a1;
    a1.num_a=1,a1.num_b=2;
    cout<<a1.result();
}
