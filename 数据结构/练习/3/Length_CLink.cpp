//本程序的功能为：求循环单链表的长度
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
int LengthCLink(LNode *head);

int main()
{
  LNode *head;
  int n;
  head = CreateCLinkR();
  DisplayCLink(head);
  n = LengthCLink(head);
  printf("链表的表长(返回值)为:%d\n", n);
  printf("链表的表长为（头结点数据域）:%d\n", head->data);
  return 0;
}

LNode *InitCLink()
{
  LNode *head;
  head = (LNode *)malloc(sizeof(LNode));
  /*为头结点申请空间*/
  if (head != NULL)
    head->next = head;
  return (head);
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
  return head;
}

void DisplayCLink(LNode *head)
{
  LNode *p;
  p = head->next;
  printf("链表中的结点值分别为：\n");
  while (p != head)
  {
    printf("%5d", p->data);
    p = p->next;
  }
  printf("\n");
}

int LengthCLink(LNode *L) //求循环单链表长度
{
  int n;
  LNode *p;
  p = L;
  n = 0;
  while (p->next != L)
  {
    p = p->next;
    n++;
  }
  L->data = n;
  return (n);
}
