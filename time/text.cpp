#include<stdio.h>
#include<stdlib.h>

int my_gets(char *ptr,int size)
{
    int i;
    for(i=0;i<=size;i++)
    {
        ptr[i]=getchar();
    }
    return i;
}
int main()
{
    char *chunk1,*chunk2;
    chunk1=malloc(16*(sizeof(char*)));
    chunk2=malloc(16*(sizeof(char*)));
    puts("Get Input:");
    my_gets(chunk1,16);
	puts(chunk1);
	puts(chunk2);
    return 0;
}