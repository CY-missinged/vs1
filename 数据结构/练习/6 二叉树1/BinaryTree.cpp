#include <stdio.h>
#include <stdlib.h>

typedef char DataType;

typedef struct node
{
   DataType data;
   struct node *lchild, *rchild;
} BSTree;

//建立二叉树的二叉链表，t为指向二叉树根结点指针的指针
void CreatBSTree(BSTree **t)
{
   DataType ch;
   scanf("%c", &ch); //输入当前结点的数据值
   if (ch == '#')    //以'#'作为空结点值用于结束递归
      *t = NULL;
   else //若二叉树非空，先建根，再分别递归建左右子树
   {
      *t = (BSTree *)malloc(sizeof(BSTree)); //申请新结点空间
      (*t)->data = ch;
      CreatBSTree(&((*t)->lchild)); //递归创建左子树
      CreatBSTree(&((*t)->rchild)); //递归创建右子树
   }
}

void PreOrder(BSTree *p)
{
   if (p != NULL)
   {
      printf("%5c", p->data); //访问根结点
      PreOrder(p->lchild);    //先序遍历左子树
      PreOrder(p->rchild);    //先序遍历右子树
   }
}

void InOrder(BSTree *p)
{
   if (p != NULL)
   {
      InOrder(p->lchild);     //中序遍历左子树
      printf("%5c", p->data); //访问根结点
      InOrder(p->rchild);     //中序遍历右子树
   }
}

void PostOrder(BSTree *p)
{
   if (p != NULL)
   {
      PostOrder(p->lchild);   //后序遍历左子树
      PostOrder(p->rchild);   //后序遍历右子树
      printf("%5c", p->data); //访问根结点
   }
}

//计算根结点地址为p的二叉树的深度
int DepthBSTree(BSTree *p)
{
   int n1, n2;
   if (p != NULL)
   {
      n1 = DepthBSTree(p->lchild); //后序遍历左子树
      n2 = DepthBSTree(p->rchild); //后序遍历右子树
      if (n1 > n2)                 //比较根结点的左右子树深度
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
   printf("按照先序次序依次输入二叉树的各个结点值，以#作为递归结束标志");
   CreatBSTree(&p);
   printf("先序遍历结果为：");
   PreOrder(p);
   printf("\n中序遍历结果为：");
   InOrder(p);
   printf("\n后序遍历结果为：");
   PostOrder(p);
   d = DepthBSTree(p);
   printf("\n二叉树深度为：%d\n", d);
   return 0;
}
