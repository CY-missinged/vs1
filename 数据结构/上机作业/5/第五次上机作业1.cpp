//利用顺序表进行交并集运算
// encoding=GBK

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int data[MAXSIZE];
    int len;
} SeqList;

//顺序表初始化
SeqList *Init_SeqList()
{
    SeqList *L;
    L = (SeqList *)malloc(sizeof(SeqList));
    L->len = 0; //空表的表长为0
    return L;
}

//输入
void Input_SeqList(SeqList *L)
{
    int m, i;
    printf("请输入需要输入的元素个数:\n");
    scanf("%d", &m);
    L->len = m;
    printf("请输入集合元素:\n");
    for (i = 1; i <= m; i++)
    {
        scanf("%d", &(L->data[i]));
    }
}

//输出
void Output_SeqList(SeqList *L)
{
    int i;
    for (i = 1; i <= L->len; i++)
    {
        if (i == L->len)
        {
            printf("%d\n", L->data[i]);
        }
        else
        {
            printf("%d ", L->data[i]);
        }
    }
}

//按值查找,找到返回1，否侧返回0
int Find_SeqList(SeqList *L, int x)
{
    int i = 1;
    while (i <= L->len && L->data[i] != x)
        i++;
    if (i > L->len)
        return 0;
    else
        return 1;
}

//求A与B的交集
void jiaoji_SeqList(SeqList *A, SeqList *B, SeqList *C)
{
    int i;
    for (i = 1; i <= A->len; i++)
    {
        if (Find_SeqList(B, A->data[i]) == 1)
        {
            C->len++;
            C->data[C->len] = A->data[i];
        }
    }
}

//求A与B的并集
void bingji_SeqList(SeqList *A, SeqList *B, SeqList *C)
{
    int i;
    for (i = 1; i <= A->len; i++)
    {
        C->data[i] = A->data[i];
    }
    C->len = A->len;
    for (i = 1; i <= B->len; i++)
    {
        if (Find_SeqList(C, B->data[i]) == 0)
        {
            C->len++;
            C->data[C->len] = B->data[i];
        }
    }
}

int main()
{
    SeqList *A, *B, *C;
    A = Init_SeqList();
    B = Init_SeqList();
    C = Init_SeqList();
    printf("请输入A集合:\n");
    Input_SeqList(A);
    printf("请输入B集合:\n");
    Input_SeqList(B);
    jiaoji_SeqList(A, B, C);
    printf("集合A与集合B的交集为:\n");
    Output_SeqList(C);
    C = Init_SeqList();
    bingji_SeqList(A, B, C);
    printf("集合A与集合B的并集为:\n");
    Output_SeqList(C);
    return 0;
}
