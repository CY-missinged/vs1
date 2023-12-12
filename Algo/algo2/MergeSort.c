#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define N 1000000
#define N_file 46

void MergeSort(int *a, int *b, int i, int j);

int main()
{
	FILE *fp4;
	fp4 = fopen("D:\\vscode\\Algo\\algo2\\output_times.txt", "w");
	fclose(fp4);
	clock_t begin, end;
	char path[50] = "D:\\vscode\\Algo\\algo1\\data\\data_";
	char num[50][10] = {"1000", "2000", "3000", "4000", "5000", "6000", "7000", "8000", "9000", "10000", "11000", "12000", "13000", "14000", "15000", "16000", "17000", "18000", "19000", "20000", "21000", "22000", "23000", "24000", "25000", "26000", "27000", "28000", "29000", "30000", "40000", "50000", "60000", "70000", "80000", "90000", "100000", "200000", "300000", "400000", "500000", "600000", "700000", "800000", "900000", "1000000"};
	int path1;
	for (path1 = 0; path1 < N_file; path1++)
	{
		char path_a[100];
		strcpy(path_a, path);
		strcpy(path_a, strcat(path_a, num[path1]));
		begin = clock();
		int n, i;
		int *a = (int *)malloc(sizeof(int) * N);
		int *b = (int *)malloc(sizeof(int) * N);
		FILE *fp1, *fp2, *fp3;
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
			MergeSort(a, b, 0, n - 1);
			fp2 = fopen("D:\\vscode\\Algo\\algo2\\output.txt", "w");
			for (i = 0; i < n; i++)
			{
				fprintf(fp2, "%d\n", b[i]);
			}
			end = clock();
			double duration = ((double)(end - begin)) / CLK_TCK;
			fp3 = fopen("D:\\vscode\\Algo\\algo2\\output_times.txt", "a");
			printf("%7s run time: %lf\n", num[path1], duration);
			fprintf(fp3, "%lf\n", duration);
		}
		fclose(fp1);
		fclose(fp2);
		fclose(fp3);
		free(a);
		free(b);
	}
	return 0;
}

void MergeSort(int *a, int *b, int i, int j)
{
	int left = i, right = j, b_times, x1;
	if (i == j)
		return;
	int mid = (i + j) / 2 + 1;
	int mid1 = mid;
	MergeSort(a, b, i, mid - 1);
	MergeSort(a, b, mid, j);
	for (b_times = i; b_times <= j; b_times++)
	{
		if (a[i] < a[mid1])
		{
			b[b_times] = a[i];
			if (i < mid - 1)
				i++;
			else
			{
				b_times++;
				while (b_times <= j)
					b[b_times++] = a[mid1++];
				break;
			}
		}
		else
		{
			b[b_times] = a[mid1];
			if (mid1 < j)
				mid1++;
			else
			{
				b_times++;
				while (b_times <= j)
					b[b_times++] = a[i++];
				break;
			}
		}
	}
	for (x1 = left; x1 <= right; x1++)
		a[x1] = b[x1];
}