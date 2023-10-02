//此程序的功能为：实现二叉树的层序遍历
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
   DataType data[MAXSIZE]; //队列用于存放已访问结点的信息
   int front, rear;        //队首、队尾
} SeqQueue;

//初始化队列
SeqQueue *InitQueue()
{
   SeqQueue *q;
   q = (SeqQueue *)malloc(sizeof(SeqQueue));
   q->front = q->rear = 0;
   return q;
}

// 判断队空
int QueueEmpty(SeqQueue *q)
{
   if (q->front == q->rear)
      return 1;
   else
      return 0;
}

//入队操作
int EnQueue(SeqQueue *q, DataType x)
{
   if (((q->rear + 1) % MAXSIZE) == q->front)
   {
      printf("队满！\n");
      return 0;
   }
   else
   {
      q->rear = (q->rear + 1) % MAXSIZE;
      q->data[q->rear] = x;
      return 1;
   }
}

//出队操作
int DeQueue(SeqQueue *q, DataType *px)
{
   if (q->front == q->rear)
   {
      printf("队空!\n");
      return 0;
   }
   else
   {
      q->front = (q->front + 1) % MAXSIZE;
      *px = q->data[q->front];
      return 1;
   }
}

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

//层次遍历二叉树， root 为整棵二叉树的根结点
void LevelOrder(BSTree *root)
{
   SeqQueue *sq;
   BSTree *p = root;
   sq = InitQueue(); //初始化队列
   if (p != NULL)    //若当前二叉树非空
   {
      EnQueue(sq, *p);              //根结点入队
      while (sq->front != sq->rear) //队列不为空时，出队并访问该结点
      {
         DeQueue(sq, p);
         printf("%3c", p->data); //访问根结点
         if (p->lchild != NULL)
            EnQueue(sq, *(p->lchild)); //左孩子入队
         if (p->rchild != NULL)
            EnQueue(sq, *(p->rchild)); //右孩子入队
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
