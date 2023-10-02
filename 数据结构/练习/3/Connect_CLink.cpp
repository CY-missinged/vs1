//本程序的功能为：将两个循环单链表首尾相接合并为一个循环单链表
#include <stdio.h>
#include <stdlib.h>

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode;

typedef int DataType;
typedef int KeyType;

LNode *InitCLink();
LNode *CreateCLinkR();
void DisplayCLink(LNode *head);
LNode *ConnectCLink(LNode *ra, LNode *rb);

int main()
{
  LNode *ra, *rb; // ra和rb分别为两个循环单链表的尾指针
  int n;
  printf("建立第一个链表：\n");
  ra = CreateCLinkR();
  DisplayCLink(ra);
  printf("建立第二个链表：\n");
  rb = CreateCLinkR();
  DisplayCLink(rb);
  rb = ConnectCLink(ra, rb);
  printf("连接后的新链表：\n");
  DisplayCLink(rb);
  return 0;
}

LNode *InitCLink()
{
  LNode *head, *rear;
  head = (LNode *)malloc(sizeof(LNode));
  /*为头结点申请空间*/
  if (rear != NULL)
    head->next = head;
  rear = head;
  return (rear);
  /*将头结点的指针域初始化为NULL*/
}

LNode *CreateCLinkR()
/*建立一个头为head的带头结点的单链表*/
{
  LNode *head, *rear, *s;
  DataType x;
  head = InitCLink(); /*链表初始化*/
  rear = head;        /*尾结点初始化为头结点*/
  printf("请输入各结点的值，以-1结束\n");
  scanf("%d", &x);
  while (x != -1)
  {
    s = (LNode *)malloc(sizeof(LNode)); /*申请新结点空间*/
    s->data = x;                        /*给新结点的数据域赋值*/
    rear->next = s;                     /*将新结点链接到表尾*/
    rear = s;                           /*新结点成为新链表的尾结点*/
    scanf("%d", &x);
  }
  rear->next = head;
  return rear;
}

void DisplayCLink(LNode *rear)
{
  LNode *p;
  p = rear->next->next;
  printf("链表中的结点值分别为：\n");
  while (p != rear->next)
  {
    printf("%5d", p->data);
    p = p->next;
  }
  printf("\n");
}

LNode *ConnectCLink(LNode *ra, LNode *rb)
{
  LNode *p;
  p = ra->next; //记录下第１个链表的头结点
  ra->next = rb->next->next;
  free(rb->next);
  rb->next = p;
  return (rb);
}
