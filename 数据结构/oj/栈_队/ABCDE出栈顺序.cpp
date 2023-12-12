#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

typedef char DataType;

typedef struct
{
    DataType data[MAXSIZE];
    int top;
} SeqStack;

SeqStack *InitStack() //初始化栈s，置为空栈
{
    SeqStack *s;
    s = (SeqStack *)malloc(sizeof(SeqStack));
    s->top = -1;
    return s;
}

int StackEmpty(SeqStack *s)
{ //判断s是否为空栈，若为空栈，返回1，否则返回0
    return s->top == -1;
}

int Push(SeqStack *s, DataType x)
{
    if (s->top == MAXSIZE - 1) //栈满
    {
        printf("栈已满!\n");
        return 0; //入栈失败返回0
    }
    s->top++;            //栈顶指针增加1
    s->data[s->top] = x; //将新元素赋值给栈顶空间
    return 1;            //入栈成功返回1
}

int Pop(SeqStack *s, DataType *px)
{
    if (StackEmpty(s))
    {
        printf("p栈空!\n");
        return 0; //出栈失败返回0
    }
    *px = s->data[s->top]; // 将栈顶元素赋值给px指向的变量
    s->top--;              // 栈顶指针减1
    return 1;              //出栈成功返回1
}

int GetTop(SeqStack *s, DataType *px)
{
    if (StackEmpty(s))
    {
        // printf("G栈空!\n");
        return 0; //读取栈顶元素失败返回0
    }
    *px = s->data[s->top]; // 将栈顶元素赋值给px指向的变量
    return 1;              //读栈顶元素成功返回1
}

int JudgeSerial(char str[], int n)
{                              //若长度为n的字符序列str对应的是正确的出栈序列，返回1；否则返回0
    SeqStack *s;               // s为顺序栈指针
    char x;                    // x用于保存出栈元素或读取的栈顶元素
    char c[MAXSIZE] = "ABCDE"; // c用于保存进栈的字符序列
    int i = 0, j = 0;          // i,j分别用于控制在字符序列c和str中的当前扫描位置
    //依次扫描c和str中的字符，比较栈顶元素x和str当前字符的值
    //若两者不相等，则将c当前字符进栈并后移c中当前字符位置
    //若两者相等，则出栈并后移str当前字符位置
    s = InitStack();
    Push(s, c[i]);
    printf("%c进栈\n", c[i]);
    for (i = 1, j = 0; i < 5, j < n;)
    {
        // printf("i:%d,j:%d\n", i, j);
        if (i > 5 || j > 5)
            break;
        if (GetTop(s, &x) == 0)
        {
            if (i >= 5)
            {
                break;
            }
            Push(s, c[i]);
            printf("%c进栈\n", c[i]);
            i++;
            continue;
        }
        GetTop(s, &x);
        if (x == str[j])
        {
            Pop(s, &x);
            printf("%c出栈\n", x);
            j++;
        }
        else
        {
                        if (i >= 5)
            {
                break;
            }
            Push(s, c[i]);
            printf("%c进栈\n", c[i]);
            i++;
        }
        // system("pause");
    }
    if (StackEmpty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    //扫描结束时，若所有str中的字符均顺利出栈，则说明其为正确的出栈序列
}

int main()
{
    char str[MAXSIZE];
    int n = 5;
    //输入待判断的字符序列
    scanf("%s", str);
    if (JudgeSerial(str, n))
        printf("%s是一个正确的出栈序列\n", str);
    else
        printf("%s不是一个正确的出栈序列\n", str);
    return 0;
}
