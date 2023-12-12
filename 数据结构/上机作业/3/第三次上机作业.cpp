// GBK
//链表 将两个链表合成一个
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

LNode *Creatlink() //尾插法
{
    LNode *head, *p;
    DataType x;
    int uesr_num, i;
    head = InitLink();
    p = head;
    printf("请输入需要输入的数据个数:\n");
    scanf("%d", &uesr_num);
    for (i = 0; i < uesr_num; i++)
    {
        printf("请输入第%d个数据：\n", i + 1);
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
    printf("链表打印如下：\n");
    while (p->next != NULL)
    {
        p = p->next;
        printf("%d\n", p->data);
    }
}

LNode *lianjie_link(LNode *head1, LNode *head2)
{
    LNode *p = head1;
    while (1)
    {
        if (p->next == NULL)
        {
            p->next = head2->next;
            break;
        }
        else
        {
            p = p->next;
        }
    }
    return head1;
}

int main()
{
    LNode *head1, *head2, *p;
    int ch, i;
    printf("请输入第一个链表\n");
    head1 = Creatlink();
    printf("请输入第二个链表\n");
    head2 = Creatlink();
    p = lianjie_link(head1, head2);
    InputList(p);
    return 0;
}
