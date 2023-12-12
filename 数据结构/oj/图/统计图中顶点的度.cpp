#define MAXLEN 100
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int adjvex;        //与某顶点邻接的顶点
    struct node *next; //指向下一个与某顶点邻接的顶点
} EdgeNode;            //边链表结点

typedef struct vnode
{
    int vertex;                     //数据域，存放某顶点名或其它信息
    EdgeNode *firstedge;            //指针域，指向与某顶点邻接的第一个顶点
} VertexNode;                       //表头结点
typedef VertexNode AdjList[MAXLEN]; //表头结点表,下标从0开始

typedef struct
{
    AdjList adjlist;
    int n, e; //图中顶点数及边数
} ALGraph;    //定义邻接表

void CreatesAdjList(ALGraph *g, int n, int e)
{
    EdgeNode *ptr;
    int k, v1, v2;
    g->n = n;
    g->e = e;
    for (k = 0; k < g->n; k++) //初始化表头数组的指针域为空
    {
        g->adjlist[k].firstedge = NULL;
        g->adjlist[k].vertex = k; //这里默认顶点值就是对应下标值
    }
    for (k = 1; k <= g->e; k++) //建立邻接表
    {
        scanf("%d%d", &v1, &v2);                    //输入一对边的起、终结点
        ptr = (EdgeNode *)malloc(sizeof(EdgeNode)); //动态申请一个边链表结点空间
        ptr->adjvex = v2;                           //将该边的终点写入数据域
        ptr->next = g->adjlist[v1].firstedge;       //以下两句是将该结点插入到链表头处
        g->adjlist[v1].firstedge = ptr;
        //若为有向图，则以下几句不执行
        ptr = (EdgeNode *)malloc(sizeof(EdgeNode)); //动态申请一个边链表结点空间
        ptr->adjvex = v1;                           //将该边的终点写入数据域
        ptr->next = g->adjlist[v2].firstedge;       //以下两句是将该结点插入到链表头处
        g->adjlist[v2].firstedge = ptr;
    }
}

int Nodedegree(ALGraph *g, int ch) //统计顶点为ch的度
{
    int i, flag = 0;
    if (g->adjlist[ch].firstedge == NULL)
        return flag;
    while (g->adjlist[ch].firstedge!= NULL)
    {
        flag++;
        g->adjlist[ch].firstedge = g->adjlist[ch].firstedge->next;
    }
    return flag;
}

int main()
{
    ALGraph g;   //定义一个图变量
    EdgeNode *p; //定义一个边链表结点指针变量
    int i, ch;
    scanf("%d%d", &g.n, &g.e);          //图的顶点数和边数
    CreatesAdjList(&g, g.n, g.e);       //调用函数创建邻接表
    scanf("%d", &ch);                   //输入查询顶点值
    printf("%d\n", Nodedegree(&g, ch)); //输出该顶点的度
    return 0;
}
