#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<malloc.h>

void merge_sort(int x[],int left,int right);
void Merge(int* arr, int left, int middle, int right);

int main() {
	clock_t start , end;/*首先用clock_t定义两个变量来存储开始与结束的值*/
	double cost_time;
	start = clock();/*记录开始的值*/

	FILE *fin,*fout;
	int *x=(int *)malloc(sizeof(int)*1000000);
	
	int n;
	fin=fopen("D:\\vscode\\Algo\\lago1\\data\\data_600000","r");
	fscanf(fin,"%d",&n);
	// /*
	for(int i=0; i<n; i++) {
		fscanf(fin,"%d",&x[i]);
	}
	fclose(fin);
	
	// for(int i=0; i<n; i++) {
	// 	printf("%d\n",x[i]);
	// }
	// printf("\n");
	// */ 
	merge_sort(x,0,n-1);

	/*
	for(int i=0; i<n; i++) {
		printf("%d\n",x[i]);
	}
	*/
	
	end = clock();/*记录结束的值*/
	cost_time =((double)(end - start))/ CLK_TCK;
	printf("运行的时间是%f秒\n", cost_time);
	cost_time =((double)(end - start));
	printf("运行的时间是%f毫秒", cost_time);
}

void merge_sort(int x[],int left,int right){
	if(left<right){
		int i=(left+right)/2;
		merge_sort(x,left,i);
		merge_sort(x,i+1,right);
		Merge(x,left, i, right);
	}
}

void Merge(int arr[], int left, int middle, int right)
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;
	int L[n1], R[n2];
	
	for (i = 0; i < n1; i++) {
		L[i] = arr[left + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = arr[middle + 1 + j];
	}
	
	i = 0;
	j = 0;
	k = left;
	
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		arr[k] = R[j];		
		j++;
		k++;
	}
}