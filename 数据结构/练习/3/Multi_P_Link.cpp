//�˳���Ĺ���Ϊʵ�ִ�ͷ�������͵������ϵĸ��ֻ�������
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
      printf("������������ֵ\n");
      scanf("%d", &x);
      p = SearchLink(head, x);
      if (p == NULL)
        printf("û�иý��!\n");
      else
      {
        printf("��ϲ���ҵ��ˣ�\n");
        printf("�ý���ַΪ��%d\n", p);
      }
      break;
    case 4:
      printf("���������Ԫ�ص�ֵ:\n");
      scanf("%d", &x);
      printf("������ָ�����Ĺؼ���:\n");
      scanf("%d", &k);
      InsertLink(head, x, k);
      DisplayLink(head);
      break;
    case 5:
      printf("�������ɾ�����Ĺؼ���:\n");
      scanf("%d", &k);
      DeletetLink(head, k);
      DisplayLink(head);
      break;
    case 6:
      n = LengthLink(head);
      printf("����ı�Ϊ:%d\n", n);
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
        printf("����Ϊ�գ�\n");
      else
        printf("�����ֵΪ��%d\n", p->data);
      break;
    case 10:
      printf("������ָ������ֵ:\n");
      scanf("%d", &k);
      p = GetPre(head, k);
      if (p == NULL)
        printf("�޴˽��!\n");
      else if (p == head)
        printf("���ֵΪ%d��ǰ�������ͷ��㣡\n", k);
      else
        printf("���ֵΪ%d��ǰ������ֵΪ%d\n", k, p->data);
      break;
    case 11:
      printf("������ָ������ֵ:\n");
      scanf("%d", &k);
      MultiDelLink(head, k);
      DisplayLink(head);
      break;
    case 0:
      printf("ллʹ�ã��ټ�!\n");
    }
    printf("�����������......\n");
    getchar();
    getchar();
    system("cls");
  }
  return 0;
}

int menu()
{
  int ch;
  printf("************�˵�***********\n");
  printf("* 1-------β�ӷ���������  *\n");
  printf("* 2-------ͷ�巨��������  *\n");
  printf("* 3-------����ָ�����    *\n");
  printf("* 4-------�����½�㣨��*\n");
  printf("* 5-------ɾ��ָ�����(��1����*\n");
  printf("* 6-------���          *\n");
  printf("* 7-------��������        *\n");
  printf("* 8-------�������        *\n");
  printf("* 9-------�����������  *\n");
  printf("* 10------��ָ������ǰ��*\n");
  printf("* 11------ɾ��ָ����㣨�����*\n");
  printf("* 0-------�˳�            *\n");
  printf("* *************************\n");
  printf("���������ѡ��\n");
  scanf("%d", &ch);
  return ch;
}

LNode *InitLink()
{
  LNode *head;
  head = (LNode *)malloc(sizeof(LNode));
  /*Ϊͷ�������ռ�*/
  if (head != NULL)
    head->next = NULL;
  return (head);
  /*��ͷ����ָ�����ʼ��ΪNULL*/
}

LNode *CreateLinkR()
/*����һ��ͷΪhead�Ĵ�ͷ���ĵ�����*/
{
  LNode *head, *rear, *s;
  DataType x;
  head = InitLink(); /*�����ʼ��*/
  rear = head;       /*β����ʼ��Ϊͷ���*/
  printf("�����������ֵ����-1����\n");
  scanf("%d", &x);
  while (x != -1)
  {
    s = (LNode *)malloc(sizeof(LNode)); /*�����½��ռ�*/
    s->data = x;                        /*���½���������ֵ*/
    s->next = NULL;                     /*���½���ָ�����ʼ��Ϊ��*/
    rear->next = s;                     /*���½�����ӵ���β*/
    rear = s;                           /*�½���Ϊ�������β���*/
    scanf("%d", &x);
  }
  return head;
}

LNode *CreateLinkF()
{
  LNode *head, *s;
  DataType x;
  head = InitLink(); /*�����ʼ��*/
  printf("�����������ֵ����-1����\n");
  scanf("%d", &x);
  while (x != -1)
  {
    s = (LNode *)malloc(sizeof(LNode));
    /*Ϊ�½��s����ռ䣬*/
    s->data = x;          /*���½���������ֵ*/
    s->next = head->next; /*���½��������Ԫ���֮ǰ*/
    head->next = s;       /*���½������ͷ���֮��*/
    scanf("%d", &x);
  }
  return (head);
}

void DisplayLink(LNode *head)
{
  LNode *p;
  p = head->next;
  printf("�����еĽ��ֵ�ֱ�Ϊ��\n");
  while (p != NULL)
  {
    printf("%5d", p->data);
    p = p->next;
  }
  printf("\n");
}

LNode *SearchLink(LNode *head, int x)
/*�ڴ�ͷ���ĵ�����head�в���Ԫ��x*/
{
  LNode *p;
  p = head->next;                   /*����Ԫ��㿪ʼ����*/
  while (p != NULL && p->data != x) /*������������*/
    p = p->next;
  return p;
}

void InsertLink(LNode *head, DataType x, KeyType k)
/*��Ԫ��x���뵽��������ֵΪk��Ԫ��֮��*/
{
  LNode *p, *s;
  p = SearchLink(head, k);
  if (p != NULL)
  {
    s = (LNode *)malloc(sizeof(LNode));
    /*�����½��*/
    s->data = x; /*���½��������ֵ*/
    s->next = p->next;
    p->next = s; /*���½������p���֮��*/
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
    /*��ָ������������ɾ��*/
    free(p); /*�ͷű�ɾ�����ռ���ڴ�ռ�*/
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
