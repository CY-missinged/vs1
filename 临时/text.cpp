// encoding=GBK

//顺序栈的定义及基本运算
#include <stdio.h>
#include <stdlib.h>

//定义数据类型
typedef int DataType;

//定义栈的最大内存
#define STACKSIZE 100

//定义栈
typedef struct
{
    DataType data[STACKSIZE];
    int top;
} SeqStack;

//置空栈，将s所指栈置为空栈
void InitStack(SeqStack *s)
{
    s->top = -1;
}

//判断栈是否为空，空返回1，否则返回0
int StackEmpty(SeqStack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

//入栈,将x入栈，成功返回1，否则返回0
int Push(SeqStack *s, DataType x)
{
    if (s->top == STACKSIZE - 1)
    {
        printf("栈已满！\n");
        return 0;
    }
    else
    {
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}

//出栈，将s所指栈的栈顶元素出栈，并通过指针变量x返回出栈元素，成功返回1，否则返回0
int Pop(SeqStack *s, DataType *x)
{
    if (s->top == -1)
    {
        printf("栈已空！\n");
        return 0;
    }
    else
    {
        *x = s->data[s->top];
        s->top--;
        return 1;
    }
}

//读栈顶元素，只读不出栈,成功返回1，否侧返回0
int GetTop(SeqStack *s,DataType *x)
{
    if(s->top==-1)
    {
        printf("栈已空！\n");
        return 0;
    }
    else
    {
        *x=s->data[s->top];
        return 1;
    }
}

int main()
{
    SeqStack s1;
    SeqStack *s = &s1;
    InitStack(s);
    return 0;
}
