#include <stdio.h>

#define MAXLEN 100

typedef struct
{
    int list[MAXLEN];
    int length;
} SeqList;

void out(SeqList *L);

void BubbleSort(SeqList *L);

int main()
{
    int i;
    SeqList a;
    scanf("%d", &a.length);
    for (i = 1; i <= a.length; i++)
        scanf("%d", &a.list[i]);
    BubbleSort(&a);
    return 0;
}

void BubbleSort(SeqList *L)
{
    int i, j, t, flag;
    flag = 0;
    for (j = 1; j < L->length; j++)
    {
        for (i = L->length; i > 1; i--)
        {
            if (L->list[i] > L->list[i - 1])
            {
                flag = 1;
                t = L->list[i];
                L->list[i] = L->list[i - 1];
                L->list[i - 1] = t;
            }
        }
        out(L);
        if (flag == 0)
            break;
        flag = 0;
    }
}

void out(SeqList *L)
{
    int i, j;
    for (i = 1; i <= L->length; i++)
    {
        printf("%d ", L->list[i]);
    }
    printf("\n");
}
