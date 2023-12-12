#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

// 定义一个点结构体，包含 x 和 y 坐标
typedef struct point
{
    double x;
    double y;
} point;

// 根据 x 坐标排序的比较函数
int pointx(const void *a1, const void *b1)
{
    point *a = (point *)a1;
    point *b = (point *)b1;
    return a->x - b->x;
}

// 根据 y 坐标排序的比较函数
int pointy(const void *a1, const void *b1)
{
    point *a = (point *)a1;
    point *b = (point *)b1;
    return a->y - b->y;
}

// 计算两个点之间的距离
double distant(point i, point j)
{
    return sqrt(pow(i.x - j.x, 2) + pow(j.y - i.y, 2));
}

// 求解最近点对距离的递归函数
double piar(point *points, int start, int end)
{
    double d = INT_MAX; // 初始化当前最短距离为正无穷
    if (start == end)
    { // 若只有一个点，则返回正无穷
        return d;
    }
    if (start + 1 == end)
    { // 若只有两个点，则直接计算距离并返回
        return distant(points[start], points[end]);
    }
    int mid = (start + end) / 2;            // 计算中间点位置
    double d1 = piar(points, start, mid);   // 递归求解左半部分的最近点对距离
    double d2 = piar(points, mid + 1, end); // 递归求解右半部分的最近点对距离
    d = fmin(d1, d2);                       // 取左右两部分最近点对距离中的较小值作为当前最短距离
    // 将中间部分所有符合条件的点存入 temp 数组中
    point temp[end - start + 1];
    int top = 0;
    for (int i = start; i <= end; ++i)
    {
        if (abs(points[i].x - points[mid].x) < d)
        {
            temp[top++] = points[i];
        }
    }
    // 根据 y 坐标排序
    qsort(temp, top, sizeof(point), pointy);
    // 在 temp 中寻找最近点对
    for (int i = 0; i < top - 1; ++i)
    {
        for (int j = i + 1; j < top && (temp[j].y - temp[i].y) < d; ++j)
        {
            double d3 = distant(temp[i], temp[j]);
            if (d3 < d)
            { // 如果找到更小的距离，则更新当前最短距离
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
    // 分配足够大的内存空间
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
        // 读入每个点的坐标
        for (int i = 0; i < n; ++i)
        {
            fscanf(fp1, "%lf %lf", &points[i].x, &points[i].y);
        }
        // 根据 x 坐标排序
        qsort(points, n, sizeof(point), pointx);
        // 求解最近点对距离并输出结果
        double ans = piar(points, 0, n - 1);
        end = clock();
        double duration = ((double)(end - begin)) / CLK_TCK;
        printf("%7s run time: %lf\t%.21lf\n", num[path1], duration, ans);
    }
    free(points); // 释放分配的内存空间
    return 0;
}