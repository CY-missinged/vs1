#include <stdio.h>
#include <stdlib.h>

typedef int DataType1;

//�������ṹ��
typedef struct Node
{
    //�������ṹ����
    DataType1 data;
    struct Node *lchild;
    struct Node *rchild;
} BiTreeNode;

//������������
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
        CreatTree(&((*t)->lchild)); //������
        CreatTree(&((*t)->rchild)); //������
    }
}

//�������������
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

//�����������������¼Ҷ�ӽڵ�ĸ���
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

//����
typedef struct Queue
{
    DataType2 data[QUEUESIZE];
    int front; //��ͷ
    int rear;  //��β
    int count; //���������жϼ����
} SeqQueue;

//��ʼ������
void InitQueue(SeqQueue *q)
{
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

//�ж�q��ָ�����Ƿ�Ϊ�գ��շ���1�����򷵻�0
int QueueEmpty(SeqQueue *q)
{
    if (q->front == q->rear && q->count == 0)
        return 1;
    else
        return 0;
}

//��ӣ���x����q��ָ�Ķ����У��ɹ�����1�����򷵻�0
int EnQueue(SeqQueue *q, DataType2 x)
{
    if (q->count == QUEUESIZE)
    {
        printf("����������\n");
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

//���ӣ���q��ָ���еĶ�ͷԪ��ɾ������ͨ��ָ�����x���س���Ԫ�أ��ɹ�����1�����򷵻�0
int DeQueue(SeqQueue *q, DataType2 *x)
{
    if (q->front == q->rear && q->count == 0)
    {
        printf("�����ѿգ�\n");
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

// 1 2 3 -1 -1 -1 4 -1 -1δ���
// Ҷ�ӽڵ���ж�
// //�ж϶������Ƿ�Ϊ��ȫ���������Ƿ���1�����򷵻�0
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
    printf("�������������Ϊ:\n");
    OutputTree_zhong(root);
    printf("\n");
    OutputTree_hou(root);
    printf("Ҷ�ӽڵ���ĿΪ%d\n", root_hou);
    // if (IsWQTree(root))
    // {
    //     printf("��ȫ������\n");
    // }
    // else
    // {
    //     printf("����ȫ������\n");
    // }
    return 0;
}
