#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// ����һ����ṹ�壬���� x �� y ����
typedef struct point
{
    double x;
    double y;
} point;

// ���� x ��������ıȽϺ���
int pointx(const void *a1, const void *b1)
{
    point *a = (point *)a1;
    point *b = (point *)b1;
    return a->x - b->x;
}

// ���� y ��������ıȽϺ���
int pointy(const void *a1, const void *b1)
{
    point *a = (point *)a1;
    point *b = (point *)b1;
    return a->y - b->y;
}

// ����������֮��ľ���
double distant(point i, point j)
{
    return sqrt(pow(i.x - j.x, 2) + pow(j.y - i.y, 2));
}

// ��������Ծ���ĵݹ麯��
double piar(point *points, int start, int end)
{
    double d = INT_MAX; // ��ʼ����ǰ��̾���Ϊ������
    if (start == end)
    { // ��ֻ��һ���㣬�򷵻�������
        return d;
    }
    if (start + 1 == end)
    { // ��ֻ�������㣬��ֱ�Ӽ�����벢����
        return distant(points[start], points[end]);
    }
    int mid = (start + end) / 2;            // �����м��λ��
    double d1 = piar(points, start, mid);   // �ݹ������벿�ֵ������Ծ���
    double d2 = piar(points, mid + 1, end); // �ݹ�����Ұ벿�ֵ������Ծ���
    d = fmin(d1, d2);                       // ȡ���������������Ծ����еĽ�Сֵ��Ϊ��ǰ��̾���
    // ���м䲿�����з��������ĵ���� temp ������
    point temp[end - start + 1];
    int top = 0;
    for (int i = start; i <= end; ++i)
    {
        if (abs(points[i].x - points[mid].x) < d)
        {
            temp[top++] = points[i];
        }
    }
    // ���� y ��������
    qsort(temp, top, sizeof(point), pointy);
    // �� temp ��Ѱ��������
    for (int i = 0; i < top - 1; ++i)
    {
        for (int j = i + 1; j < top && (temp[j].y - temp[i].y) < d; ++j)
        {
            double d3 = distant(temp[i], temp[j]);
            if (d3 < d)
            { // ����ҵ���С�ľ��룬����µ�ǰ��̾���
                d = d3;
            }
        }
    }
    return d;
}
int main()
{
    int N_file = 21; // total =21
    clock_t begin, end;
    char path[50] = "D:\\vscode\\Algo2\\data\\data_";
    char num[30][10] = {"5", "6", "7", "8", "9", "10", "20", "50", "100", "150", "1000", "2000", "3000", "4000", "5000", "6000", "7000", "8000", "9000", "10000", "100000"};
    // �����㹻����ڴ�ռ�
    point *points = (point *)malloc(100000 * sizeof(point));
    if (points == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }
    for (int path1 = 0; path1 < N_file; path1++)
    {
        begin = clock();
        char path_a[100];
        strcpy(path_a, path);
        strcpy(path_a, strcat(path_a, num[path1]));
        FILE *fp1 = fopen(path_a, "r");
        int n;
        fscanf(fp1, "%d", &n);
        // ����ÿ���������
        for (int i = 0; i < n; ++i)
        {
            fscanf(fp1, "%lf %lf", &points[i].x, &points[i].y);
        }
        // ���� x ��������
        qsort(points, n, sizeof(point), pointx);
        // ��������Ծ��벢������
        double ans = piar(points, 0, n - 1);
        end = clock();
        double duration = ((double)(end - begin)) / CLK_TCK;
        printf("%7s run time: %lf\t%.21lf\n", num[path1], duration, ans);
    }
    free(points); // �ͷŷ�����ڴ�ռ�
    return 0;
}