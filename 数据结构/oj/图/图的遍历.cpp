#include <stdio.h>
#include <stdlib.h>

#define MAX_GRAPH 50 // �������Ŀ

int visited[MAX_GRAPH] = {0};

typedef struct
{
    int V;                               // �����Ŀ
    int E;                               // ����Ŀ
    int adjMatrix[MAX_GRAPH][MAX_GRAPH]; // �����ڽӾ���洢
} Graph;

// ͼ�ĳ�ʼ��
void InitGraph(Graph *g)
{
    int i, j;
    g->V = 0;
    g->E = 0;
    for (i = 0; i < MAX_GRAPH; i++)
        for (j = 0; j < MAX_GRAPH; j++)
            g->adjMatrix[i][j] = 0;
}

// ����ͼ
void CreateGraph(Graph *g)
{
    int n, m, i;
    int v, u;
    scanf("%d", &n); // ����ڵ�ĸ���
    scanf("%d", &m); // ����ߵĸ���
    g->V = n;
    g->E = m;
    for (i = 0; i < g->E; i++)
    { // ѭ������m����
        scanf("%d%d", &v, &u);
        g->adjMatrix[v][u] = 1;
        g->adjMatrix[u][v] = 1;
    }
}

int visit[MAX_GRAPH + 1];

// �벹��DFS�����Ĵ���
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
    DFS(&g, 0); // ��ͼg��0�Ž�㿪ʼ�����������
    return 0;
}
