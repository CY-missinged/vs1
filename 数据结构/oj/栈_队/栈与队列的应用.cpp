// 功能：对于一个已知的一个表达式字符串，函数功能功能检验其左右括号是否匹配。如果匹配则返回一个1否则返回0。
// 要求对于表达式中出现的三种括号（圆括号（）、方括号[ ]、大括号{ }）进行匹配检查。请完善下列程序代码中的int  Match(char  *str) 函数。

#include <stdio.h>
#include <string.h>
#define STACKSIZE 5

typedef char DataType;

typedef struct
{
    DataType data[STACKSIZE];
    int top;
} SeqStack;

//初始化为空栈
void InitStack(SeqStack *s)
{
    s->top = -1; //置空栈
}

//判断栈s是否为空，为空返回1，否则返回0
int StackEmpty(SeqStack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

//将元素x压入栈s中，正常入栈返回1，否则返回0
int Push(SeqStack *s, DataType x)
{
    if (s->top == STACKSIZE - 1) //栈满，不能入栈
    {
        printf("栈已满！\n");
        return 0; //入栈失败
    }
    else
    {
        s->top++;            //栈顶位置加1
        s->data[s->top] = x; // x入栈
        return 1;            //入栈成功
    }
}

//将栈s的栈顶出栈，并通过指针变量x将顶栈元素返回，正常出栈返回1，否则返回0
int Pop(SeqStack *s, DataType *x)
{
    if (s->top == -1)
    {
        printf("栈已空！\n");
        return 0; //栈空，不能出栈
    }
    else
    {
        *x = s->data[s->top]; //栈顶元素保存在*x中
        s->top--;             //栈顶位置减1
        return 1;             //出栈成功
    }
}

//读取栈顶元素，并通过参数x返回其值
int GetTop(SeqStack *s, DataType *x)
{
    if (s->top == -1)
    {
        printf("栈已空！\n");
        return 0; //栈空，读取失败
    }
    else
    {
        *x = s->data[s->top]; //栈顶元素保存在*x中，此时栈顶并不出栈
        return 1;             //读取成功
    }
}

int Match(char *str)
{
    int i, l = strlen(str);
    SeqStack a;
    SeqStack *stack = &a;
    InitStack(stack);
    char *s = str, t;
    for (i = 0; i < l; i++)
    {
        if ((s[i] == ')' || s[i] == ']' || s[i] == '}') && StackEmpty(stack))
            return 0;
        if (s[i] == '(')
            Push(stack, s[i]);
        else if (s[i] == ')')
        {
            GetTop(stack, &t);
            if (t == '(')
                Pop(stack, &t);
            else
                return 0;
        }
        if (s[i] == '[')
            Push(stack, s[i]);
        else if (s[i] == ']')
        {
            GetTop(stack, &t);
            if (t == '[')
                Pop(stack, &t);
            else
                return 0;
        }
        if (s[i] == '{')
            Push(stack, s[i]);
        else if (s[i] == '}')
        {
            GetTop(stack, &t);
            if (t == '{')
                Pop(stack, &t);
            else
                return 0;
        }
    }
    if (!StackEmpty(stack))
    {
        return 0;
    }
    else
    {
        return 1;
    }
} // Match结束

int main()
{
    char str[100];
    gets(str);
    printf("%d\n", Match(str));
    return 0;
}
