//类的联系：构建立方体类
//设计立方体类(Cube)，求出立方体的面积和体积
//分别利用全局函数和成员函数判断两个立方体是否相等
#include<iostream>
using namespace std;
class Cube{
    private:
        double Length,Width,Hight;
    public:
        Cube(int a,int b,int c);
        void WhetherSame(Cube &d);
        void SetCube(double NewLength,double NewHight,double Newwidth){Length=NewLength,Hight=NewHight,Width=Newwidth;}
        double GetL(){return Length;}
        double GetW(){return Width;}
        double GetH(){return Hight;}
        double GetSquare(){return Hight*Width*Length;}
};
Cube::Cube(int a,int b,int c){
    Length=a;
    Width=b;
    Hight=c;
}
void Cube::WhetherSame(Cube &d){
    if (Length==d.GetL()&& Hight==d.GetH()&&Width==d.GetW())
    {
        cout<<"相同"<<endl;
    }
    else cout<<"不相同"<<endl;
}
void WhetherSame(Cube &a,Cube &d){
    if (d.GetH()==a.GetH()&&d.GetL()==a.GetL()&&d.GetW()==a.GetW())
    {
        cout<<"相同"<<endl;
    }
    else cout<<"不相同"<<endl;
}
int main(){
    Cube c1(1,2,3);
    Cube c2(1,2,3);
    //c1.WhetherSame(c2);
    WhetherSame(c1,c2);
}