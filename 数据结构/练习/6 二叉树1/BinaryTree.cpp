#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct node
{
   DataType data;
   struct node *lchild, *rchild;
} BSTree;

//�����������Ķ�������tΪָ������������ָ���ָ��
void CreatBSTree(BSTree **t)
{
   DataType ch;
   scanf("%c", &ch); //���뵱ǰ��������ֵ
   if (ch == '#')    //��'#'��Ϊ�ս��ֵ���ڽ����ݹ�
      *t = NULL;
   else //���������ǿգ��Ƚ������ٷֱ�ݹ齨��������
   {
      *t = (BSTree *)malloc(sizeof(BSTree)); //�����½��ռ�
      (*t)->data = ch;
      CreatBSTree(&((*t)->lchild)); //�ݹ鴴��������
      CreatBSTree(&((*t)->rchild)); //�ݹ鴴��������
   }
}

void PreOrder(BSTree *p)
{
   if (p != NULL)
   {
      printf("%5c", p->data); //���ʸ����
      PreOrder(p->lchild);    //�������������
      PreOrder(p->rchild);    //�������������
   }
}

void InOrder(BSTree *p)
{
   if (p != NULL)
   {
      InOrder(p->lchild);     //�������������
      printf("%5c", p->data); //���ʸ����
      InOrder(p->rchild);     //�������������
   }
}

void PostOrder(BSTree *p)
{
   if (p != NULL)
   {
      PostOrder(p->lchild);   //�������������
      PostOrder(p->rchild);   //�������������
      printf("%5c", p->data); //���ʸ����
   }
}

//���������ַΪp�Ķ����������
int DepthBSTree(BSTree *p)
{
   int n1, n2;
   if (p != NULL)
   {
      n1 = DepthBSTree(p->lchild); //�������������
      n2 = DepthBSTree(p->rchild); //�������������
      if (n1 > n2)                 //�Ƚϸ����������������
         return n1 + 1;
      else
         return n2 + 1;
   }
   else
      return 0;
}

int main()
{
   BSTree *p;
   int n = 0, d;
   printf("�������������������������ĸ������ֵ����#��Ϊ�ݹ������־");
   CreatBSTree(&p);
   printf("����������Ϊ��");
   PreOrder(p);
   printf("\n����������Ϊ��");
   InOrder(p);
   printf("\n����������Ϊ��");
   PostOrder(p);
   d = DepthBSTree(p);
   printf("\n���������Ϊ��%d\n", d);
   return 0;
}
