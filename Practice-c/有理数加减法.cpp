#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
typedef struct Rational{
	int numerator;//定义分子
	int denominator;//定义分母
}R;
string b[4]={".Add",".Sub",".Mul",".Div"};
string c[4]={"加法结果为:","减法结果为:","乘法结果为:","除法结果为:"};
bool a[4]={0,1,1,1};
void UserAttention(){
    cout<<"-------------用户须知-------------"<<endl;
    cout<<"--使用'w'与's'键实现菜单的上下选中--"<<endl;
    cout<<"-----f键为确认键,esc键为退出键-----"<<endl;
    system("pause");
}
void CreateRational(R &r){
	cout<<"请输入分子和分母:";cin>>r.numerator;cin>>r.denominator;
	if(!r.denominator){cout<<"分母为0！";exit(-1);}//如果输入的分母为0，则直接报错并退出程序
}
void Simplify(R &x){//化简函数 
	int n=x.numerator,m=x.denominator;
	int r=0;
	while(r=n%m){n=m;m=r;}//辗转相除法求最大公约数
	x.numerator/=m;//化简分子分母
	x.denominator/=m;
	if(x.numerator>0&&x.denominator<0){
		x.numerator=-x.numerator;//如果分母有负号而分母无负号，则负号统一放入分子
		x.denominator=-x.denominator;
	}
}
R RationalAdd(R &x,R &y){//有理数加法
	R z;z.numerator=x.numerator*y.denominator+x.denominator*y.numerator;
	z.denominator=x.denominator*y.denominator;
	Simplify(z);return z;	
}
R RationalSub(R &x,R &y){//有理数减法
	R z;z.numerator=y.denominator*x.numerator-x.denominator*y.numerator;
	z.denominator=x.denominator*y.denominator;
	Simplify(z);return z;
}
R RationalDiv(R &x,R &y){//有理数除数
	R z;z.numerator=x.numerator*y.denominator;
	z.denominator=x.denominator*y.numerator;
	Simplify(z);return z;
}
R RationalMul(R &x,R &y){//有理数乘法
	R z;z.numerator=x.numerator*y.numerator;
	z.denominator=x.denominator*y.denominator;
	Simplify(z);
	return z;
}
void ShowRational(R x){//输出有理数
	if(!x.numerator){//如果分子为0，则直接输出0
		cout<<"0"<<endl;
	}
	cout<<x.numerator<<"/"<<x.denominator<<endl;	
}
void Menu(){
	cout<<"--------------------M e n u----------------------"<<endl;
	for(int i=1;i<=4;++i){
		cout<<"                  ";
		if(!a[i-1]){
			cout<<"-->";
		}
		else
			cout<<i;
		cout<<b[i-1];
		cout<<"            "<<endl;
	}
}	
void MoveArrow(int &i,int x){
	system("cls");
	a[i]=1;i=(i+x)%4;
	a[i]=0;
	Menu();
}
int main(){
    UserAttention();
	R (*fp[4])(R &,R &)={RationalAdd,RationalDiv,RationalMul,RationalSub};
	char ch;R x,y,z;
	int i=0,k;
	system("cls");
	Menu();
	while(ch!=27){ 
		if(kbhit()){
			ch=getch();
			switch (ch) {
				case 'w':
                    if(i==0){continue;} 
					MoveArrow(i,-1);
					break;
				case 's':
					if(i==3){continue;}
					MoveArrow(i,1);
					break;
				case 'f':
					system("cls");
					for( k=0;k<4;++k){
						if(a[k]==0){
							break;
						}
					}
					CreateRational(x);
					CreateRational(y);
					z=fp[k](x,y);
					cout<<c[k];
                    ShowRational(z);
					system("pause");
					system("cls");
					Menu();
				default:
					continue;
			}
		}
	}
}