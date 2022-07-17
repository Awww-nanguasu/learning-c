#include"Stack.cpp"
void TestStackInit(Stack* SK){
    StackInit(SK);
}
void TestStackEmpty(Stack* SK){
    if (StackEmpty(SK))
    {
        printf("Õ»Îª¿Õ\n");
    }
    else{
        printf("Õ»²»Îª¿Õ\n");
    }
}
void TestStackPush(Stack* SK){
    StackPush(SK,1);
    StackPush(SK,2);
    StackPush(SK,3);
    StackPush(SK,4);
    StackPush(SK,5);

}
void TestStackPop(Stack* SK){
    StackPop(SK);
}
int main(){
    Stack SK;
    TestStackInit(&SK);
    TestStackEmpty(&SK);
    TestStackPush(&SK);
    while (!StackEmpty(&SK))
    {
        printf("capacity:%d Top:%d Data:%d\n",SK.Capacity,SK.Top,StackTop(&SK));
        StackPop(&SK);
    }
    StackDestory(&SK);
    return 0;
}