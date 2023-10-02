#include <stdio.h>
struct aa
{
    char a[15];
    char b[5];
    double c;
    double d;
    int e;
    int yce;
}stu[1005];
int main()
{
    double xx;
    int t,n,i,j,xxx=0,zq=0,zq1=0,zq0=0;
    scanf("%d",&t);
    while(t!=0)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            stu[i].yce=0;
            xxx=0;
            scanf("%s",&stu[i].a);
            for(j=0;j<10;j++)
            {
                xxx=xxx+stu[i].a[j]-48;
            }
            // printf("%d***\n",xxx);
            if(xxx%2==0) stu[i].yce=0;
            else stu[i].yce=1;
            xxx=0;
            scanf("%s",stu[i].b);
            for(j=0;j<4;j++)
            {
                if(stu[i].b[j]!='.') xxx=xxx+stu[i].b[j]-48;
            }
            // printf("%d***\n",xxx);
            if(xxx>=10) stu[i].yce=stu[i].yce+1;
            scanf("%lf %lf %d",&stu[i].c,&stu[i].d,&stu[i].e);
            xx=stu[i].d/stu[i].c;
            xxx=xx;
            // printf("%d***\n",xxx);
            if(xxx>=7) stu[i].yce=stu[i].yce+1;
            // printf("%d  %d***\n",i,stu[i].yce);
            if(stu[i].yce>=2) stu[i].yce=1;
            else stu[i].yce=0;
            // printf("%d  %d***\n",i,stu[i].yce);
        }
        zq=0;
        zq1=0;
        zq0=0;
        for(i=0;i<n;i++)
        {
            if(stu[i].e==1&&stu[i].yce==0) zq++;
            if(stu[i].e==stu[i].yce&&stu[i].e==1&&stu[i].yce==1) zq1++;
            if(stu[i].e==stu[i].yce&&stu[i].e==0&&stu[i].yce==0) zq0++;
        }
        printf("%d %d\n%d %d\n",zq1,zq,n-zq0-zq1-zq,zq0);
        if(((zq1+zq0)*1.0)/(n*1.0)>=0.8) printf("yes\n");
        else printf("no\n");
        t--;
    }
    return 0;
}