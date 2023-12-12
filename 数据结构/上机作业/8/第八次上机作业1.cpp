// gbk
//编写完整程序在按照主关键字降序排列的顺序表上分别实现顺序查找和折半查找

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef struct
{
    int key;
} DataType;

typedef struct
{
    DataType list[MAXSIZE + 1];
    int len;
} SeqList;

//初始化
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
        scanf("%d", &(L->list[i].key));
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
            printf("%d\n", L->list[i].key);
        }
        else
        {
            printf("%d ", L->list[i].key);
        }
    }
}

//比较函数
int compare(const void *s1, const void *s2)
{
    return -((*(SeqList *)s1).list->key - (*(SeqList *)s2).list->key);
}

//顺序查找
void shunxu_search(SeqList *L, int x)
{
    int i;
    for (i = 1; i <= L->len; i++)
    {
        if (i == L->len)
        {
            if (L->list[i].key != x)
                printf("未查找到该关键字!\n");
            else
            {
                printf("已查找到该关键字，位于第%d位\n", i);
                break;
            }
        }
        else
        {
            if (L->list[i].key == x)
            {
                printf("已查找到该关键字，位于第%d位\n", i);
                break;
            }
        }
    }
}

//折半查找
void half_search(SeqList *L, int x)
{
    int j = 1;
    int left, right, i = 0, flag = 0;
    for (j = 1, left = 1, right = L->len; j < 10; j++)
    {
        if (left == right)
        {
            if (x == L->list[i].key)
            {
                printf("已查找到该关键字，位于第%d位\n", i);
                flag = 1;
                break;
            }
            break;
        }
        i = (left + right) / 2;
        if (x == L->list[i].key)
        {
            printf("已查找到该关键字，位于第%d位\n", i);
            flag = 1;
            break;
        }
        else if (x > L->list[i].key)
        {
            right = i;
        }
        else
        {
            left = i;
        }
    }
    if (flag == 0)
    {
        printf("未查找到该关键字!\n");
    }
}

int main()
{
    int x;
    SeqList *L;
    L = Init_SeqList();
    Input_SeqList(L);
    qsort(L->list, L->len + 1, sizeof(L->list[1].key), compare);
    printf("降序排列为:\n");
    Output_SeqList(L);
    printf("请输入需要查找的关键字:");
    scanf("%d", &x);
    printf("顺序查找结果为:\n");
    shunxu_search(L, x);
    printf("折半查找结果为:\n");
    half_search(L, x);
    return 0;
}
