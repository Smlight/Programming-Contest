#include <iostream> 
#include <cstdio>
#include <cstring>

const int N=1000010;
int sta[N],pos[N],a[N];

int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		int n,i;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for (i=1;a[i]<=a[i+1]&&i<n;i++);
		if (i>=n)
		{
			puts("0");
			continue;
		}
		for (;a[n]<=a[n-1]&&n>i;n--);
		if (n<=i)
		{
			puts("0");
			continue;
		}
		int top=1;
		sta[1]=a[i];
		pos[1]=i;
		long long ans=0;
		for (i++;i<=n;i++)
		{
			if (a[i]<sta[top])
			{
				pos[++top]=i;
				sta[top]=a[i];
			}
			else
			{
				for (top--;sta[top]<=a[i]&&top>0;top--);
				if (top<=0)
				{
					for (int p=pos[1]+1;p<i;p++)
					{
						ans+=a[pos[1]]-a[p];
					}
				}
				pos[++top]=i;
				sta[top]=a[i];
			}
		}
		for (i=2;i<=top;i++)
		{
			for (int p=pos[i-1]+1;p<pos[i];p++)
				ans+=a[pos[i]]-a[p];
		}
		printf("%lld\n",ans);
	}
}
