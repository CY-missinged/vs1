// GBK

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

//定义栈的最大内存
#define STACKSIZE 100

//定义队列的最大内存
#define QUEUESIZE 100

//定义栈
typedef struct
{
    DataType data[STACKSIZE];
    int top;
} SeqStack;

typedef struct
{
    DataType data[QUEUESIZE];
    int front; //队头
    int rear;  //队尾
    int count; //计数器，判断假溢出
} SeqQueue;

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

//读栈顶元素，通过x返回其值，成功返回1，否则返回0
int GetTop(SeqStack *s, DataType *x)
{
    if (s->top == -1)
    {
        printf("栈已空！\n");
        return 0;
    }
    else
    {
        *x = s->data[s->top];
        return 1;
    }
}

//置空队列，将q所指队列置为空队列
void InitQueue(SeqQueue *q)
{
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

//判断q所指队列是否为空，空返回1，否则返回0
int QueueEmpty(SeqQueue *q)
{
    if (q->front == q->rear && q->count == 0)
        return 1;
    else
        return 0;
}

//入队，将x插入q所指的队列中，成功返回1，否则返回0
int EnQueue(SeqQueue *q, DataType x)
{
    if (q->count == QUEUESIZE)
    {
        printf("队列已满！\n");
        return 0;
    }
    else
    {
        q->data[q->rear] = x;
        q->rear = (q->rear + 1) % QUEUESIZE;
        q->count++;
        return 1;
    }
}

//出队，将q所指队列的队头元素删除，并通过指针变量x返回出队元素，成功返回1，否则返回0
int DeQueue(SeqQueue *q, DataType *x)
{
    if (q->front == q->rear && q->count == 0)
    {
        printf("队列已空！\n");
        return 0;
    }
    else
    {
        *x = q->data[q->front];
        q->front = (q->front + 1) % QUEUESIZE;
        q->count--;
        return 1;
    }
}

//读取队头元素，通过x返回其值，成功返回1，否则返回0
int GetQueue(SeqQueue *q, DataType *x)
{
    if (q->front == q->rear && q->count == 0)
    {
        printf("队列已空！\n");
        return 0;
    }
    else
    {
        *x = q->data[q->front];
        return 1;
    }
}

//菜单
void mean()
{
    printf("1————输入待转换的十进制实数\n");
    printf("2————转换为二进制数\n");
    printf("3————转换为八进制数\n");
    printf("4————转换为十六进制数\n");
    printf("0————结束程序\n");
}

void fun_jinzhi(double x, int r, SeqStack *s, SeqQueue *q)
{
    InitStack(s);
    InitQueue(q);
    int y, t, i = 0;
    int x1 = int(x);
    double x2 = x - x1;
    while (x1 != 0) //计算整数部分
    {
        y = x1 % r;
        x1 = x1 / r;
        Push(s, y);
    }
    while (x2 != 0 && i < 10) //计算小数部分
    {
        x2 = x2 * r;
        y = int(x2);
        x2 = x2 - y;
        EnQueue(q, y);
        i++;
    }
    while (StackEmpty(s) != 1)
    {
        Pop(s, &t);
        if (r == 16)
        {
            switch (t)
            {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d", t);
                break;
            }
        }
        else
            printf("%d", t);
    }
    printf(".");
    if(QueueEmpty(q) == 1)
    printf("0");
    while (QueueEmpty(q) == 0)
    {
        DeQueue(q, &t);
        if (r == 16)
        {
            switch (t)
            {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d", t);
                break;
            }
        }
        else
            printf("%d", t);
    }
    printf("\n");
}

int main()
{
    SeqStack s1;
    SeqStack *s = &s1;
    InitStack(s);
    SeqQueue q1;
    SeqQueue *q = &q1;
    InitQueue(q);
    int a,b;
    double x;
    do
    {
        mean();
        scanf("%d", &a);
        switch (a)
        {
        case 0:
            break;
        case 1:
            scanf("%lf", &x);
            break;
        case 2:
            fun_jinzhi(x, 2, s, q);
            break;
        case 3:
            fun_jinzhi(x, 8, s, q);
            break;
        case 4:
            fun_jinzhi(x, 16, s, q);
            break;
        }
        system("pause");
        system("cls");
    } while (a != 0);
    return 0;
}
