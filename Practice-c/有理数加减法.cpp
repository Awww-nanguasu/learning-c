#include<iostream>
#include<string.h>
#include<conio.h>
using namespace std;
typedef struct Rational{
	int numerator;//�������
	int denominator;//�����ĸ
}R;
string b[4]={".Add",".Sub",".Mul",".Div"};
string c[4]={"�ӷ����Ϊ:","�������Ϊ:","�˷����Ϊ:","�������Ϊ:"};
bool a[4]={0,1,1,1};
void UserAttention(){
    cout<<"-------------�û���֪-------------"<<endl;
    cout<<"--ʹ��'w'��'s'��ʵ�ֲ˵�������ѡ��--"<<endl;
    cout<<"-----f��Ϊȷ�ϼ�,esc��Ϊ�˳���-----"<<endl;
    system("pause");
}
void CreateRational(R &r){
	cout<<"��������Ӻͷ�ĸ:";cin>>r.numerator;cin>>r.denominator;
	if(!r.denominator){cout<<"��ĸΪ0��";exit(-1);}//�������ķ�ĸΪ0����ֱ�ӱ����˳�����
}
void Simplify(R &x){//������ 
	int n=x.numerator,m=x.denominator;
	int r=0;
	while(r=n%m){n=m;m=r;}//շת����������Լ��
	x.numerator/=m;//������ӷ�ĸ
	x.denominator/=m;
	if(x.numerator>0&&x.denominator<0){
		x.numerator=-x.numerator;//�����ĸ�и��Ŷ���ĸ�޸��ţ��򸺺�ͳһ�������
		x.denominator=-x.denominator;
	}
}
R RationalAdd(R &x,R &y){//�������ӷ�
	R z;z.numerator=x.numerator*y.denominator+x.denominator*y.numerator;
	z.denominator=x.denominator*y.denominator;
	Simplify(z);return z;	
}
R RationalSub(R &x,R &y){//����������
	R z;z.numerator=y.denominator*x.numerator-x.denominator*y.numerator;
	z.denominator=x.denominator*y.denominator;
	Simplify(z);return z;
}
R RationalDiv(R &x,R &y){//����������
	R z;z.numerator=x.numerator*y.denominator;
	z.denominator=x.denominator*y.numerator;
	Simplify(z);return z;
}
R RationalMul(R &x,R &y){//�������˷�
	R z;z.numerator=x.numerator*y.numerator;
	z.denominator=x.denominator*y.denominator;
	Simplify(z);
	return z;
}
void ShowRational(R x){//���������
	if(!x.numerator){//�������Ϊ0����ֱ�����0
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