#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define N 1000000
#define N_file 38

void BubbleSort(int a[], int n);

int main()
{
    clock_t begin, end;
    char path[50] = "D:\\vscode\\Algo\\algo1\\data\\data_";
    char num[50][10] = {"1000", "2000", "3000", "4000", "5000", "6000", "7000", "8000", "9000", "10000", "11000", "12000", "13000", "14000", "15000", "16000", "17000", "18000", "19000", "20000", "21000", "22000", "23000", "24000", "25000", "26000", "27000", "28000", "29000", "30000", "40000", "50000", "60000", "70000", "80000", "90000", "100000", "200000", "300000", "400000", "500000", "600000", "700000", "800000", "900000", "1000000"};
    int path1;
    for (path1 =0; path1 < N_file; path1++)
    {
        char path_a[100];
        strcpy(path_a, path);
        strcpy(path_a, strcat(path_a, num[path1]));
        begin = clock();
        int n, i;
        int *a = (int *)malloc(N * sizeof(int));
        FILE *fp1, *fp2;
        if ((fp1 = fopen(path_a, "r")) == NULL)
        {
            puts("error file path\n");
        }
        else
        {
            fscanf(fp1, "%d", &n);
            for (i = 0; i < n; i++)
            {
                fscanf(fp1, "%d", &a[i]);
            }
            BubbleSort(a, n);
            fp2 = fopen("D:\\vscode\\Algo\\algo1\\output.txt", "w");
            for (i = 0; i < n; i++)
            {
                fprintf(fp2, "%d\n", a[i]);
            }
            end = clock();
            double duration = ((double)(end - begin)) / CLK_TCK;
            printf("%7s run time: %lf\n", num[path1], duration);
        }
        free(a);
    }
    return 0;
}

void BubbleSort(int a[], int n)
{
    int i, j, k;
    for (i = 1; i < n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            if (a[j - 1] > a[j])
            {
                k = a[j];
                a[j] = a[j - 1];
                a[j - 1] = k;
            }
        }
    }
}