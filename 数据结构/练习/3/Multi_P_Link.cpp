//此程序的功能为实现带头结点的整型单链表上的各种基本操作
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct LNode
{
  int data;
  struct LNode *next;
} LNode;

typedef int DataType;
typedef int KeyType;

int menu();
LNode *InitLink();
LNode *CreateLinkR();
LNode *CreateLinkF();
void DisplayLink(LNode *head);
LNode *SearchLink(LNode *head, int x);
void InsertLink(LNode *head, DataType x, KeyType k);
void DeletetLink(LNode *head, KeyType k);
int LengthLink(LNode *head);
void InverseLink(LNode *head);
LNode *GetMax(LNode *head);
LNode *GetPre(LNode *head, int k);
void MultiDelLink(LNode *head, int k);

int main()
{
  LNode *head, *p;
  int x, k, ch = 1, n;
  while (ch != 0)
  {
    ch = menu();
    switch (ch)
    {
    case 1:
      head = CreateLinkR();
      DisplayLink(head);
      break;
    case 2:
      head = CreateLinkF();
      DisplayLink(head);
      break;
    case 3:
      printf("请输入待查结点的值\n");
      scanf("%d", &x);
      p = SearchLink(head, x);
      if (p == NULL)
        printf("没有该结点!\n");
      else
      {
        printf("恭喜，找到了！\n");
        printf("该结点地址为：%d\n", p);
      }
      break;
    case 4:
      printf("请输入待插元素的值:\n");
      scanf("%d", &x);
      printf("请输入指定结点的关键字:\n");
      scanf("%d", &k);
      InsertLink(head, x, k);
      DisplayLink(head);
      break;
    case 5:
      printf("请输入待删除结点的关键字:\n");
      scanf("%d", &k);
      DeletetLink(head, k);
      DisplayLink(head);
      break;
    case 6:
      n = LengthLink(head);
      printf("链表的表长为:%d\n", n);
      break;
    case 7:
      InverseLink(head);
      DisplayLink(head);
      break;
    case 8:
      DisplayLink(head);
      break;
    case 9:
      p = GetMax(head);
      if (p == NULL)
        printf("链表为空！\n");
      else
        printf("最大结点值为：%d\n", p->data);
      break;
    case 10:
      printf("请输入指定结点的值:\n");
      scanf("%d", &k);
      p = GetPre(head, k);
      if (p == NULL)
        printf("无此结点!\n");
      else if (p == head)
        printf("结点值为%d的前驱结点是头结点！\n", k);
      else
        printf("结点值为%d的前驱结点的值为%d\n", k, p->data);
      break;
    case 11:
      printf("请输入指定结点的值:\n");
      scanf("%d", &k);
      MultiDelLink(head, k);
      DisplayLink(head);
      break;
    case 0:
      printf("谢谢使用！再见!\n");
    }
    printf("按任意键继续......\n");
    getchar();
    getchar();
    system("cls");
  }
  return 0;
}

int menu()
{
  int ch;
  printf("************菜单***********\n");
  printf("* 1-------尾接法建立链表  *\n");
  printf("* 2-------头插法建立链表  *\n");
  printf("* 3-------查找指定结点    *\n");
  printf("* 4-------插入新结点（后）*\n");
  printf("* 5-------删除指定结点(仅1个）*\n");
  printf("* 6-------求表长          *\n");
  printf("* 7-------逆置链表        *\n");
  printf("* 8-------输出链表        *\n");
  printf("* 9-------求链表最大结点  *\n");
  printf("* 10------求指定结点的前驱*\n");
  printf("* 11------删除指定结点（多个）*\n");
  printf("* 0-------退出            *\n");
  printf("* *************************\n");
  printf("请输入你的选择：\n");
  scanf("%d", &ch);
  return ch;
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
  printf("请输入各结点的值，以-1结束\n");
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

LNode *CreateLinkF()
{
  LNode *head, *s;
  DataType x;
  head = InitLink(); /*链表初始化*/
  printf("请输入各结点的值，以-1结束\n");
  scanf("%d", &x);
  while (x != -1)
  {
    s = (LNode *)malloc(sizeof(LNode));
    /*为新结点s申请空间，*/
    s->data = x;          /*给新结点的数据域赋值*/
    s->next = head->next; /*将新结点链到首元结点之前*/
    head->next = s;       /*将新结点链到头结点之后*/
    scanf("%d", &x);
  }
  return (head);
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

LNode *SearchLink(LNode *head, int x)
/*在带头结点的单链表head中查找元素x*/
{
  LNode *p;
  p = head->next;                   /*从首元结点开始查找*/
  while (p != NULL && p->data != x) /*逐个结点向后查找*/
    p = p->next;
  return p;
}

void InsertLink(LNode *head, DataType x, KeyType k)
/*将元素x插入到单链表中值为k的元素之后*/
{
  LNode *p, *s;
  p = SearchLink(head, k);
  if (p != NULL)
  {
    s = (LNode *)malloc(sizeof(LNode));
    /*申请新结点*/
    s->data = x; /*给新结点数据域赋值*/
    s->next = p->next;
    p->next = s; /*将新结点链到p结点之后*/
  }
  else
    printf("invaild insert position\n");
}

void DeletetLink(LNode *head, KeyType x)
{
  LNode *p, *q;
  q = head;
  p = head->next;
  while (p != NULL && p->data != x)
  {
    q = p;
    p = p->next;
  }
  if (p != NULL)
  {
    q->next = p->next;
    /*将指定结点从链表中删除*/
    free(p); /*释放被删结点所占的内存空间*/
  }
  else
    printf("invaild delete position\n");
}

int LengthLink(LNode *head)
{
  int n = 0;
  LNode *p;
  p = head->next;
  while (p != NULL)
  {
    n++;
    p = p->next;
  }
  return n;
}

void InverseLink(LNode *head)
{
  LNode *p, *q;
  p = head->next;
  head->next = NULL;
  while (p != NULL)
  {
    q = p->next;
    p->next = head->next;
    head->next = p;
    p = q;
  }
}

LNode *GetMax(LNode *head)
{
  LNode *p, *pmax;
  if (head->next != NULL)
  {
    p = head->next;
    pmax = head->next;
    while (p != NULL)
    {
      if (p->data > pmax->data)
        pmax = p;
      p = p->next;
    }
    return pmax;
  }
  else
    return NULL;
}

LNode *GetPre(LNode *head, int k)
{
  LNode *p, *q;
  q = head;
  p = head->next;
  while (p != NULL && p->data != k)
  {
    q = p;
    p = p->next;
  }
  if (p == NULL)
    return NULL;
  else
    return q;
}

void MultiDelLink(LNode *head, int k)
{
  LNode *q, *p;
  q = head;
  p = head->next;
  while (p != NULL)
    if (p->data == k)
    {
      q->next = p->next;
      free(p);
      p = q->next;
    }
    else
    {
      q = p;
      p = p->next;
    }
}
