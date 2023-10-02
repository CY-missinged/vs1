#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

//节点信息
typedef struct zhangting
{
    int num;
    char name[10];
    int works, audience;
} DataType;

//图的信息
typedef struct tu
{
    DataType vexs[MAXSIZE + 1];          //节点
    int edges[MAXSIZE + 1][MAXSIZE + 1]; //邻接矩阵
    int n, e;                            //节点数，边数
} MGraph;

//创建无向图邻接矩阵,n个顶点，e条边
void Creat(MGraph *g, int n, int e)
{
    int i, j, k, v1, v2, t1, t3, t4;
    char t2[20];
    g->n = n;
    g->e = e;
    for (i = 1; i <= g->n; i++)
    {
        g->vexs[i].num = i;
    }
    for (i = i; i < g->n; i++)
    {
        for (j = 1; j <= g->n; j++)
        {
            g->edges[i][j] = 0;
        }
    }
    printf("请输入每一条边的起点、终点对应的节点：\n");
    for (k = 1; k <= g->e; k++)
    {
        scanf("%d%d", &v1, &v2);
        g->edges[v1][v2] = 1;
        g->edges[v2][v1] = 1;
    }
    printf("请输入每个展厅的信息:\n");
    for (i = 1; i <= g->n; i++)
    {
        printf("请输入展厅编号:\n");
        scanf("%d", &t1);
        printf("请输入展厅名称:\n");
        scanf("%s", t2);
        printf("请输入作品数量:\n");
        scanf("%d", &t3);
        printf("请输入观众喜爱度:\n");
        scanf("%d", &t4);
        g->vexs[i].num = t1;
        strcpy(g->vexs[i].name, t2);
        g->vexs[i].works = t3;
        g->vexs[i].audience = t4;
    }
}

int visited[MAXSIZE + 1];

//深度优先遍历
DFS(MGraph *g, int i)
{
    int j;
    printf("%-3d", g->vexs[i].num);
    visited[i] = 1;
    for (j = 1; j <= g->n; j++)
    {
        if (g->edges[i][j] == 1 && !visited[j])
        {
            DFS(g, j);
        }
    }
}

//邻接矩阵的深度优先遍历
DFS_juzheng(MGraph *g)
{
    printf("深度优先遍历为:\n");
    int i;
    for (i = 1; i <= g->n; i++)
    {
        visited[i] = 0;
    }
    for (i = 1; i <= g->n; i++)
    {
        if (!visited[i])
        {
            DFS(g, i);
        }
    }
    printf("\n");
}

//查找指定编号展厅，输出展厅的基本信息及直接相连的其他展厅的编号
findone(MGraph *g)
{
    int i, t;
    printf("请输入需要查找的展厅的编号:");
    scanf("%d", &t);
    for (i = 1; i <= g->n; i++)
    {
        if (t == g->vexs[i].num)
        {
            printf("展厅编号为%d\n", g->vexs[i].num);
            printf("展厅名称为%s\n", g->vexs[i].name);
            printf("作品数量为%d\n", g->vexs[i].works);
            printf("观众喜爱度为%d\n", g->vexs[i].audience);
            break;
        }
    }
    printf("与其直接相连的展厅序号为:\n");
    for(i=1;i<=g->n;i++)
    {
        if(g->edges[t][i]!=0)
        {
            printf("%-4d",g->vexs[i].num);
        }
    }
}

int main()
{
    MGraph tu;
    MGraph *g = &tu;
    int n, e;
    printf("请输入图的节点数、边的条数:\n");
    scanf("%d %d", &n, &e);
    Creat(g, n, e);
    DFS_juzheng(g);
    findone(g);
    return 0;
}
