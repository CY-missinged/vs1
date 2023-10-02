#include<stdio.h>

int m,n,step=0,min=99999999;
int a[100][100];    //地图，3是墙障碍物，2是路
int b[100][100];    //是否遍历，0是为未遍历，1是遍历

void dfs(int x,int y,int step);

int main()
{
    printf("%d %d",&m,&n);
    return 0;
}
void dfs(int x,int y,int step)
{
    if(n==x&&m==y)
    {
        if(step<min) min=step;
        return;
    }
    if(a[x][y+1]==2&&b[x][y+1]==0)  //右
    {
        b[x][y+1]=1;
        dfs(x,y+1,step+1);
        b[x][y+1]=0;
    }
    if(a[x+1][y]==2&&b[x+1][y]==0)  //下
    {
        b[x+1][y]=1;
        dfs(x+1,y,step+1);
        b[x+1][y]=0;
    }
    if(a[x][y-1]==2&&b[x][y-1]==0)  //左
    {
        b[x][y-1]=1;
        dfs(x,y-1,step+1);
        b[x][y-1]=0;
    }
    if(a[x][y+1]==2&&b[x][y+1]==0)  //上
    {
        b[x][y+1]=1;
        dfs(x,y+1,step+1);
        b[x][y+1]=0;
    }
}