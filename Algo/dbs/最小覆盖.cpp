#include <iostream>
#include <string>
using namespace std;
 
struct FunctionDependence//函数依赖 
{
	string X;//决定因素 
	string Y;	
};
 
void Init (FunctionDependence FD[],int n)
{
	//函数依赖关系初始化
	int i;
	string x,y;
	cout<<"请输入F中的函数依赖（决定因素在左，被决定因素在右）"<<endl; 
	//输入函数依赖集合F 
	for (i=0;i<n;i++)
	{		
		cin>>x>>y;
		FD[i].X=x;
		FD[i].Y=y;	
	} 
	cout<<"函数依赖集合"; 
	cout<<"F={" ;
	for (i=0;i<n;i++)
	{
		//显示已知的函数依赖集合F 
		cout<<FD[i].X<<"->"<<FD[i].Y;
		if (i<n-1)cout<<", ";	
	} 
	cout<<"}"<<endl; 
}
 
string CutAndSort(string mm)//将最终得到的闭包去除其中重复的元素，并且进行排序 
{
	int size=mm.length();
	string ss="\0"; 
	int kk=0,ii=0;;
	int a[200]={0};//用来记录各个命题出现的次数
	for(kk=0;kk<size;kk++) 
	{
		a[(int)mm[kk]]++;//强制转换类型，储存各个因素的次数 
	}
 
	for (ii=0;ii<200;ii++)
	{
		if (a[ii]>=1)
		ss+=(char)ii;
	} 
	return ss;
} 
 
 
bool IsIn(string f,string zz)//能够判断F中决定因素f里所有的因素是否在X中，但这样可能导致结果出现重复 
{
	bool flag1=false;
	int len1=f.length();
	int len2=zz.length();
	int k=0,t=0,count1=0;
	for (k=0;k<len1;k++)
	{
		for (t=0;t<len2;t++)
		{
			if (f[k]==zz[t])
			{
				//flag1=true;break;
				count1++;
			}
		}
	}
	if (count1==len1)
	{
		flag1=true;
	}
	else flag1=false;
	return flag1;
}
string X_Fn(FunctionDependence FD[],int n,string &xx)  
{  
    string yy=xx;  
    for (int i=0;i<n;i++)  
    {  
        if (IsIn(FD[i].X,yy)==true)  
        {  
            xx+=FD[i].Y;  
        }         
    }  
    yy=CutAndSort(yy);  
    xx=CutAndSort(xx);    
    if (xx!=yy)  
    {  
        X_Fn(FD,n,xx);//递归   
    }  
    return xx;   
}  
 
string FD_Fun(FunctionDependence FD[],int n,string xx)
{
    //求X关于F的闭包  
    //cout<<X_Fn(FD,n,xx);  
	return X_Fn(FD,n,xx); 
}
 
//从函数依赖集F中删除某个依赖关系 left->right
void  Cut(FunctionDependence FD[],int n,string left,string right,FunctionDependence Dyna[])
{	
	int i=0,j=0,count=0;
	for (i=0;i<n;i++)
	{
		if((FD[i].X==left)&&(FD[i].Y==right))
		{
		}
		else
		{
			Dyna[count].X=FD[i].X;
			Dyna[count].Y=FD[i].Y;
			count++;
		}
	}
	cout<<"\n去掉"<<left<<"->"<<right;
	cout<<"后的函数依赖集F："<<endl;
	cout<<"F={" ; 
	for(j=0;j<count;j++)
	{
		cout<<Dyna[j].X<<"->"<<Dyna[j].Y;
		if (j<count-1)cout<<",";
	}
	cout<<"}"<<endl;	
	
}
 
bool RA(FunctionDependence a,FunctionDependence b)//判断冗余属性
{
	if ((IsIn(a.X,b.X)==true)&&(a.Y==b.Y)) 
	{
		return true;
	}
	else return false;
} 
 
string StringCutChar(char f, string zz) //从中去掉一个属性
{ 
    int len = zz.length();  
    int k = 0;
    string tt;
    for (k = 0;k<len;k++)  
    {  
            if (f == zz[k])  
            {  
            }
			else 
			{
				tt+=zz[k];
			}  
    } 
	return tt;
} 
 
void CutSameFD(FunctionDependence FD[],int n)//除去重复的函数依赖 
{
	FunctionDependence Dyna1[n+20];
	FunctionDependence Dyna2[n+20];
	FunctionDependence Dyna3[n+20];
	FunctionDependence Dyna4[n+20];
	int i=0,j=0,k=0,count=0,count1=0,count2=0;
	for (i=0;i<n;i++)
	{
			for (j=0;j<count;j++)
			{
				if((FD[i].X==FD[j].X)&&(FD[i].Y==FD[j].Y))//有函数依赖重复
				{
					break;//跳过当前的函数依赖 
				} 
			}
			if (j==count)
			{
				Dyna1[count].X=FD[i].X;
				Dyna1[count].Y=FD[i].Y;
				count++; 
			}			
	}
	cout<<"去掉重复后的函数依赖集F="<<"{";
	for (k=0;k<count;k++)
	{
		//去掉重复后的函数依赖集
		cout<< Dyna1[k].X<<"->"<<Dyna1[k].Y;
		if (k<count-1)cout<<",";
	}
	cout<<"}"<<endl;
	
	for (k=0;k<count;k++)
	{
		//从第一个函数依赖X→Y开始将其从F中去掉，
		Cut( Dyna1,count,Dyna1[k].X,Dyna1[k].Y,Dyna2);
		//然后在剩下的函数依赖中求X的闭包X+，看X+是否包含Y
		cout<<Dyna1[k].X<<"关于F的闭包：";
		cout<<FD_Fun(Dyna2,count,Dyna1[k].X);//在剩下的函数依赖中求X的闭包X+
		if(IsIn(Dyna1[k].Y,FD_Fun(Dyna2,count,Dyna1[k].X))==true)//在闭包中 
		{
			cout<<"\n"<<Dyna1[k].X<<"->"<<Dyna1[k].Y<<"冗余"<<endl;
		}
		else 
		{
			cout<<"\n"<<Dyna1[k].X<<"->"<<Dyna1[k].Y<<"不冗余"<<endl;			
			Dyna3[count1].X=Dyna1[k].X;
			Dyna3[count1].Y=Dyna1[k].Y;
			count1++;
		}
	}
	cout<<"\n去冗余函数依赖后的函数依赖集F={";
	for (i=0;i<count1;i++)
	{
			cout<<Dyna3[i].X<<"->"<<Dyna3[i].Y;
			if (i<count1-1)cout<<",";
	} 
	cout<<"}"<<endl;
	//去掉冗余属性
 
	for (i=0;i<count1;i++)
	{
		for (j=0;j<Dyna3[i].X.length();j++)
		{
			//X-Bj
			string temp_x=StringCutChar((Dyna3[i].X)[j],Dyna3[i].X);
 
			if (IsIn(Dyna3[i].Y,FD_Fun(Dyna3,count1,temp_x))==true)//即X->A,X=B1B2..Bm,A属于{X去掉某个其中的属性Bi的闭包} 
			{
				Dyna3[i].X= temp_x;
 
			}
		}
			/*if(RA(Dyna3[i],Dyna3[j])==true)
			{
				break;
			}*/
				Dyna4[count2].X=Dyna3[i].X;
				Dyna4[count2].Y=Dyna3[i].Y;
				count2++;	
			
	}
 
	//求得最小覆盖 
	cout<<endl; 
	cout<<"最小覆盖Fm="<<"{";
	for (k=0;k<count2;k++)
	{
			cout<<Dyna4[k].X<<"->"<<Dyna4[k].Y;
			if (k<count2-1)cout<<",";		
	} 
	cout<<"}"<<endl;
} 
 
void SingleR(FunctionDependence FD[],int n) //使F所有函数依赖的右部分解成单一属性 
{
	int lengthR=0,i=0,j=0,k=0;
	static int D=n;
	int count=0;
	FunctionDependence  DynamicFD[D+20];//建立新的空间来存储所有的函数依赖 
	cout<<"右侧属性单一化后的函数依赖集F为："<<endl;
	cout<<"F={" ;
	for (i=0;i<n;i++)
	{
			lengthR=(FD[i].Y).size();			
			for (j=0;j<lengthR;j++)//将右部分解成单一属性，添加到属性集合的后面 
			{
				DynamicFD[count].X=FD[i].X;
				DynamicFD[count].Y= (FD[i].Y)[j];
				count++;
			}
			
	}
	for (k=0;k<count;k++)
	{
		cout<<DynamicFD[k].X<<"->"<<DynamicFD[k].Y;	
		if (k<count-1)cout<<", ";	
	}
	
	cout<<"}"<<endl; 
	D=count; 
	CutSameFD(DynamicFD,D);
 
 
}
 
void Fmin(FunctionDependence FD[],int n)//求最小覆盖 
{
	Init(FD,n);	
	SingleR(FD,n);	
	
}
 
int main()
{
	int N;
	cout<<"请输入F中函数依赖的组数:"; 
	cin>>N;
	
	FunctionDependence fd[N];
	Fmin(fd,N);
 
	return 0;
} 