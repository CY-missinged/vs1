// ���ܣ�����һ����֪��һ�����ʽ�ַ������������ܹ��ܼ��������������Ƿ�ƥ�䡣���ƥ���򷵻�һ��1���򷵻�0��
// Ҫ����ڱ��ʽ�г��ֵ��������ţ�Բ���ţ�����������[ ]��������{ }������ƥ���顣���������г�������е�int  Match(char  *str) ������

#include <stdio.h>
#include <string.h>
#define STACKSIZE 5

typedef char DataType;

typedef struct
{
    DataType data[STACKSIZE];
    int top;
} SeqStack;

//��ʼ��Ϊ��ջ
void InitStack(SeqStack *s)
{
    s->top = -1; //�ÿ�ջ
}

//�ж�ջs�Ƿ�Ϊ�գ�Ϊ�շ���1�����򷵻�0
int StackEmpty(SeqStack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

//��Ԫ��xѹ��ջs�У�������ջ����1�����򷵻�0
int Push(SeqStack *s, DataType x)
{
    if (s->top == STACKSIZE - 1) //ջ����������ջ
    {
        printf("ջ������\n");
        return 0; //��ջʧ��
    }
    else
    {
        s->top++;            //ջ��λ�ü�1
        s->data[s->top] = x; // x��ջ
        return 1;            //��ջ�ɹ�
    }
}

//��ջs��ջ����ջ����ͨ��ָ�����x����ջԪ�ط��أ�������ջ����1�����򷵻�0
int Pop(SeqStack *s, DataType *x)
{
    if (s->top == -1)
    {
        printf("ջ�ѿգ�\n");
        return 0; //ջ�գ����ܳ�ջ
    }
    else
    {
        *x = s->data[s->top]; //ջ��Ԫ�ر�����*x��
        s->top--;             //ջ��λ�ü�1
        return 1;             //��ջ�ɹ�
    }
}

//��ȡջ��Ԫ�أ���ͨ������x������ֵ
int GetTop(SeqStack *s, DataType *x)
{
    if (s->top == -1)
    {
        printf("ջ�ѿգ�\n");
        return 0; //ջ�գ���ȡʧ��
    }
    else
    {
        *x = s->data[s->top]; //ջ��Ԫ�ر�����*x�У���ʱջ��������ջ
        return 1;             //��ȡ�ɹ�
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
} // Match����

int main()
{
    char str[100];
    gets(str);
    printf("%d\n", Match(str));
    return 0;
}
