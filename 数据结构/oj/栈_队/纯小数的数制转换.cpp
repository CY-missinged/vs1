
#include <stdio.h>

#define DataType int
#define MAXSIZE1 20

typedef struct
{
    DataType data[MAXSIZE1];
    int front, rear;
} SeqQueue;

//��ʼ������
void InitQueue(SeqQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

//����
int DeleteQueue(SeqQueue *q, DataType *x)
{
    if (q->front == q->rear)
    {
        printf(" ������Ϊ�գ���Ԫ�ؿ�ȡ\n");
        return 0;
    }
    else
    {
        q->front++;
        *x = q->data[q->front];
        return 1;
    }
}

//����
int EnterQueue(SeqQueue *q, DataType x)
{
    if (q->rear >= MAXSIZE1)
    {
        printf("�����������ܲ���Ԫ��\n");
        return 0;
    }
    else
    {
        q->rear++;
        q->data[q->rear] = x;
        return 1;
    }
}

//ȡ����Ԫ��
int getfront(SeqQueue *q, DataType *x)
{
    if (q->front == q->rear)
    {
        return 0;
    }
    else
    {
        *x = q->data[q->front + 1];
        return 1;
    }
}

//��ʮ���ƴ�С��ת��Ϊr���ƵĴ�С������ౣ��nλС��
void NumConve(float x, int r, int n) // r=2 8 16
{

    SeqQueue Q;
    SeqQueue *q = &Q;
    int i,y,t;
    printf("0.");
    InitQueue(q);
    i=1;
    while (x != 0 && i <= n)
    {
        x = x * r;
        y = x;
        x = x - y;
        EnterQueue(q, y);
        i++;
    }
    i=1;
    while (getfront(q,&t) != 0&&i<=n)
    {
        i++;
        DeleteQueue(q, &t);
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
}

int main()
{
    float x;
    int r, n;
    scanf("%f", &x); //��������ת���Ĵ�ʮ����С��
    if (x >= 1.0f)
        printf("data error\n");
    else
    {
        scanf("%d", &r); //��������ת���Ľ���(2,8,16)
        scanf("%d", &n); //�������뱣������С��λ��
        NumConve(x, r, n);
        printf("\n");
    }
    return 0;
}
