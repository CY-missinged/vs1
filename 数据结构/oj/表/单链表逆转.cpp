#include <stdio.h>
#include <stdlib.h>
typedef int DataType;
typedef struct Node
{
    DataType data;     /* �洢������� */
    struct Node *next; /* ָ����һ������ָ�� */
} LNode, *LinkList;

void CreateListR(LinkList *head) /*β�巨,ע���β��ö���ָ��*/
{
    int i, n;
    LinkList p;
    *head = (LinkList)malloc(sizeof(LNode)); /*����ͷ���*/
    p = *head;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        p->next = (LinkList)malloc(sizeof(LNode)); /*�����½��ռ�*/
        p = p->next;                               /*ָ��P�����½��*/
        scanf("%d", &p->data);                     /*����Ԫ�ص�p����������*/
    }
    p->next = NULL; /*������β����ָ����Ҫ��Ϊ��*/
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
