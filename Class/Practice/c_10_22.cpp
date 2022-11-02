//设计点类和圆类，判断点和圆的关系
#include<iostream>
#include<cmath>
using namespace std;
class Circle{
    private:
        double c_x,c_y,c_z;//圆心坐标
        double Diag;//直径
    public:
        Circle(double x,double y,double z,double diag=2){c_x=x,c_y=y,c_z=z,Diag=diag;}
        void SetDiag(double NewDiag){Diag=NewDiag;}//设置直径
        double GetDiag(){return Diag;}
};
class Point{
    private:
        double p_x,p_y,p_z;
    public:
        Point(double x,double y,double z){p_x=x,p_y=y,p_z=z;}
        double Getx(){return p_x;}
        double Gety(){return p_y;}
        double Getz(){return p_z;}
};
void InCircle(Circle a,Point b){
    double h=sqrt(b.Getx()*b.Getx()+b.Gety()*b.Gety()+b.Getz()*b.Getz());
    if (h>(a.GetDiag()*a.GetDiag())/4.0)
    {
        cout<<"位于圆外"<<endl;
    }
    else if(h==(a.GetDiag()*a.GetDiag())/4.0)
    {cout<<"位于圆上"<<endl;}
    else
    {cout<<"位于圆内"<<endl;}
}
int main(){
    Circle c1(0,0,0);
    Point p1(0,0,1);
    InCircle(c1,p1);
}