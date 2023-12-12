#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef struct LNODE
{
    DataType data;      /*data���������ڴ�Ž�������ֵ*/
    struct LNODE *next; /*next����������һ������ָ��*/
} LNODE;

LNODE *initl()
{
    LNODE *head;
    head = (LNODE *)malloc(sizeof(LNODE)); /*Ϊͷ�������ռ�*/
    if (head != NULL)                      /*��ͷ����ָ�����ʼ��ΪNULL*/
        head->next = NULL;
    return (head);
}

LNODE *creatL1() /*����һ��ͷΪhead�Ĵ�ͷ���ĵ�����*/
{
    LNODE *head, *p, *s;
    DataType x;
    head = initl(); /*�����ʼ��*/
    p = head;
    scanf("%d", &x);
    while (x != -1)
    {
        s = (LNODE *)malloc(sizeof(LNODE)); /*�����½��ռ�*/
        s->data = x;                        /*���½���������ֵ*/
        s->next = NULL;                     /*���½���ָ�����ʼ��Ϊ��*/
        p->next = s;                        /*���½�����ӵ���β*/
        p = s;                              /*�½���Ϊ�������β���*/
        scanf("%d", &x);
    }
    return head;
}

void output(LNODE *head) /*����ڵ�����*/
{
    LNODE *p;
    p = head->next;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

/*���º����������ϲ�������������Ϊһ����������*/
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
    printf("�ϲ��������Ϊ��\n");
    output(x);
    return 0;
}
