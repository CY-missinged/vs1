// GBK
//���� ��������������ϳ�һ������������

#include <stdio.h>
#include <stdlib.h>

struct DataType
{
    int num;
};

struct LNode
{
    DataType data;
    LNode *next;
};

LNode *InitLink()
{
    LNode *head;
    head = (LNode *)malloc(sizeof(LNode));
    if (head != NULL)
        head->next = NULL;
    return head;
}

LNode *Creatlink() //β�巨
{
    LNode *head, *p;
    DataType x;
    int uesr_num, i;
    head = InitLink();
    p = head;
    printf("��������Ҫ��������ݸ���:\n");
    scanf("%d", &uesr_num);
    for (i = 0; i < uesr_num; i++)
    {
        printf("�������%d�����ݣ�\n", i + 1);
        scanf("%d", &x.num);
        p->next = (LNode *)malloc(sizeof(LNode));
        p = p->next;
        p->data = x;
    }
    p->next = NULL;
    return head;
}

void InputList(LNode *head)
{
    LNode *p = head;
    printf("�����ӡ���£�\n");
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d\n", p->data);
    }
}

LNode *paixu_link(LNode *head1, LNode *head2)
{
    LNode *pleft = head1, *pright = head1->next, *q = head2->next;
    int judge = 1;
    while (1)
    {
        if (pright->next == NULL && pright->data.num <= q->data.num)
        {
            pright->next = q;
            break;
        }
        if (pright->data.num > q->data.num)
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
    LNode *head1, *head2, *p;
    printf("�������һ������\n");
    head1 = Creatlink();
    printf("������ڶ�������\n");
    head2 = Creatlink();
    p = paixu_link(head1, head2);
    InputList(p);
    return 0;
}
