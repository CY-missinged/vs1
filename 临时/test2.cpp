#include <stdio.h>
#include <stdlib.h>

typedef int DataType;

typedef struct Node
{
    DataType data;     /* 存储结点数据 */
    struct Node *next; /* 指向下一个结点的指针 */
} Node, *LinkList;

void CreateListR(LinkList *head);
void display(LinkList head);
void insert_List_Head(LinkList *L, int x);
void K_Reverse(LinkList *head, int k);
void CreateListR(LinkList *head) /*尾插法,注意形参用二级指针*/
{
    int i, n;
    LinkList p;
    *head = (LinkList)malloc(sizeof(Node)); /*申请头结点*/
    p = *head;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        p->next = (LinkList)malloc(sizeof(Node)); /*申请新结点空间*/
        p = p->next;                              /*指针P移向新结点*/
        scanf("%d", &p->data);                    /*输入元素到p的数据域中*/
    }
    p->next = NULL; /*单链表尾结点的指针域要置为空*/
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
    p = (LinkList)malloc(sizeof(Node)); /*  生成新结点 */
    p->data = x;
    p->next = (*L)->next;
    (*L)->next = p; /*  插入到表头 */
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
