// encoding=GBK

//˳��ջ�Ķ��弰��������
#include <stdio.h>
#include <stdlib.h>

//������������
typedef int DataType;

//����ջ������ڴ�
#define STACKSIZE 100

//����ջ
typedef struct
{
    DataType data[STACKSIZE];
    int top;
} SeqStack;

//�ÿ�ջ����s��ָջ��Ϊ��ջ
void InitStack(SeqStack *s)
{
    s->top = -1;
}

//�ж�ջ�Ƿ�Ϊ�գ��շ���1�����򷵻�0
int StackEmpty(SeqStack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

//��ջ,��x��ջ���ɹ�����1�����򷵻�0
int Push(SeqStack *s, DataType x)
{
    if (s->top == STACKSIZE - 1)
    {
        printf("ջ������\n");
        return 0;
    }
    else
    {
        s->top++;
        s->data[s->top] = x;
        return 1;
    }
}

//��ջ����s��ָջ��ջ��Ԫ�س�ջ����ͨ��ָ�����x���س�ջԪ�أ��ɹ�����1�����򷵻�0
int Pop(SeqStack *s, DataType *x)
{
    if (s->top == -1)
    {
        printf("ջ�ѿգ�\n");
        return 0;
    }
    else
    {
        *x = s->data[s->top];
        s->top--;
        return 1;
    }
}

//��ջ��Ԫ�أ�ֻ������ջ,�ɹ�����1����෵��0
int GetTop(SeqStack *s,DataType *x)
{
    if(s->top==-1)
    {
        printf("ջ�ѿգ�\n");
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
