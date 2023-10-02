//本程序的功能为：实现单链表的逆置
#include <stdio.h>
#include <stdlib.h>

typedef int DataType;
typedef int KeyType;

typedef struct LNode
{
  DataType data;
  struct LNode *next;
} LNode;

LNode *InitLink();
LNode *CreateLinkR();
void DisplayLink(LNode *head);
void ReverseLink(LNode *H);

int main()
{
  LNode *head;
  head = CreateLinkR();
  printf("逆置前：\n");
  DisplayLink(head);
  ReverseLink(head);
  printf("逆置后：\n");
  DisplayLink(head);
  return 0;
}

LNode *InitLink()
{
  LNode *head;
  head = (LNode *)malloc(sizeof(LNode));
  /*为头结点申请空间*/
  if (head != NULL)
    head->next = NULL;
  return (head);
  /*将头结点的指针域初始化为NULL*/
}

LNode *CreateLinkR()
/*建立一个头为head的带头结点的单链表*/
{
  LNode *head, *rear, *s;
  DataType x;
  head = InitLink(); /*链表初始化*/
  rear = head;       /*尾结点初始化为头结点*/
  printf("输入各结点的值，以-1结束\n");
  scanf("%d", &x);
  while (x != -1)
  {
    s = (LNode *)malloc(sizeof(LNode)); /*申请新结点空间*/
    s->data = x;                        /*给新结点的数据域赋值*/
    s->next = NULL;                     /*将新结点的指针域初始化为空*/
    rear->next = s;                     /*将新结点链接到表尾*/
    rear = s;                           /*新结点成为新链表的尾结点*/
    scanf("%d", &x);
  }
  return head;
}

void DisplayLink(LNode *head)
{
  LNode *p;
  p = head->next;
  printf("链表中的结点值分别为：\n");
  while (p != NULL)
  {
    printf("%5d", p->data);
    p = p->next;
  }
  printf("\n");
}

void ReverseLink(LNode *H)
{
  LNode *p, *q;
  p = H->next;      //使p指向原链表的首元结点
  H->next = NULL;   //新链表初始化
  while (p != NULL) //将原链表中的结点逐个摘下并头插到新链表中
  {
    q = p;             //先使q指向原链表中待摘下的结点
    p = p->next;       // p后移指向原链表剩余部分的第一个结点
    q->next = H->next; //将q采用头插法插到新链表中
    H->next = q;
  }
}
