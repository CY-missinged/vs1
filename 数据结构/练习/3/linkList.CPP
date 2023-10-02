/*链式存储结构的线性表上的基本操作*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE sizeof(LNode)

typedef struct
{
  int num;
  char name[20];
  float price;
  int stock;
} DataType;

typedef struct LNode
{
  DataType data;
  struct LNode *next;
} LNode;

typedef int KeyType;

int menu();
LNode *InitLink();
LNode *CreatLinkR();
void DisplayLink(LNode *head);
int InsertLink1(LNode *head, DataType x, KeyType knum);
int DeleteLink(LNode *head, KeyType knum);
LNode *SearchLink(LNode *head, KeyType knum);

int main()
{
  DataType x;
  LNode *head, *p;
  int ch, j;
  KeyType s_num;
  ch = 1;
  while (ch != 0)
  {
    ch = menu();
    switch (ch)
    {
    case 1:
      head = CreatLinkR();
      break;
    case 2:
      DisplayLink(head);
      break;
    case 3:
      printf("请输入待插位置商品的编号:");
      scanf("%d", &s_num);
      printf("请输入新商品的完整信息：编号、名称、单价和库存量:");
      scanf("%d %s %f %d", &x.num, x.name, &x.price, &x.stock);
      j = InsertLink1(head, x, s_num);
      if (j == 0)
        printf("插入失败！\n");
      else
        DisplayLink(head);
      break;
    case 4:
      printf("请输入待删商品的编号:");
      scanf("%d", &s_num);
      j = DeleteLink(head, s_num);
      if (j == 0)
        printf("删除失败！\n");
      else
        DisplayLink(head);
      break;
    case 5:
      printf("请输入待查商品的编号:");
      scanf("%d", &s_num);
      p = SearchLink(head, s_num);
      if (p == NULL)
        printf("无此商品!\n");
      else
      {
        printf("    编号           名称      单价   库存量\n");
        printf("%6d%16s%10.2f%6d\n", p->data.num, p->data.name, p->data.price, p->data.stock);
      }
      break;
    case 0:
      printf("谢谢使用本系统，再见！\n");
    } /*switch*/
    printf("按任意键继续......\n");
    getchar();
    getchar();
    system("cls");
  } /*while*/
  return 0;
}

int menu()
{
  int ch;
  printf("*****************************************\n");
  printf("*    1------------建立初始商品信息链表   *\n");
  printf("*    2------------显示商品信息表        *\n");
  printf("*    3------------插入新商品信息        *\n");
  printf("*    4------------删除指定编号商品信息  *\n");
  printf("*    5------------查找指定编号商品信息  *\n");
  printf("*    0------------退出商品信息管理程序  *\n");
  printf("*****************************************\n");
  printf("请输入你的选择:(0-5)\n");
  scanf("%d", &ch);
  return (ch);
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

LNode *CreatLinkR()
/*尾接法创建链表,输入商品信息表，以商品编号为-1作为输入的结束标志*/
{
  LNode *head, *rear, *s;
  DataType x;
  int tnum;
  head = InitLink();
  rear = head;
  printf("输入商品编号:");
  scanf("%d", &tnum);
  while (tnum != -1)
  {
    x.num = tnum;
    printf("输入商品名称:");
    scanf("%s", x.name);
    printf("输入商品单价:");
    scanf("%f", &x.price);
    printf("输入商品库存量:");
    scanf("%d", &x.stock);
    s = (LNode *)malloc(SIZE);
    s->data = x;
    rear->next = s;
    rear = s;
    printf("输入商品编号:");
    scanf("%d", &tnum);
  }
  rear->next = NULL;
  return (head);
}

void DisplayLink(LNode *head)
{
  LNode *p;
  p = head->next;
  printf("    编号           名称      单价   库存量\n");
  while (p != NULL)
  {
    printf("%6d%16s%10.2f%6d\n", p->data.num, p->data.name, p->data.price, p->data.stock);
    p = p->next;
  }
}

int InsertLink1(LNode *head, DataType x, KeyType knum)
{
  LNode *p, *q, *s;
  p = head->next;
  q = head;
  while (p != NULL && p->data.num != knum)
  {
    q = p;
    p = p->next;
  }
  if (p != NULL)
  {
    s = (LNode *)malloc(SIZE);
    s->data = x;
    s->next = p;
    q->next = s;
    return 1;
  }
  else
  {
    printf("插入位置错误\n");
    return 0;
  }
}

int DeleteLink(LNode *head, KeyType knum)
{
  LNode *p, *q;
  p = head->next;
  q = head;
  while (p != NULL && p->data.num != knum)
  {
    q = p;
    p = p->next;
  }
  if (p != NULL)
  {
    q->next = p->next;
    free(p);
    return 1;
  }
  else
  {
    printf("删除位置错误！\n");
    return 0;
  }
}

LNode *SearchLink(LNode *head, KeyType knum)
{
  LNode *p;
  p = head->next;
  while (p != NULL && p->data.num != knum)
    p = p->next;
  return (p);
}
