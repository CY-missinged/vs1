//������Ĺ���Ϊ����ѭ��������ĳ���
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
  printf("����ı�(����ֵ)Ϊ:%d\n", n);
  printf("����ı�Ϊ��ͷ���������:%d\n", head->data);
  return 0;
}

LNode *InitCLink()
{
  LNode *head;
  head = (LNode *)malloc(sizeof(LNode));
  /*Ϊͷ�������ռ�*/
  if (head != NULL)
    head->next = head;
  return (head);
  /*��ͷ����ָ�����ʼ��ΪNULL*/
}

LNode *CreateCLinkR()
/*����һ��ͷΪhead�Ĵ�ͷ���ĵ�����*/
{
  LNode *head, *rear, *s;
  DataType x;
  head = InitCLink(); /*�����ʼ��*/
  rear = head;        /*β����ʼ��Ϊͷ���*/
  printf("�����������ֵ����-1����\n");
  scanf("%d", &x);
  while (x != -1)
  {
    s = (LNode *)malloc(sizeof(LNode)); /*�����½��ռ�*/
    s->data = x;                        /*���½���������ֵ*/
    rear->next = s;                     /*���½�����ӵ���β*/
    rear = s;                           /*�½���Ϊ�������β���*/
    scanf("%d", &x);
  }
  rear->next = head;
  return head;
}

void DisplayCLink(LNode *head)
{
  LNode *p;
  p = head->next;
  printf("�����еĽ��ֵ�ֱ�Ϊ��\n");
  while (p != head)
  {
    printf("%5d", p->data);
    p = p->next;
  }
  printf("\n");
}

int LengthCLink(LNode *L) //��ѭ����������
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
