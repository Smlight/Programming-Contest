#include <iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int M=10001;
int f1[M],f2[M];
struct pur
{
	int m,atk;
};
pur p[200];

int main()
{
	int T,m,a,b,c,d,i,j;
	scanf("%d",&T);
	while (T--)
	{
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		scanf("%d%d%d%d%d",&m,&a,&b,&c,&d);
		for (i=1;i<=a;i++)
		{
			scanf("%d%d",&p[i].m,&p[i].atk);
			f1[p[i].m]=max(f1[p[i].m],p[i].atk);
		}
		int mon,atk,id,buff;
		for (i=1;i<=b;i++)
		{
			scanf("%d%d%d%d",&mon,&atk,&id,&buff);
			f1[mon]=max(f1[mon],atk);
			for (j=1;j<=a;j++)
				if (p[j].m+mon<=m)
				{
					if (j==id+1)
						f1[p[j].m+mon]=max(f1[p[j].m+mon],p[j].atk+atk+buff);
					else
						f1[p[j].m+mon]=max(f1[p[j].m+mon],p[j].atk+atk);
				}
		}
		int tmp=0;
		for (i=1;i<=m;i++)
			if (f1[i]>tmp) tmp=f1[i];
			else f1[i]=tmp;
		for (i=1;i<=c;i++)
		{
			scanf("%d%d",&p[i].m,&p[i].atk);
			f2[p[i].m]=max(f2[p[i].m],p[i].atk);
		}
		for (i=1;i<=c;i++)
			for (j=i+1;j<=c;j++)
				f2[p[i].m+p[j].m]=max(f2[p[i].m+p[j].m],p[i].atk+p[j].atk);
		for (i=1;i<=d;i++)
		{
			scanf("%d%d",&mon,&atk);
			f2[mon]=max(f2[mon],atk);
		}
		tmp=0;
		for (i=1;i<=m;i++)
			if (f2[i]>tmp) tmp=f2[i];
			else f2[i]=tmp;
		int ans=0;
		for (i=0;i<=m;i++)
			ans=max(ans,f1[i]+f2[m-i]);
		printf("%d\n",ans);
	}
	return 0;
}
