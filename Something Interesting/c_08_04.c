#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#define Max_size 10
typedef struct Stack
{
    double* Data;
    int Capacity;
    int Top;
}Stack;
void InitStack(Stack* stack){
    stack->Capacity=4;
    stack->Data=(double*)malloc(stack->Capacity);
    stack->Top=0;
}
void CheckCapacity(Stack* stack){
    if (stack->Top==stack->Capacity)
    {
        stack->Capacity*=2;
        stack->Data=(double*)realloc(stack->Data,stack->Capacity);
    }
}
void CreatNewNode(Stack* stack){
    CheckCapacity(stack);

}
bool StackEmpty(Stack stack){
    return stack.Top==0;
}
void StackPush(Stack* stack,double num){
    CheckCapacity(stack);
    stack->Data[stack->Top]=num;
    (stack->Top)++;
}
void StackPop(Stack* stack){
    if (!(StackEmpty(*stack)))
    {
        stack->Top--;
    }
}
double GetTop(Stack* stack){
    if (!StackEmpty(*stack))
    {
        return stack->Data[stack->Top-1];
    }    
}
void Action(Stack* stack,char Input ){
    double act1=0,act2=0;
    act1=GetTop(stack);
    StackPop(stack);
    act2=GetTop(stack);
    StackPop(stack);
    switch (Input)
    {
    case '+':
        StackPush(stack,act2+act1);
        break;
    case '-':
        StackPush(stack,act2-act1);
        break;
    case '*':
        StackPush(stack,act2*act1);
        break;
    case '/':
        StackPush(stack,act2/act1);
        break;
    default:
        printf("表达式不合法\n");
        exit(-1);
        break;
    } 
}
int main(){
    int i=0;
    double k=0;
    Stack stack;
    InitStack(&stack);
    char Input;
    char Num[Max_size];
    printf("请按逆波兰方式输入数学表达式,表达式以#结尾:");
    scanf("%c",&Input);
    while (Input!='#')
    {
        if (Input==' ')
        {
            if (i!=0)
            {
                k=atof(Num);
                StackPush(&stack,k);
                i=0;
            }
        }
        else if (isdigit(Input) || Input=='.')
        {
            Num[i++]=Input;
            Num[i]='\0'; 
        }
        else{
            Action(&stack,Input);
        }
        scanf("%c",&Input);
    }
    printf("Data:%lf ",stack.Data[stack.Top-1]);
}
