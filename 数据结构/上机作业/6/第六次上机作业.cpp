#include <stdio.h>
#include <stdlib.h>

typedef int DataType1;

//二叉树结构体
typedef struct Node
{
    //二叉树结构定义
    DataType1 data;
    struct Node *lchild;
    struct Node *rchild;
} BiTreeNode;

//先序建立二叉树
void CreatTree(BiTreeNode **t)
{
    int x;
    // printf("aaaaa\n");
    scanf("%d", &x);
    if (x == -1)
    {
        *t = NULL;
    }
    else
    {
        // system("pause");
        *t = (BiTreeNode *)malloc(sizeof(BiTreeNode));
        (*t)->data = x;
        CreatTree(&((*t)->lchild)); //左子树
        CreatTree(&((*t)->rchild)); //右子树
    }
}

//中序输出二叉树
void OutputTree_zhong(BiTreeNode *root)
{
    if (root)
    {
        OutputTree_zhong(root->lchild);
        printf("%d ", root->data);
        OutputTree_zhong(root->rchild);
    }
}

int root_hou = 0;

//后序遍历二叉树并记录叶子节点的个数
void OutputTree_hou(BiTreeNode *root)
{
    if (root)
    {
        OutputTree_hou(root->lchild);
        OutputTree_hou(root->rchild);
        if (root->lchild == NULL && root->rchild == NULL)
            root_hou++;
    }
}

#define QUEUESIZE 100
typedef BiTreeNode DataType2;

//队列
typedef struct Queue
{
    DataType2 data[QUEUESIZE];
    int front; //队头
    int rear;  //队尾
    int count; //计数器，判断假溢出
} SeqQueue;

//初始化队列
void InitQueue(SeqQueue *q)
{
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

//判断q所指队列是否为空，空返回1，否则返回0
int QueueEmpty(SeqQueue *q)
{
    if (q->front == q->rear && q->count == 0)
        return 1;
    else
        return 0;
}

//入队，将x插入q所指的队列中，成功返回1，否则返回0
int EnQueue(SeqQueue *q, DataType2 x)
{
    if (q->count == QUEUESIZE)
    {
        printf("队列已满！\n");
        return 0;
    }
    else
    {
        q->data[q->rear] = x;
        q->rear = (q->rear + 1) % QUEUESIZE;
        q->count++;
        return 1;
    }
}

//出队，将q所指队列的队头元素删除，并通过指针变量x返回出队元素，成功返回1，否则返回0
int DeQueue(SeqQueue *q, DataType2 *x)
{
    if (q->front == q->rear && q->count == 0)
    {
        printf("队列已空！\n");
        return 0;
    }
    else
    {
        *x = q->data[q->front];
        q->front = (q->front + 1) % QUEUESIZE;
        q->count--;
        return 1;
    }
}

// 1 2 3 -1 -1 -1 4 -1 -1未解决
// 叶子节点的判断
// //判断二叉树是否为完全二叉树，是返回1，否则返回0
// int IsWQTree(BiTreeNode *root)
// {
//     int flag = 1;
//     SeqQueue dl;
//     BiTreeNode *p = root;
//     InitQueue(&dl);
//     if (p != NULL)
//     {
//         EnQueue(&dl, *p);
//         while (QueueEmpty(&dl) == 0)
//         {
//             DeQueue(&dl, p);
//             if ((p->lchild != NULL && p->rchild == NULL) || (p->lchild == NULL && p->rchild != NULL))
//             {
//                 flag = 0;
//             }
//             if (p->lchild != NULL)
//                 EnQueue(&dl, *(p->lchild));
//             if (p->rchild != NULL)
//                 EnQueue(&dl, *(p->rchild));
//         }
//     }
//     return flag;
// }

int main()
{
    BiTreeNode *root, **t;
    root = (BiTreeNode *)malloc(sizeof(BiTreeNode));
    t = &root;
    CreatTree(t);
    getchar();
    printf("中序遍历二叉树为:\n");
    OutputTree_zhong(root);
    printf("\n");
    OutputTree_hou(root);
    printf("叶子节点数目为%d\n", root_hou);
    // if (IsWQTree(root))
    // {
    //     printf("完全二叉树\n");
    // }
    // else
    // {
    //     printf("非完全二叉树\n");
    // }
    return 0;
}
