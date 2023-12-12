#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct LNODE
{
    DataType data;      /*data数据项用于存放结点的数据值*/
    struct LNODE *next; /*next数据项存放下一个结点的指针*/
} LNODE;

LNODE *initl()
{
    LNODE *head;
    head = (LNODE *)malloc(sizeof(LNODE)); /*为头结点申请空间*/
    if (head != NULL)                      /*将头结点的指针域初始化为NULL*/
        head->next = NULL;
    return (head);
}

LNODE *creatL1() /*建立一个头为head的带头结点的单链表*/
{
    LNODE *head, *p, *s;
    DataType x;
    head = initl(); /*链表初始化*/
    p = head;
    scanf("%d", &x);
    while (x != -1)
    {
        s = (LNODE *)malloc(sizeof(LNODE)); /*申请新结点空间*/
        s->data = x;                        /*给新结点的数据域赋值*/
        s->next = NULL;                     /*将新结点的指针域初始化为空*/
        p->next = s;                        /*将新结点链接到表尾*/
        p = s;                              /*新结点成为新链表的尾结点*/
        scanf("%d", &x);
    }
    return head;
}

void output(LNODE *head) /*输出节点数据*/
{
    LNODE *p;
    p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

/*以下函数完成升序合并两个升序单链表为一个升序单链表*/
LNODE *Ascendingmerge(LNODE *head1, LNODE *head2)
{
    if (head1->next == NULL)
    {
        return head2;
    }
    if (head2->next == NULL)
    {
        return head1;
    }
    LNODE *pleft = head1, *pright = head1->next, *q = head2->next;
    int judge = 1;
    while (1)
    {
        if (pright->next == NULL && pright->data <= q->data)
        {
            pright->next = q;
            break;
        }
        if (pright->data > q->data)
        {
            pleft->next = q;
            if (q->next == NULL)
            {
                judge = 0;
            }
            else
            {
                q = q->next;
            }
            pleft = pleft->next;
            pleft->next = pright;
        }
        else
        {
            pright = pright->next;
            pleft = pleft->next;
        }
        if (judge == 0)
            break;
    }
    return head1;
}

int main()
{
    LNODE *head1, *head2, *x;
    head1 = creatL1();
    head2 = creatL1();
    x = Ascendingmerge(head1, head2);
    printf("合并后的数据为：\n");
    output(x);
    return 0;
}
