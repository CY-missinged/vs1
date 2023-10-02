// GBK

#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

//����ջ������ڴ�
#define STACKSIZE 100

//������е�����ڴ�
#define QUEUESIZE 100

//����ջ
typedef struct
{
    DataType data[STACKSIZE];
    int top;
} SeqStack;

typedef struct
{
    DataType data[QUEUESIZE];
    int front; //��ͷ
    int rear;  //��β
    int count; //���������жϼ����
} SeqQueue;

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

//��ջ��Ԫ�أ�ͨ��x������ֵ���ɹ�����1�����򷵻�0
int GetTop(SeqStack *s, DataType *x)
{
    if (s->top == -1)
    {
        printf("ջ�ѿգ�\n");
        return 0;
    }
    else
    {
        *x = s->data[s->top];
        return 1;
    }
}

//�ÿն��У���q��ָ������Ϊ�ն���
void InitQueue(SeqQueue *q)
{
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

//�ж�q��ָ�����Ƿ�Ϊ�գ��շ���1�����򷵻�0
int QueueEmpty(SeqQueue *q)
{
    if (q->front == q->rear && q->count == 0)
        return 1;
    else
        return 0;
}

//��ӣ���x����q��ָ�Ķ����У��ɹ�����1�����򷵻�0
int EnQueue(SeqQueue *q, DataType x)
{
    if (q->count == QUEUESIZE)
    {
        printf("����������\n");
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

//���ӣ���q��ָ���еĶ�ͷԪ��ɾ������ͨ��ָ�����x���س���Ԫ�أ��ɹ�����1�����򷵻�0
int DeQueue(SeqQueue *q, DataType *x)
{
    if (q->front == q->rear && q->count == 0)
    {
        printf("�����ѿգ�\n");
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

//��ȡ��ͷԪ�أ�ͨ��x������ֵ���ɹ�����1�����򷵻�0
int GetQueue(SeqQueue *q, DataType *x)
{
    if (q->front == q->rear && q->count == 0)
    {
        printf("�����ѿգ�\n");
        return 0;
    }
    else
    {
        *x = q->data[q->front];
        return 1;
    }
}

//�˵�
void mean()
{
    printf("1�������������ת����ʮ����ʵ��\n");
    printf("2��������ת��Ϊ��������\n");
    printf("3��������ת��Ϊ�˽�����\n");
    printf("4��������ת��Ϊʮ��������\n");
    printf("0����������������\n");
}

void fun_jinzhi(double x, int r, SeqStack *s, SeqQueue *q)
{
    InitStack(s);
    InitQueue(q);
    int y, t, i = 0;
    int x1 = int(x);
    double x2 = x - x1;
    while (x1 != 0) //������������
    {
        y = x1 % r;
        x1 = x1 / r;
        Push(s, y);
    }
    while (x2 != 0 && i < 10) //����С������
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
