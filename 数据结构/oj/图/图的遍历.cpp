#include <stdio.h>
#include <stdlib.h>

#define MAX_GRAPH 50 // 最大结点数目

int visited[MAX_GRAPH] = {0};

typedef struct
{
    int V;                               // 结点数目
    int E;                               // 边数目
    int adjMatrix[MAX_GRAPH][MAX_GRAPH]; // 采用邻接矩阵存储
} Graph;

// 图的初始化
void InitGraph(Graph *g)
{
    int i, j;
    g->V = 0;
    g->E = 0;
    for (i = 0; i < MAX_GRAPH; i++)
        for (j = 0; j < MAX_GRAPH; j++)
            g->adjMatrix[i][j] = 0;
}

// 创建图
void CreateGraph(Graph *g)
{
    int n, m, i;
    int v, u;
    scanf("%d", &n); // 读入节点的个数
    scanf("%d", &m); // 读入边的个数
    g->V = n;
    g->E = m;
    for (i = 0; i < g->E; i++)
    { // 循环读入m条边
        scanf("%d%d", &v, &u);
        g->adjMatrix[v][u] = 1;
        g->adjMatrix[u][v] = 1;
    }
}

int visit[MAX_GRAPH + 1];

// 请补充DFS函数的代码
void DFS(Graph *g, int v)
{
    int j, i = v;
    printf("%d ", i);
    visit[i] = 1;
    for (j = 1; j <= g->V; j++)
    {
        if ((g->adjMatrix[i][j] == 1) && !visit[j])
            DFS(g, j);
    }
}

void DFST(Graph *g)
{
    int i;
    for (i = 1; i < g->V; i++)
    {
        visit[1] = 0;
    }
    for (i = 1; i < g->V; i++)
    {
        if (!visit[i])
        {
            DFS(g, i);
        }
    }
}

int main()
{
    Graph g;
    InitGraph(&g);
    CreateGraph(&g);
    DFS(&g, 0); // 从图g的0号结点开始深度优先搜索
    return 0;
}
