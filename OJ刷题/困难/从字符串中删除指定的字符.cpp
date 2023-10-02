    #include<stdio.h>
    #include<string.h>
    int main()
    {
        char a[25],b;
        int i,j,l,k;
        scanf("%c\n",&b);
        gets(a);
        l=strlen(a);
        j=0;
        for(i=0;i<l;i++) 
        {   
            if(b==a[i]) 
            {
                for(k=i;k<l;k++)
                {
                a[k]=a[k+1];
                j++;
                }
                i--;
            }
        }
        if(j!=0) for(i=0;i<strlen(a);i++) printf("%c",a[i]);
        else printf("not found");    
        return 0;
    }