#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
    DataType data;     /* �洢������� */
    struct Node *next; /* ָ����һ������ָ�� */
} Node, *LinkList;

void CreateListR(LinkList *head);
void display(LinkList head);
void insert_List_Head(LinkList *L, int x);
void K_Reverse(LinkList *head, int k);
void CreateListR(LinkList *head) /*β�巨,ע���β��ö���ָ��*/
{
    int i, n;
    LinkList p;
    *head = (LinkList)malloc(sizeof(Node)); /*����ͷ���*/
    p = *head;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        p->next = (LinkList)malloc(sizeof(Node)); /*�����½��ռ�*/
        p = p->next;                              /*ָ��P�����½��*/
        scanf("%d", &p->data);                    /*����Ԫ�ص�p����������*/
    }
    p->next = NULL; /*������β����ָ����Ҫ��Ϊ��*/
}

void display(LinkList head)
{
    LinkList p;
    p = head->next;
    while (p)
    {
        printf("%4d", p->data);
        p = p->next;
    }
    printf("\n");
}

void insert_List_Head(LinkList *L, int x)
{
    LinkList p;
    p = (LinkList)malloc(sizeof(Node)); /*  �����½�� */
    p->data = x;
    p->next = (*L)->next;
    (*L)->next = p; /*  ���뵽��ͷ */
}

void K_Reverse(LinkList *head, int k)
{
    LinkList p = (*head)->next, p1 = p, p2 = *head, p3 = (*head)->next;
    p = p->next;
    while (p)
    {
        p = p2->next;
        p1 = p;
        p = p->next;
        for (int i = 1; i < k && p; i++)
        {
            insert_List_Head(&p2, p->data);
            p = p->next;
            p1->next = p;
        }
        p2 = p3;
        p3 = p3->next;
    }
}

int main()
{
    LinkList head;
    int k;
    CreateListR(&head);
    if (head->next == NULL)
        return 0;
    scanf("%d", &k);
    K_Reverse(&head, k);
    display(head);
    return 0;
}
