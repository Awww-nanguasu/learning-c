#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
int Hang, Line, All, Num, i,Lei,ch,Esc=0/*-1为失败，1为胜利，2为按键退出，0为进行*/;
int *b/*底层上移动的指针*/,*t/*玩家操作的指针(用于在Top上移动)*/,*k;//程序的指针,在Top图里，与玩家分开
int Mine[999] = {0}/*地雷图，大于8为雷*/, Top[999] = {0};//顶层图 比地雷图小一圈
int *Reflect(int *TopTU){//将顶层指针映射到底层,画图分析可得两者关系
  return (1+(TopTU-Top)/Line)*(Line+2)+(TopTU-Top)%Line+1+Mine;
}
void buttom() {  //生成地雷  Mine里大于8为雷
  srand((unsigned int)time(NULL));//随机种子
  for(Num=Lei;Num > 0;Num--){
    k = Top + rand() % All +1;//使k指向Top中的随机格子（随机生成雷）
    b=Reflect(k);//对应的b指针（映射到底层）
    if(*b>8){Num++;continue;}//不在同一格重复生成雷的并退回重新随机生成
    *b = 9;++*(b + 1);++*(b - 1);//将b指的格子赋值9且左右俩边加上1
    for (i = 0; i < 3; i++, ++*(b + Line + i), ++*(b - Line - i));//将b指的格子上下3格加上1
  }
}
void start() {//初始化参数
  Hang = 20;//行数
  Line = 30;//列数
  Lei = 20;//雷数
  All = Hang * Line;//辅助数 Top全格子数量
  buttom();//生成雷
  t = Top;++*t;
}
void marker(int color,char C,int num){//一堆变色和空格处理就随便写了，if(t!=k)用来检查是否为被选中状态
  if(C=='\t')
    if(t!=k)if(num==0)printf("   ");else printf(" %d ",num);
    else if(num==0)printf("\033[1;%d;40m> <\033[0m",color);else printf("\033[1;%d;40m>%d<\033[0m",color,num);
  else
    if(t!=k)printf("\033[1;%d;40m %c \033[0m",color,C);
    else printf("\033[1;%d;40m>%c<\033[0m",color,C);
}
void top(){//顶层 负责打印与胜负判断
  for (k=Top,Num=Hang*Line-Lei; k < Top+All;k++){//遍历数组Top
    b=Reflect(k);//对应上数组Mine
    if (*b > 8 && *k < 0) Esc = -1;//翻开地雷结束游戏
    if (*b < 9 && *k < 0) Num--;//同时满足Mine不为雷且Top翻开的格子数减到0则胜利
    if ((k-Top) % Line == 0) printf("\n");//Line格换一行
    switch (*k){//根据遍历中格子的内容打印
      case 0:printf("[ ]");break;//草地
      case 1:marker(36,' ',0);break;//被选中
      case 2:marker(33,'#',0);break;//标记雷
      case 3:marker(36,'?',0);break;//标记问号
      case -1://已翻开的草地(透视到底层Mine图)
        if(*b>8)marker(31,'@',0);//翻开了雷
        else marker(36,'\t',*b);//透视到底层
        break;
    }
  }
  if(Num==0)Esc=1;
}
void fanGe(int *j){
  int x, y, *p;
  p=Reflect(j);//被选中的Top格在Mine上的映射
  if (*p == 0)
    for(p-=Line+3,j-=Line+1,y=0;y<3;p+=Line-1,j+=Line-3,y++)
      for(x=0;x<3;p++,j++,x++)//俩个for循环遍历传入格子的周围
        if (//p指针在Mine图上的越界判断(地雷图的最外一圈),画图可知各边界的条件(0为越界，1为未越界)
            ((p - Mine) % (Line + 2) != 0 &&                   //右边界   
             (p - Mine + 1) % (Line + 2) != 0 &&               //左边界
             p - Mine < (Hang + 2) * (Line + 2) - Line - 1 &&  //下边界
             p - Mine > Line + 1)                              //上边界
            && *j == 0 /*Top格为0才翻*/) {*j = -1;fanGe(j)/*自递归*/;}
}
void logical() {
  ch = _getch();//每次循环只用获取一次按键值
  if (*t == 1) --*t;//删除拖尾
  if (ch == 27) Esc = 2;                              // ESC
  if (ch == 119 && t - Line > Top - 1) t -= Line;     // W上
  if (ch == 115 && t + Line < Top + All) t += Line;   // S下
  if (ch == 100 && t + 1 < Top + All) t++;            // D右
  if (ch == 97 && t > Top) t--;                       // A左
  if (*t == 0) ++*t;//将当前指着的格子变为被选中状态
  if (ch == 101)if (*t > 0 && *t < 3)++*t;else *t = 0;// E标记
  if (ch == 102){*t=-1;fanGe(t)/*传入了当前格子地址*/;}// F翻格
}
int main() {
  start();
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//去光标
  CONSOLE_CURSOR_INFO CursorInfo;
  GetConsoleCursorInfo(handle, &CursorInfo);
  CursorInfo.bVisible = FALSE;
  SetConsoleCursorInfo(handle, &CursorInfo);      //去光标
  top();
  while (!Esc){
    if (_kbhit()) {//键盘按了键_kbhit()会变为1(监控键盘)
      system("cls");
      logical();
      top();
    }
  }
  printf("\n%d",Esc);
}