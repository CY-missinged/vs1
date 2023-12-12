#define MAXLEN 100
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int adjvex;        //��ĳ�����ڽӵĶ���
    struct node *next; //ָ����һ����ĳ�����ڽӵĶ���
} EdgeNode;            //��������

typedef struct vnode
{
    int vertex;                     //�����򣬴��ĳ��������������Ϣ
    EdgeNode *firstedge;            //ָ����ָ����ĳ�����ڽӵĵ�һ������
} VertexNode;                       //��ͷ���
typedef VertexNode AdjList[MAXLEN]; //��ͷ����,�±��0��ʼ

typedef struct
{
    AdjList adjlist;
    int n, e; //ͼ�ж�����������
} ALGraph;    //�����ڽӱ�

void CreatesAdjList(ALGraph *g, int n, int e)
{
    EdgeNode *ptr;
    int k, v1, v2;
    g->n = n;
    g->e = e;
    for (k = 0; k < g->n; k++) //��ʼ����ͷ�����ָ����Ϊ��
    {
        g->adjlist[k].firstedge = NULL;
        g->adjlist[k].vertex = k; //����Ĭ�϶���ֵ���Ƕ�Ӧ�±�ֵ
    }
    for (k = 1; k <= g->e; k++) //�����ڽӱ�
    {
        scanf("%d%d", &v1, &v2);                    //����һ�Աߵ����ս��
        ptr = (EdgeNode *)malloc(sizeof(EdgeNode)); //��̬����һ����������ռ�
        ptr->adjvex = v2;                           //���ñߵ��յ�д��������
        ptr->next = g->adjlist[v1].firstedge;       //���������ǽ��ý����뵽����ͷ��
        g->adjlist[v1].firstedge = ptr;
        //��Ϊ����ͼ�������¼��䲻ִ��
        ptr = (EdgeNode *)malloc(sizeof(EdgeNode)); //��̬����һ����������ռ�
        ptr->adjvex = v1;                           //���ñߵ��յ�д��������
        ptr->next = g->adjlist[v2].firstedge;       //���������ǽ��ý����뵽����ͷ��
        g->adjlist[v2].firstedge = ptr;
    }
}

int Nodedegree(ALGraph *g, int ch) //ͳ�ƶ���Ϊch�Ķ�
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
    ALGraph g;   //����һ��ͼ����
    EdgeNode *p; //����һ����������ָ�����
    int i, ch;
    scanf("%d%d", &g.n, &g.e);          //ͼ�Ķ������ͱ���
    CreatesAdjList(&g, g.n, g.e);       //���ú��������ڽӱ�
    scanf("%d", &ch);                   //�����ѯ����ֵ
    printf("%d\n", Nodedegree(&g, ch)); //����ö���Ķ�
    return 0;
}
