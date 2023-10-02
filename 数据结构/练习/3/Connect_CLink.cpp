//������Ĺ���Ϊ��������ѭ����������β��Ӻϲ�Ϊһ��ѭ��������
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
  LNode *ra, *rb; // ra��rb�ֱ�Ϊ����ѭ���������βָ��
  int n;
  printf("������һ������\n");
  ra = CreateCLinkR();
  DisplayCLink(ra);
  printf("�����ڶ�������\n");
  rb = CreateCLinkR();
  DisplayCLink(rb);
  rb = ConnectCLink(ra, rb);
  printf("���Ӻ��������\n");
  DisplayCLink(rb);
  return 0;
}

LNode *InitCLink()
{
  LNode *head, *rear;
  head = (LNode *)malloc(sizeof(LNode));
  /*Ϊͷ�������ռ�*/
  if (rear != NULL)
    head->next = head;
  rear = head;
  return (rear);
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
  return rear;
}

void DisplayCLink(LNode *rear)
{
  LNode *p;
  p = rear->next->next;
  printf("�����еĽ��ֵ�ֱ�Ϊ��\n");
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
  p = ra->next; //��¼�µڣ��������ͷ���
  ra->next = rb->next->next;
  free(rb->next);
  rb->next = p;
  return (rb);
}
