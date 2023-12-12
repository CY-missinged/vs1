
#include <stdio.h>

#define DataType int
#define MAXSIZE1 20

typedef struct
{
    DataType data[MAXSIZE1];
    int front, rear;
} SeqQueue;

//初始化队列
void InitQueue(SeqQueue *q)
{
    q->front = -1;
    q->rear = -1;
}

//出队
int DeleteQueue(SeqQueue *q, DataType *x)
{
    if (q->front == q->rear)
    {
        printf(" 队列已为空，无元素可取\n");
        return 0;
    }
    else
    {
        q->front++;
        *x = q->data[q->front];
        return 1;
    }
}

//进队
int EnterQueue(SeqQueue *q, DataType x)
{
    if (q->rear >= MAXSIZE1)
    {
        printf("队已满，不能插入元素\n");
        return 0;
    }
    else
    {
        q->rear++;
        q->data[q->rear] = x;
        return 1;
    }
}

//取队首元素
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

//将十进制纯小数转换为r进制的纯小数，最多保留n位小数
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
    scanf("%f", &x); //请输入想转换的纯十进制小数
    if (x >= 1.0f)
        printf("data error\n");
    else
    {
        scanf("%d", &r); //请输入想转换的进制(2,8,16)
        scanf("%d", &n); //请输入想保留最多的小数位数
        NumConve(x, r, n);
        printf("\n");
    }
    return 0;
}
