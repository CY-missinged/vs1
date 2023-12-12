#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct Node
{
    DataType data;     /* 存储结点数据 */
    struct Node *next; /* 指向下一个结点的指针 */
} LNode, *LinkList;

void CreateListR(LinkList *head) /*尾插法,注意形参用二级指针*/
{
    int i, n;
    LinkList p;
    *head = (LinkList)malloc(sizeof(LNode)); /*申请头结点*/
    p = *head;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        p->next = (LinkList)malloc(sizeof(LNode)); /*申请新结点空间*/
        p = p->next;                               /*指针P移向新结点*/
        scanf("%d", &p->data);                     /*输入元素到p的数据域中*/
    }
    p->next = NULL; /*单链表尾结点的指针域要置为空*/
}

void display(LNode *head)
{
    LNode *p;
    if (p = NULL)
        return;
    p = head->next;
    while (p)
    {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

void K_Reverse(LinkList head, int k)
{
    int x, y1, y, i = 1, t, t1, j, a[10000];
    while (head->next != NULL)
    {
        head = head->next;
        a[i] = head->data;
        i++;
    }
    i--;
    x = i % k;
    y = i / k;
    for (y1 = 1; y1 <= y; y1++)
    {
        t1 = k * y1;
        for (t = k; t > 0; t--)
        {
            printf("%4d", a[t1]);
            t1--;
        }
    }
    if (x != 0)
    {
        for (t = x; t > 0; t--)
        {
            t1 = y * k;
            printf("%4d", a[t1 + t]);
        }
    }
}

int main()
{
    LinkList head;
    int k;
    CreateListR(&head);
    if (head->next == NULL)
        return 0;
    // display(head);
    scanf("%d", &k);
    K_Reverse(head, k);
    return 0;
}
