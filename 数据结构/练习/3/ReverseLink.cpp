//������Ĺ���Ϊ��ʵ�ֵ����������
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
  printf("����ǰ��\n");
  DisplayLink(head);
  ReverseLink(head);
  printf("���ú�\n");
  DisplayLink(head);
  return 0;
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
  printf("���������ֵ����-1����\n");
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

void ReverseLink(LNode *H)
{
  LNode *p, *q;
  p = H->next;      //ʹpָ��ԭ�������Ԫ���
  H->next = NULL;   //�������ʼ��
  while (p != NULL) //��ԭ�����еĽ�����ժ�²�ͷ�嵽��������
  {
    q = p;             //��ʹqָ��ԭ�����д�ժ�µĽ��
    p = p->next;       // p����ָ��ԭ����ʣ�ಿ�ֵĵ�һ�����
    q->next = H->next; //��q����ͷ�巨�嵽��������
    H->next = q;
  }
}
