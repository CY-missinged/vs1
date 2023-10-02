// GBK

//试查找元素x在该顺序表升序排序后的位置

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef int DataType;
typedef struct
{
    DataType data[MAXSIZE];
    int len;
} SeqList;

SeqList *init()

{
    SeqList *L;
    L = (SeqList *)malloc(sizeof(SeqList));
    L->len = 0;
    return (L);
}

void input(SeqList *L)

{
    int i;
    scanf("%d", &L->len);
    for (i = 0; i < L->len; i++)
        scanf("%d", &L->data[i]);
}

int SearchX(SeqList *L, DataType x)
{
    int i, j, t;
    for (i = 0; i < L->len-1; i++)
    {
        for (j = i + 1; j < L->len; j++)
        {
            if (L->data[i] > L->data[j])
            {
                t = L->data[i];
                L->data[i] = L->data[j];
                L->data[j] = t;
            }
        }
    }
    i = L->len-1;
    while (i > -1 && L->data[i] != x)
        i--;
    return i+1;
}

int main()
{
    SeqList *L;
    DataType x;
    L = init();
    input(L);
    scanf("%d", &x);
    printf("%d\n", SearchX(L, x));
    return 0;
}
