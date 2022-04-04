#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
int Hang, Line, All, Num, i, *b,*t,Esc=0,Lei;
int Mine[999] = {0}/*地雷图，大于8为雷*/, Top[999] = {0};//顶层图 比地雷图小一圈
int overborder() {  //越界判断 1为越界，0为未越界(地雷图的最外一圈)
  return ((b - Mine) % (Line + 2) != 0 &&      //右边界
          (b - Mine + 1) % (Line + 2) != 0 &&  //左边界
          b - Mine <= All - Line - 2 &&        //下边界
          b - Mine >= Line + 2);               //上边界
}
void LinkFind(){
  
}
void buttom() {  //生成地雷  Mine里大于9为雷
  srand((unsigned int)time(NULL));//随机种子
  do {b = Mine + rand() % All + 1;//使b指向Mine中的随机格子
    if(!(overborder() && *b < 9))continue;//去除越界且重复的
    *b = 9;++*(b + 1);++*(b - 1);//将b指的格子赋值9且左右俩边加上1
    for (i = 0; i < 3; i++, ++*(b + Line + i), ++*(b - Line - i));//将b指的格子上下3格加上1
    Num--;} while (Num > 0);
}
void start() {//初始化参数
  int t;
  Hang = 10;//行数
  Line = 10;//列数
  Num = Lei = 10;//雷数
  All = (Hang + 2) * (Line + 2);//辅助数 Mine全格子数量
  buttom();//生成雷
}

void logical() {
  int ch = _getch();//每次循环只用获取一次按键值
  if (*t == 1) --*t;//删除拖尾
  if (ch == 27)Esc=2;                                        // ESC
  if (ch == 119 && t - Line > Top - 1) t -= Line;            //上
  if (ch == 115 && t + Line < Top + Hang * Line) t += Line;  //下
  if (ch == 100 && t + 1 < Top + Hang * Line) t++;           //右
  if (ch == 97 && t > Top) t--;                              //左
  if (*t == 0) ++*t;//将当前指着的格子变为被选中状态
  if (ch == 101)if (*t > 0 && *t < 3)++*t;else *t = 0;       // E
  if (ch == 102) *t = -1;                                    // F
}

void maker(int color,char C,int num){//if(t!=Top+i)用来检查被选中状态
  if(C=='\t')
    if(t!=Top+i)printf(" %d ",num);
    else printf("\033[1;%d;40m>%d<\033[0m",color,num);
  else
    if(t!=Top+i)printf("\033[1;%d;40m %c \033[0m",color,C);
    else printf("\033[1;%d;40m>%c<\033[0m",color,C);
}
void top(){//顶层 负责打印与统计
  for (b=Mine,i=0,Num=Hang*Line-Lei; b-Mine < All;b++){//遍历数组Mine同时对应上数组Top
    if (!overborder()) continue;//通过continue将越界指针b的去除,使得i与没越界的指针b对应，Top与Mine对应
    if (*b > 8 && Top[i] < 0) Esc = -1;//翻开地雷结束游戏
    if (*b < 9 && Top[i] < 0) Num--;//同时满足Mine不为雷且Top翻开的格子数减到0则胜利
    if (i % Line == 0) printf("\n");//Line格换一行
    switch (Top[i]){//Top[i]的值
      case 0:printf("[ ]");break;//草地
      case 1:maker(36,' ',0);break;//被选中
      case 2:maker(33,'#',0);break;//标记雷
      case 3:maker(36,'?',0);break;//标记问号
      case -1://已翻开的草地(透视到底层Mine图)
        if(*b>8)maker(31,'@',0);
        else maker(36,'\t',*b);
        break;
    }
    i++;
  }
  if(Num==0)Esc=1;
}

int main() {
  start();
  HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//去光标
  CONSOLE_CURSOR_INFO CursorInfo;
  GetConsoleCursorInfo(handle, &CursorInfo);
  CursorInfo.bVisible = FALSE;
  SetConsoleCursorInfo(handle, &CursorInfo);      //去光标
  t = Top;++*t;
  top();
  while (!Esc){
    if (_kbhit()) {//键盘按了键_kbhit()会变为1(监控键盘)
      system("cls");
      logical();
      top();
    }
  }
}