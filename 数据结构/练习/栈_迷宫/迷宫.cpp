#include<stdio.h>

typedef int DataType;

#define STACKMAX 100

typedef struct
{
    DataType data[STACKMAX];
    int top;
}SeqStack;

void InitStack(SeqStack *s)
{
    s->top=-1;
}

int Push(SeqStack *s, DataType x)
{
    if (s->top == STACKMAX - 1)
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

int main()
{
    SeqStack s1;
    SeqStack *s=&s1;
    InitStack(s);
    int a[100][100],b[10000];
    int m,n,i,j;
    printf("�������Թ��Ĵ�С��\n");
    scanf("%d%d",&m,&n);
    printf("�������Թ��ĵ��Σ�\n");
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    return 0;
}
