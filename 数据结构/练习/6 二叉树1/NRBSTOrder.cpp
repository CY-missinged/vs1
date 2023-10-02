//此程序功能为：采用非递归算法实现二叉树的先序、中序和后序遍历

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct node
{
   char data;                    //数据域，存放结点的数据值
   struct node *lchild, *rchild; //左右指针域，分别存放左、右孩子结点的地址
} BSTree;

typedef BSTree DataType;

typedef struct
{
   BSTree *link;
   int flag;
} StackType;

//建立二叉树的二叉链表，t为指向二叉树根结点指针的指针
void CreatBSTree(BSTree **t)
{
   char ch;
   scanf("%c", &ch); //输入当前结点的数据值
   if (ch == '#')    //以'#'作为空结点值用于结束递归
      *t = NULL;
   else
   {
      *t = (BSTree *)malloc(sizeof(BSTree)); //申请新结点空间
      (*t)->data = ch;
      CreatBSTree(&((*t)->lchild)); //递归创建左子树
      CreatBSTree(&((*t)->rchild)); //递归创建右子树
   }
}

void NRPreOrder(BSTree *bt)
{
   BSTree *s[MAXSIZE], *p;
   int top = -1;
   if (bt != NULL) //若二叉树非空
   {
      p = bt;
      while (p != NULL || top != -1) // 当p非空且栈非空时
      {
         while (p != NULL) //从根出发，沿左子树方向一直向下
         {
            printf("%5c", p->data); //依次访问遇到的结点
            s[++top] = p;           //沿途经过的结点入栈
            p = p->lchild;
         }
         if (top != -1) //当p为空，无法再深入时，向上返回沿途结点
         {
            p = s[top];
            top--;
            p = p->rchild; //沿右子树向下
         }
      }
   }
}

void NRInOrder(BSTree *bt)
{
   BSTree *s[MAXSIZE], *p;
   int top = -1;
   if (bt != NULL) //若二叉树非空
   {
      p = bt;
      while (p != NULL || top != -1) // 当p非空且栈非空时
      {
         while (p != NULL) //从根出发，沿左子树方向一直向下
         {
            s[++top] = p; //沿途经过的结点入栈
            p = p->lchild;
         }
         if (top != -1) //当p为空，无法再深入时，向上返回沿途结点
         {
            p = s[top];
            top--;
            printf("%5c", p->data); //访问返回过程中遇到的结点
            p = p->rchild;          //沿右子树向下
         }
      }
   }
}

void NRPostOrder(BSTree *bt) //非递归后序遍历二叉树
{
   BSTree *p;
   int top = -1;
   StackType s[MAXSIZE];
   if (bt != NULL)
   {
      p = bt;
      while (p != NULL || top != -1)
      {
         while (p != NULL) //从根出发，沿左子树方向一直向下
         {
            top++;
            s[top].link = p;
            s[top].flag = 1;
            p = p->lchild;
         }
         if (top != -1)
         {
            if (s[top].flag == 1) //说明该结点只遍历了左子树还未遍历右子树
            {
               s[top].flag++;
               p = s[top].link->rchild;
            } //从栈顶元素的右孩子处开始后序遍历

            else
            {
               printf("%5c", s[top].link->data);
               top--;
            } //栈顶元素出栈
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
   printf("\n先序遍历序列：\n");
   NRPreOrder(root);
   printf("\n中序遍历序列：\n");
   NRInOrder(root);
   printf("\n后序遍历序列：\n");
   NRPostOrder(root);
   return 0;
}
