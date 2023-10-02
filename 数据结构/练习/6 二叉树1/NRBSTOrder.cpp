//�˳�����Ϊ�����÷ǵݹ��㷨ʵ�ֶ���������������ͺ������

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
   BSTree *link;
   int flag;
} StackType;

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

void NRPreOrder(BSTree *bt)
{
   BSTree *s[MAXSIZE], *p;
   int top = -1;
   if (bt != NULL) //���������ǿ�
   {
      p = bt;
      while (p != NULL || top != -1) // ��p�ǿ���ջ�ǿ�ʱ
      {
         while (p != NULL) //�Ӹ�������������������һֱ����
         {
            printf("%5c", p->data); //���η��������Ľ��
            s[++top] = p;           //��;�����Ľ����ջ
            p = p->lchild;
         }
         if (top != -1) //��pΪ�գ��޷�������ʱ�����Ϸ�����;���
         {
            p = s[top];
            top--;
            p = p->rchild; //������������
         }
      }
   }
}

void NRInOrder(BSTree *bt)
{
   BSTree *s[MAXSIZE], *p;
   int top = -1;
   if (bt != NULL) //���������ǿ�
   {
      p = bt;
      while (p != NULL || top != -1) // ��p�ǿ���ջ�ǿ�ʱ
      {
         while (p != NULL) //�Ӹ�������������������һֱ����
         {
            s[++top] = p; //��;�����Ľ����ջ
            p = p->lchild;
         }
         if (top != -1) //��pΪ�գ��޷�������ʱ�����Ϸ�����;���
         {
            p = s[top];
            top--;
            printf("%5c", p->data); //���ʷ��ع����������Ľ��
            p = p->rchild;          //������������
         }
      }
   }
}

void NRPostOrder(BSTree *bt) //�ǵݹ�������������
{
   BSTree *p;
   int top = -1;
   StackType s[MAXSIZE];
   if (bt != NULL)
   {
      p = bt;
      while (p != NULL || top != -1)
      {
         while (p != NULL) //�Ӹ�������������������һֱ����
         {
            top++;
            s[top].link = p;
            s[top].flag = 1;
            p = p->lchild;
         }
         if (top != -1)
         {
            if (s[top].flag == 1) //˵���ý��ֻ��������������δ����������
            {
               s[top].flag++;
               p = s[top].link->rchild;
            } //��ջ��Ԫ�ص��Һ��Ӵ���ʼ�������

            else
            {
               printf("%5c", s[top].link->data);
               top--;
            } //ջ��Ԫ�س�ջ
         }
      }
   }
}

int main()
{
   BSTree *root, **t;
   root = (BSTree *)malloc(sizeof(BSTree));
   t = &root;
   CreatBSTree(t);
   getchar();
   printf("\n����������У�\n");
   NRPreOrder(root);
   printf("\n����������У�\n");
   NRInOrder(root);
   printf("\n����������У�\n");
   NRPostOrder(root);
   return 0;
}
