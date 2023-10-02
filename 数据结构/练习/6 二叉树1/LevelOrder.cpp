//�˳���Ĺ���Ϊ��ʵ�ֶ������Ĳ������
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct node
{
   char data;                    //�����򣬴�Ž�������ֵ
   struct node *lchild, *rchild; //����ָ���򣬷ֱ������Һ��ӽ��ĵ�ַ
} BSTree;

typedef BSTree DataType;

typedef struct
{
   DataType data[MAXSIZE]; //�������ڴ���ѷ��ʽ�����Ϣ
   int front, rear;        //���ס���β
} SeqQueue;

//��ʼ������
SeqQueue *InitQueue()
{
   SeqQueue *q;
   q = (SeqQueue *)malloc(sizeof(SeqQueue));
   q->front = q->rear = 0;
   return q;
}

// �ж϶ӿ�
int QueueEmpty(SeqQueue *q)
{
   if (q->front == q->rear)
      return 1;
   else
      return 0;
}

//��Ӳ���
int EnQueue(SeqQueue *q, DataType x)
{
   if (((q->rear + 1) % MAXSIZE) == q->front)
   {
      printf("������\n");
      return 0;
   }
   else
   {
      q->rear = (q->rear + 1) % MAXSIZE;
      q->data[q->rear] = x;
      return 1;
   }
}

//���Ӳ���
int DeQueue(SeqQueue *q, DataType *px)
{
   if (q->front == q->rear)
   {
      printf("�ӿ�!\n");
      return 0;
   }
   else
   {
      q->front = (q->front + 1) % MAXSIZE;
      *px = q->data[q->front];
      return 1;
   }
}

//�����������Ķ�������tΪָ������������ָ���ָ��
void CreatBSTree(BSTree **t)
{
   char ch;
   scanf("%c", &ch); //���뵱ǰ��������ֵ
   if (ch == '#')    //��'#'��Ϊ�ս��ֵ���ڽ����ݹ�
      *t = NULL;
   else
   {
      *t = (BSTree *)malloc(sizeof(BSTree)); //�����½��ռ�
      (*t)->data = ch;
      CreatBSTree(&((*t)->lchild)); //�ݹ鴴��������
      CreatBSTree(&((*t)->rchild)); //�ݹ鴴��������
   }
}

//��α����������� root Ϊ���ö������ĸ����
void LevelOrder(BSTree *root)
{
   SeqQueue *sq;
   BSTree *p = root;
   sq = InitQueue(); //��ʼ������
   if (p != NULL)    //����ǰ�������ǿ�
   {
      EnQueue(sq, *p);              //��������
      while (sq->front != sq->rear) //���в�Ϊ��ʱ�����Ӳ����ʸý��
      {
         DeQueue(sq, p);
         printf("%3c", p->data); //���ʸ����
         if (p->lchild != NULL)
            EnQueue(sq, *(p->lchild)); //�������
         if (p->rchild != NULL)
            EnQueue(sq, *(p->rchild)); //�Һ������
      }
   }
}

int main()
{
   BSTree *root, **t;
   root = (BSTree *)malloc(sizeof(BSTree));
   t = &root;
   CreatBSTree(t);
   LevelOrder(root);
   return 0;
}
