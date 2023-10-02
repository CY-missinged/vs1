#include <stdio.h>
#include <string.h>

#define MAXSIZE 100

//�ڵ���Ϣ
typedef struct zhangting
{
    int num;
    char name[10];
    int works, audience;
} DataType;

//ͼ����Ϣ
typedef struct tu
{
    DataType vexs[MAXSIZE + 1];          //�ڵ�
    int edges[MAXSIZE + 1][MAXSIZE + 1]; //�ڽӾ���
    int n, e;                            //�ڵ���������
} MGraph;

//��������ͼ�ڽӾ���,n�����㣬e����
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
    printf("������ÿһ���ߵ���㡢�յ��Ӧ�Ľڵ㣺\n");
    for (k = 1; k <= g->e; k++)
    {
        scanf("%d%d", &v1, &v2);
        g->edges[v1][v2] = 1;
        g->edges[v2][v1] = 1;
    }
    printf("������ÿ��չ������Ϣ:\n");
    for (i = 1; i <= g->n; i++)
    {
        printf("������չ�����:\n");
        scanf("%d", &t1);
        printf("������չ������:\n");
        scanf("%s", t2);
        printf("��������Ʒ����:\n");
        scanf("%d", &t3);
        printf("���������ϲ����:\n");
        scanf("%d", &t4);
        g->vexs[i].num = t1;
        strcpy(g->vexs[i].name, t2);
        g->vexs[i].works = t3;
        g->vexs[i].audience = t4;
    }
}

int visited[MAXSIZE + 1];

//������ȱ���
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

//�ڽӾ����������ȱ���
DFS_juzheng(MGraph *g)
{
    printf("������ȱ���Ϊ:\n");
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

//����ָ�����չ�������չ���Ļ�����Ϣ��ֱ������������չ���ı��
findone(MGraph *g)
{
    int i, t;
    printf("��������Ҫ���ҵ�չ���ı��:");
    scanf("%d", &t);
    for (i = 1; i <= g->n; i++)
    {
        if (t == g->vexs[i].num)
        {
            printf("չ�����Ϊ%d\n", g->vexs[i].num);
            printf("չ������Ϊ%s\n", g->vexs[i].name);
            printf("��Ʒ����Ϊ%d\n", g->vexs[i].works);
            printf("����ϲ����Ϊ%d\n", g->vexs[i].audience);
            break;
        }
    }
    printf("����ֱ��������չ�����Ϊ:\n");
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
    printf("������ͼ�Ľڵ������ߵ�����:\n");
    scanf("%d %d", &n, &e);
    Creat(g, n, e);
    DFS_juzheng(g);
    findone(g);
    return 0;
}
